#pragma once
 
#include "../def.h"
#include "../Object/Image/Image.h"
 
class Game 
{
    private:
        SDL_Renderer *renderer;

        Image *hello_image1;
        Image *hello_image2;
        Image *hello_image3;
        Image *hello_image4;

        double a;

    public:
        Game(SDL_Renderer *_renderer);
        ~Game();

    public:
        void update(float dt);
        void draw();
};