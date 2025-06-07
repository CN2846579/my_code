#include <deque>
#include <SDL.h>

#define W 800
#define H 600

#undef main
int main()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        SDL_Log("Init failed: %s", SDL_GetError());
        return -1;
    }

    SDL_Window* win = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        W, H, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
    if (NULL == win)
    {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        return -1;
    }


    // ������Ⱦ��������
    SDL_Renderer* rdr = SDL_CreateRenderer(win, -1, 0);
    if (NULL == rdr)
    {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        return -1;
    }
    // ������Ⱦ��ɫ
    SDL_SetRenderDrawColor(rdr, 0, 255, 0, 255);
    // �����Ļ
    SDL_RenderClear(rdr);

    // ��Ⱦ�㡢��
    SDL_SetRenderDrawColor(rdr, 0, 0, 0, 255);
    SDL_RenderDrawPoint(rdr, 200, 200);
    for (int i = 200; i < 300; i += 5)
    {
        SDL_RenderDrawPoint(rdr, i, 200);
    }

    SDL_RenderDrawLine(rdr, 0, 0, 200, 250);

    SDL_Point pt[5] = { {0, 0}, {100, 100}, {100, 300}, {200, 100}, {250, 190} };
    SDL_RenderDrawLines(rdr, pt, 5);


    // ��Ⱦ����
    SDL_RenderPresent(rdr);
    // ��ϰ������һ��19*19��Χ������


    SDL_Event event;
    while (true)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }

    }


    // ������Ⱦ��
    SDL_DestroyRenderer(rdr);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}