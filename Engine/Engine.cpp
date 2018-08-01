#include "Engine.h"

Engine::Engine(SDL_Renderer *_renderer)
{
    renderer = _renderer;
}

bool Engine::onInit() 
{
    game = new Game(renderer);
    return true;
}

//*///

void Engine::onEvent(SDL_Event* event) 
{
   
}

//*///

void Engine::onLoop() 
{
    game->update(0.1); //TODO better dt
    usleep(100);      //TODO remove
}

//*///

void Engine::onRender() 
{
   game->draw();
}

//*///

void Engine::onCleanup() 
{
   delete game;
}