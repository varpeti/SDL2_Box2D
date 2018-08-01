#include "Object.h"

Vec2 Object::getCoord()
{
    return Vec2(dR.x,dR.y);
}

void Object::setCoord(Vec2 _coord)
{
    dR.x=_coord.x;
    dR.y=_coord.y;
}

//*///

Vec2 Object::getSize()
{
    return Vec2(dR.w,dR.h);
}

void Object::setSize(Vec2 _size)
{
    sR.w = dR.w = _size.x;
    sR.h = dR.h = _size.y;
}

//*///

Color Object::getColor()
{
    return color;
}

void Object::setColor(Color _color)
{
    color=_color;
}

//*///

void Object::rotate(double _angle,Vec2 _center)
{
    angle = _angle;
    center.x = _center.x;
    center.y = _center.y;

    if ((OBJ_CENTERED & flags) != OBJ_CENTERED) 
    {
        flags ^= OBJ_CENTERED;
    }
}

void Object::rotate(double _angle)
{
    angle = _angle;

    if ((OBJ_CENTERED & flags) == OBJ_CENTERED) 
    {
        flags ^= OBJ_CENTERED;
    }
}

void Object::flip(SDL_RendererFlip _flip)
{
    flip_ = _flip;
}
