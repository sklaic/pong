#include "display.h"

Display::Display(int width, int height)
{
    winWidth=width;
    winHeigth=height;
    initError=false;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0){ initError=true;
        std::cout << "Failed at SDL_Init(): "<< SDL_GetError() << std::endl; }
    window = SDL_CreateWindow("PONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeigth, 0);
	if (!window){ initError=true;
        std::cout << "Failed at SDL_CreateWindow(): "<< SDL_GetError() << std::endl; }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer){ initError=true;
        std::cout << "Failed at SDL_CreateRenderer(): "<< SDL_GetError() << std::endl; }
    if (TTF_Init() != 0){ initError=true;
        std::cout << "Failed at TTF_Init(): "<< SDL_GetError() << std::endl; }
    SDL_ShowCursor(0);
    font = TTF_OpenFont("res/FreeMono.ttf", winHeigth/20);
    if (!font){ initError=true;
        std::cout << "Failed at TTF_OpenFont(): "<< SDL_GetError() << std::endl; }
}

Display::~Display()
{
    TTF_CloseFont(font);
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Display::isInitError() { return initError; }

void Display::clearBuffer(Color c)
{
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderClear(renderer);//clear buffer for next frame
}

void Display::drawRect(SDL_Rect *rect, Color c)
{
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(renderer, rect);
}

void Display::drawText(std::string txt, int x, int y, Color c)
{
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_Surface* surface = TTF_RenderText_Solid(font, txt.c_str(), c);
    SDL_Rect rect;
    //limit text position range
    rect.x=x-surface->w/2; if(rect.x<0) rect.x=0;
    rect.y=y; if(y+surface->h>winHeigth) rect.y=winHeigth-surface->h;
    rect.w=surface->w; rect.h=surface->h;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); 
	SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}

void Display::commit() { SDL_RenderPresent(renderer); }//update buffer to window
//end display.cpp