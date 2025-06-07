#pragma once
#include<cstdio>
class WndBase
{
public:
	struct RECT {
		int left;
		int top;
		int right;
		int bottom;
	};
	RECT GetWindowRect() const {
		return this->rect;
	}
	SDL_Window* GetWindow() const {
		return this->window;
	}
	SDL_Surface* GetSurface() const {
		return this->surface;
	}
	SDL_Renderer* GetRenderer() const {
		return this->Renderer;
	}
	virtual void SetWndTitle(const char* title);
	virtual void UpateWindow();
	virtual void DestroyWindow();
	virtual void ShowWindow();
protected:
	SDL_Renderer* Renderer = nullptr;
	RECT rect;
	char title[64];
	SDL_Surface* surface = nullptr;
	SDL_Window* window = nullptr;
	int x;
	int y;
	int width;
	int height;
};
inline void WndBase::UpateWindow() {
	if (window) {
		SDL_UpdateWindowSurface(window);
	}
}
inline void WndBase::DestroyWindow(){
		if (window) {
			SDL_DestroyWindow(window);
			window = nullptr;
		}
}
inline void WndBase::ShowWindow()
{
	window = SDL_CreateWindow(
		this->title,
		x, y,
		this->rect.right - this->rect.left, this->rect.bottom - this->rect.top,
		SDL_WINDOW_SHOWN
	);
	surface = SDL_GetWindowSurface(window);
}
void WndBase::SetWndTitle(const char* title) {
	if (title) {
		strncpy_s(this->title, sizeof(this->title), title, _TRUNCATE);
	}
	else {
		this->title[0] = '\0';
	}
}