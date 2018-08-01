#pragma once
 
#include "../def.h"
#include "../Game/Game.h"
 
class Engine 
{
    private:
        SDL_Renderer *renderer;
        Game *game;

    public:
        Engine(SDL_Renderer *_renderer);

    public:
        bool onInit();
        void onEvent(SDL_Event* event);
        void onLoop();
        void onRender();
        void onCleanup();
};
 
