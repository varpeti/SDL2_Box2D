#include "CApp.h"

//*///

bool CApp::onInit() 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        printerror("SDL_Init");
        return false;
    }
 
    if ((window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, XX, YY, SDL_WINDOW_FLAGS)) == NULL)
    {
        printerror("SDL_CreateWindow");
        return false;
    }

    if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
    {
        printerror("SDL_CreateRenderer");
        return false;
    }

    engine = new Engine(renderer);
    
    if (!engine->onInit()) return false;

    return true;
}

//*///

void CApp::onEvent(SDL_Event* event) 
{
    if(event->type == SDL_QUIT) 
    {
        running = false;
    }

    engine->onEvent(event);
}

//*///

void CApp::onLoop() 
{
    engine->onLoop();
}

//*///

void CApp::onRender() 
{
    SDL_RenderClear(renderer);

    engine->onRender();
   
    SDL_RenderPresent(renderer);
}

//*///

void CApp::onCleanup() 
{
    engine->onCleanup();
    delete engine;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}