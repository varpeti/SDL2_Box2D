#pragma once
 
#include "../def.h"
#include "../Math/Math.h"

enum 
{
    OBJ_NOSIZE = 0x1,
    OBJ_FULLSIZE = 0x2,
    OBJ_CENTERED = 0x4,
};
 
class Object 
{
    protected:
        SDL_Renderer *renderer;

        SDL_Rect         sR;
        SDL_Rect         dR;
        double           angle;
        SDL_Point        center;
        SDL_RendererFlip flip_;
        Color            color;
        uint32           flags;

    public:
        Vec2 getCoord();
        void setCoord(Vec2);

        Vec2 getSize();
        void setSize(Vec2);

        Color getColor();
        void  setColor(Color);

        void rotate(double _angle);
        void rotate(double _angle,Vec2 _center);
        void flip(SDL_RendererFlip _flip);

    public:
        virtual void draw() = 0;
        virtual void update(float dt) = 0;
};