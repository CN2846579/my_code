while (true)
{
    Uint32 color = _RGB(255, 255, 255);
    Uint8 r = (color >> 16) & 0xFF;
    Uint8 g = (color >> 8) & 0xFF;
    Uint8 b = color & 0xFF;
    Uint8 a = (color >> 24) ? (color >> 24) & 0xFF : 0xFF;
    int x = 0, y = 0;
    while (x <= 600) {
        SDL_RenderPresent(wnd.GetRenderer());
        SDL_SetRenderDrawColor(wnd.GetRenderer(), r, g, b, a);
        wnd.FillRect(0, 0, 800, 600, _RGB(255, 255, 255));
        SDL_RenderClear(wnd.GetRenderer());
        wnd.FillRect(x++, y, 200, 200, _RGB(255, 0, 0));
        SDL_Delay(sleepTime);
    }
    while (y <= 400)
    {
        SDL_RenderPresent(wnd.GetRenderer());
        SDL_SetRenderDrawColor(wnd.GetRenderer(), r, g, b, a);
        wnd.FillRect(0, 0, 800, 600, _RGB(255, 255, 255));
        SDL_RenderClear(wnd.GetRenderer());
        wnd.FillRect(x, y++, 200, 200, _RGB(255, 0, 0));
        SDL_Delay(sleepTime);
    }
    while (x >= 0)
    {
        SDL_RenderPresent(wnd.GetRenderer());
        SDL_SetRenderDrawColor(wnd.GetRenderer(), r, g, b, a);
        wnd.FillRect(0, 0, 800, 600, _RGB(255, 255, 255));
        SDL_RenderClear(wnd.GetRenderer());
        wnd.FillRect(x--, y, 200, 200, _RGB(255, 0, 0));
        SDL_Delay(sleepTime);
    }
    while (y >= 0)
    {
        SDL_RenderPresent(wnd.GetRenderer());
        SDL_SetRenderDrawColor(wnd.GetRenderer(), r, g, b, a);
        wnd.FillRect(0, 0, 800, 600, _RGB(255, 255, 255));
        SDL_RenderClear(wnd.GetRenderer());
        wnd.FillRect(x, y--, 200, 200, _RGB(255, 0, 0));
        SDL_Delay(sleepTime);
    }
    if (sleepTime) sleepTime--;
}