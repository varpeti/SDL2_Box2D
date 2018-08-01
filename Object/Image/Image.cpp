#include "Image.h"

Image::Image(SDL_Renderer *_renderer, char *file)
{
    renderer =_renderer;

    SDL_Surface *surface = NULL;
    texture = NULL;

    if ((surface = SDL_LoadBMP(file))==NULL)
    {
        printerror2("Cannot open LoadBMP: ",file);
        throw;
    }

    if ((texture = SDL_CreateTextureFromSurface(renderer, surface))==NULL)
    {
        printerror2("Cannot CreateTextureFromSurface: ",file);
        print(SDL_GetError());
        print(renderer);
        throw;
    }
    SDL_FreeSurface(surface);

    flags = OBJ_NOSIZE;
}

Image::Image(SDL_Renderer *_renderer, char *file, Rect rec)
{
    renderer =_renderer;

    SDL_Surface *surface = NULL;
    texture = NULL;

    if ((surface = SDL_LoadBMP(file))==NULL)
    {
        printerror2("Cannot open LoadBMP: ",file);
        throw;
    }

    if ((texture = SDL_CreateTextureFromSurface(renderer, surface))==NULL)
    {
        printerror2("Cannot CreateTextureFromSurface: ",file);
        print(SDL_GetError());
        print(renderer);
        throw;
    }
    SDL_FreeSurface(surface);

    flags = OBJ_FULLSIZE;
    to_SDL_Rect(rec,dR);
    angle=0;
}

Image::Image(SDL_Renderer *_renderer, char *file, Vec2 coord, Vec2 size)
{
    renderer =_renderer;

    SDL_Surface *surface = NULL;
    texture = NULL;

    if ((surface = SDL_LoadBMP(file))==NULL)
    {
        printerror2("Cannot open LoadBMP: ",file);
        throw;
    }

    if ((texture = SDL_CreateTextureFromSurface(renderer, surface))==NULL)
    {
        printerror2("Cannot CreateTextureFromSurface: ",file);
        print(SDL_GetError());
        print(renderer);
        throw;
    }
    SDL_FreeSurface(surface);

    flags = OBJ_FULLSIZE;
    to_SDL_Rect(coord,size,dR);
    angle=0;
}

Image::Image(SDL_Renderer *_renderer, char *file, Rect src, Rect des)
{
    renderer =_renderer;

    SDL_Surface *surface = NULL;
    texture = NULL;

    if ((surface = SDL_LoadBMP(file))==NULL)
    {
        printerror2("Cannot open LoadBMP: ",file);
        throw;
    }

    if ((texture = SDL_CreateTextureFromSurface(renderer, surface))==NULL)
    {
        printerror2("Cannot CreateTextureFromSurface: ",file);
        print(SDL_GetError());
        print(renderer);
        throw;
    }
    SDL_FreeSurface(surface);

    flags = 0;
    to_SDL_Rect(src,sR);
    to_SDL_Rect(des,dR);
}

Image::~Image()
{
    SDL_DestroyTexture(texture);
}

void Image::draw()
{
    if ( (OBJ_NOSIZE & flags) == OBJ_NOSIZE)
    {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
    }
    else if ( (OBJ_FULLSIZE & flags) == OBJ_FULLSIZE)
    {
        if ( (OBJ_CENTERED & flags) == OBJ_CENTERED) 
             SDL_RenderCopyEx(renderer, texture, NULL, &dR, angle, &center, flip_);
        else SDL_RenderCopyEx(renderer, texture, NULL, &dR, angle, NULL,    flip_);
    }
    else
    {
        if ( (OBJ_CENTERED & flags) == OBJ_CENTERED) 
             SDL_RenderCopyEx(renderer, texture, &sR, &dR, angle, &center, flip_);
        else SDL_RenderCopyEx(renderer, texture, &sR, &dR, angle, NULL,    flip_);
    }

}

void Image::update(float dt)
{

}