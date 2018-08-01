#ifndef _CAPP_H_
#define _CAPP_H_
 
#include "def.h"
 
class CApp 
{
    private:
        bool Running;
        SDL_Surface *Surf_Display;

    public:
        CApp();
        int OnExecute();
 
    private:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void OnCleanup();
};
 
#endif