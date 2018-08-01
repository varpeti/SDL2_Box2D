#ifndef _CAPP_H_
#define _CAPP_H_
 
#include "../def.h"
#include "../Engine/Engine.h"
 
class CApp 
{
    private:
        bool running;
        SDL_Window *window;
        SDL_Renderer *renderer;
        Engine *engine;

    public:
        CApp();
        int onExecute();
 
    private:
        bool onInit();
        void onEvent(SDL_Event* event);
        void onLoop();
        void onRender();
        void onCleanup();
};
 
#endif