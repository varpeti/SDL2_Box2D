#pragma once
 
#include "../Object.h"
 
class Image : public Object
{
    private:
        SDL_Texture *texture;

    public:
        Image(SDL_Renderer *renderer, char * file);
        Image(SDL_Renderer *renderer, char * file, Rect rec);
        Image(SDL_Renderer *renderer, char * file, Vec2 coord, Vec2 size);
        Image(SDL_Renderer *renderer, char * file, Rect src, Rect des);
        ~Image();

    public:
        virtual void draw();
        virtual void update(float dt);
};