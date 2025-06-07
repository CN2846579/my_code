#include"WndSDL.h"
#include "WndVoice.h"
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>
#include <windows.h> // 添加此头文件以定义 Sleep 函数
#undef main 
inline void SDL_WND::event_loop()
{
    SDL_Event event;
    while (1)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                return;
            default:
                break;
            }
        }
    }
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Init(SDL_INIT_EVERYTHING);
	SDL_WND wnd("SDL窗口", 100, 100, 800, 600,0);
	wnd.ShowWindow();
    SDL_VOICE dm("C:\\Desktop\\Lindsey Stirling - Roundtable Rival.mp3");
	dm.Play(0);
	//dm.Pause(); // 暂停音乐
    wnd.event_loop(); // 播放音乐
    return 0;
   
 }
/*
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    return main();
}*/