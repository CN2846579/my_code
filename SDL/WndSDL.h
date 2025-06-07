#include "WndSDL_.h"
inline void SDL_WND::ShowWindow()
{
	window = SDL_CreateWindow(
		this->title,
		x, y,
		this->rect.right - this->rect.left, this->rect.bottom - this->rect.top,
		SDL_WINDOW_SHOWN
	);
	if (!window) {
		printf("Window create failed: %s\n", SDL_GetError());
	}
	else printf("Window created successfully\n");
	if (PAINT_MODE == SURFACE_MODE) {
		surface = SDL_GetWindowSurface(window);
		if (surface)printf("Surface created successfully\n");
	}
	else {
		Renderer = SDL_CreateRenderer(window, -1, 0);
		if (!Renderer) {
			printf("Renderer create failed: %s\n", SDL_GetError());
		}
		else printf("Renderer created successfully\n");
	}
	SetBkColor(this->BkColor);
}

inline void SDL_WND::SetWindowRect(int x, int y, int width, int height) {
	this->rect.left = x;
	this->rect.top = y;
	this->rect.right = x + width;
	this->rect.bottom = y + height;
	this->x = x;
	this->y = y;
}

inline void SDL_WND::FillRect(int x, int y, int width, int height, Uint32 color) {
	if (surface!=nullptr&&PAINT_MODE==SURFACE_MODE) {
		SDL_Rect rect = { x, y, width, height };
		SDL_FillRect(surface, &rect, color);
		SDL_UpdateWindowSurface(window);
	}else
	if (Renderer!=nullptr && PAINT_MODE == RENDER_MODE) {
		SDL_SetRenderDrawColor(Renderer, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF, 255);
		SDL_Rect rect = { x, y, width, height };
		SDL_RenderFillRect(Renderer, &rect);
		//SDL_RenderPresent(Renderer);
	}
}
