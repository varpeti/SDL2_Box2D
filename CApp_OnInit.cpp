#include "CApp.h"

bool CApp::OnInit() 
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        return false;
    }
 
    if((Surf_Display = SDL_SetVideoMode(XX, YY, BITRES, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) //SDL_FULLSCREEN
    {
        return false;
    }
 
    return true;
}