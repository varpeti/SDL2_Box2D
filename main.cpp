#include "CApp/CApp.h"
 
CApp::CApp() 
{
    running = true;
    window = NULL;
    renderer = NULL;
    engine = NULL;
}

int CApp::onExecute() 
{
    if(onInit() == false) 
    {
        return -1;
    }
 
    SDL_Event Event;
 
    while(running) 
    {
        while(SDL_PollEvent(&Event)) 
        {
            onEvent(&Event);
        }
 
        onLoop();
        onRender();
    }
 
    onCleanup();
 
    return 0;
}
 
int main() 
{
    CApp theApp;
    return theApp.onExecute();
}