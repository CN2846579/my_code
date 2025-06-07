#pragma once
#include <string.h>
#include <SDL.h>
#include"gdi.h"
#include"WndBase.h"
#include <basetsd.h>
#include<thread>
#define SURFACE_MODE 0
#define RENDER_MODE 1
class SDL_WND:public WndBase
{
public:
	bool PAINT_MODE;
	~SDL_WND(){
		SDL_DestroyRenderer(Renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	};
	SDL_WND(const char* title,
		    int x = 0, 
		    int y = 0, 
		    int width = 0,
		    int height = 0,
		    bool PaintMode=SURFACE_MODE,
		    UINT32 BkColor = _RGB(255, 255, 255)
	);
    static void event_loop();
	void ShowWindow();
	void SetWindowRect(int x, int y, int width, int height);
	void SetBkColor(UINT32 color) {
		if(PAINT_MODE==SURFACE_MODE){
		this->BkColor = color;
		FillRect(0, 0, rect.right - rect.left, rect.bottom - rect.top, BkColor);
		}
		else {
			SDL_SetRenderDrawColor(Renderer, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF, 255);
			SDL_RenderClear(Renderer);
			SDL_RenderPresent(Renderer); 
		}
	}
	void FillRect(int x, int y, int width, int height, Uint32 color);
	void FillRect(const SDL_Rect& rect,Uint32 color){
		if (surface != nullptr && PAINT_MODE == SURFACE_MODE) {
			SDL_FillRect(surface, &rect, color);
			SDL_UpdateWindowSurface(window);
		}
		if (Renderer != nullptr && PAINT_MODE == RENDER_MODE) {
			Uint8 r = (color >> 16) & 0xFF;
			Uint8 g = (color >> 8) & 0xFF;
			Uint8 b = color & 0xFF;
			Uint8 a = (color >> 24) ? (color >> 24) & 0xFF : 0xFF;
			SDL_SetRenderDrawColor(Renderer, r, g, b, a);
			SDL_RenderFillRect(Renderer, &rect);
			SDL_RenderPresent(Renderer); // 建议在主循环最后统一调用
		}
		
	}
private:
	UINT32 BkColor = 0;
};
inline SDL_WND::SDL_WND(const char* title,
	int x,
	int y,
	int width,
	int height,
	bool PaintMode,
	UINT32 BkColor
) {
	if (title)SetWndTitle(title);
	if (width <= 0 || height <= 0) {
		width = 640; // Default width
		height = 480; // Default height
	}
	SetWindowRect(x, y, width, height);
	this->BkColor = BkColor;
	this->PAINT_MODE = PaintMode;
}
