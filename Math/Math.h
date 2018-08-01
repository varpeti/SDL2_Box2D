#ifndef _MATH_H_
#define _MATH_H_

#define Assert( _exp ) ((void)0)

class Vec2
{
    public:
        float x, y;

        Vec2(void);
        Vec2(float _x, float _y);
        Vec2(const Vec2& src);

        inline Vec2& operator=(const Vec2 &vOther);

        inline float& operator[](int i);
        inline float operator[](int i) const;

        inline Vec2 operator+(const Vec2& v) const;
        inline Vec2 operator-(const Vec2& v) const;
        inline Vec2 operator*(const Vec2& v) const;
        inline Vec2 operator/(const Vec2& v) const;

        inline Vec2 operator+(float fl) const;
        inline Vec2 operator-(float fl) const;
        inline Vec2 operator*(float fl) const;
        inline Vec2 operator/(float fl) const;

        inline bool operator==(const Vec2& v) const;
        inline bool operator!=(const Vec2& v) const;

        inline Vec2& operator+=(const Vec2 &v);
        inline Vec2& operator-=(const Vec2 &v);
        inline Vec2& operator*=(const Vec2 &v);
        inline Vec2& operator/=(const Vec2 &v);

        inline Vec2& operator+=(float fl);
        inline Vec2& operator-=(float fl);
        inline Vec2& operator/=(float fl);
        inline Vec2& operator*=(float fl);
        
        inline Vec2 Normalize() const;
        inline Vec2 Rotate(double angle) const;
        inline float Length() const;
        inline float LengthSqr(void) const;
        inline float CrossProduct(const Vec2& b) const;
        inline float DistTo(const Vec2 &vOther) const;
        inline float DistToSqr(const Vec2 &vOther) const;
        inline float Dot(const Vec2& vOther) const;

        inline bool IsZero() const;
        inline bool IsZero(float tolerance) const;
        
        // Base address...
        inline float* Base();
        inline float const* Base() const;
};


//*///

inline Vec2::Vec2(void)
{
    x = y = 0.0f;
}

//*///

inline Vec2::Vec2(float _x, float _y)
{
    x = _x; y = _y;
}

//*///

inline Vec2::Vec2(const Vec2& src)
{
    x = src.x;
    y = src.y;
}

//*///================================================

inline Vec2& Vec2::operator=(const Vec2 &vOther)
{
    x = vOther.x; y = vOther.y;
    return *this;
}

//*///================================================

inline float& Vec2::operator[](int i)
{
    Assert((i >= 0) && (i < 2));
    return ((float*)this)[i];
}

//*///

inline float Vec2::operator[](int i) const
{
    Assert((i >= 0) && (i < 2));
    return ((float*)this)[i];
}

//*///================================================

inline Vec2 Vec2::operator+(const Vec2& v) const
{
    Vec2 res;
    res.x = x + v.x;
    res.y = y + v.y;
    return res;
}

//*///

inline Vec2 Vec2::operator-(const Vec2& v) const
{
    Vec2 res;
    res.x = x - v.x;
    res.y = y - v.y;
    return res;
}

//*///

inline Vec2 Vec2::operator*(const Vec2& v) const
{
    Vec2 res;
    res.x = x * v.x;
    res.y = y * v.y;
    return res;
}

//*///

inline Vec2 Vec2::operator/(const Vec2& v) const
{
    Vec2 res;
    res.x = x / v.x;
    res.y = y / v.y;
    return res;
}

//*///================================================

inline Vec2 Vec2::operator+(float fl) const
{
    Vec2 res;
    res.x = x + fl;
    res.y = y + fl;
    return res;
}

//*///

inline Vec2 Vec2::operator-(float fl) const
{
    Vec2 res;
    res.x = x - fl;
    res.y = y - fl;
    return res;
}

//*///

inline Vec2 Vec2::operator*(float fl) const
{
    Vec2 res;
    res.x = x * fl;
    res.y = y * fl;
    return res;
}

//*///

inline Vec2 Vec2::operator/(float fl) const
{
    Vec2 res;
    res.x = x / fl;
    res.y = y / fl;
    return res;
}

//*///================================================

inline bool Vec2::operator==(const Vec2& src) const
{
    return (src.x == x) && (src.y == y);
}

//*///

inline bool Vec2::operator!=(const Vec2& src) const
{
    return (src.x != x) || (src.y != y);
}

//*///================================================

inline  Vec2& Vec2::operator+=(const Vec2& v)
{
    x += v.x; y += v.y;
    return *this;
}

//*///

inline  Vec2& Vec2::operator-=(const Vec2& v)
{
    x -= v.x; y -= v.y;
    return *this;
}

//*///

inline  Vec2& Vec2::operator*=(const Vec2& v)
{
    x *= v.x;
    y *= v.y;
    return *this;
}

//*///

inline  Vec2& Vec2::operator/=(const Vec2& v)
{
    Assert(v.x != 0.0f && v.y != 0.0f);
    x /= v.x;
    y /= v.y;
    return *this;
}

//*///================================================

inline Vec2&  Vec2::operator+=(float fl)
{
    x += fl;
    y += fl;
    return *this;
}

//*///

inline Vec2&  Vec2::operator-=(float fl)
{
    x -= fl;
    y -= fl;
    return *this;
}

//*///

inline  Vec2& Vec2::operator*=(float fl)
{
    x *= fl;
    y *= fl;
    return *this;
}

//*///

inline  Vec2& Vec2::operator/=(float fl)
{
    Assert(fl != 0.0f);
    float oofl = 1.0f / fl;
    x *= oofl;
    y *= oofl;
    return *this;
}

//*///================================================

inline Vec2 Vec2::Normalize() const
{
    Vec2 res;
    float length = this->Length();

    if (length != 0)
    {
        res.x = x / length;
        res.y = y / length;
    }
    else
    {
        res.x = res.y = 0.0f;
    }

    return res;
}

//*///

inline Vec2 Vec2::Rotate(double angle) const
{
    Vec2 res;
    res.x = x*cos(angle) - y*sin(angle);
    res.y = x*sin(angle) - y*cos(angle);
}

//*///

inline float Vec2::Length(void) const
{
    return sqrt(x*x + y*y);
}

//*///

inline float Vec2::LengthSqr(void) const
{
    return (x*x + y*y);
}

//*///

inline float Vec2::CrossProduct(const Vec2& b) const
{
    return x*b.y-y*b.x;
}

//*///

float Vec2::DistTo(const Vec2 &vOther) const
{
    Vec2 delta;

    delta.x = x - vOther.x;
    delta.y = y - vOther.y;

    return delta.Length();
}

//*///

float Vec2::DistToSqr(const Vec2 &vOther) const
{
    Vec2 delta;

    delta.x = x - vOther.x;
    delta.y = y - vOther.y;

    return delta.LengthSqr();
}

//*///

inline float Vec2::Dot(const Vec2& vOther) const
{
    const Vec2& a = *this;

    return(a.x*vOther.x + a.y*vOther.y);
}

//*///================================================

inline bool Vec2::IsZero() const
{
    float tolerance = 0.01f;
    return (x > -tolerance && x < tolerance && y > -tolerance && y < tolerance);
}

//*///

inline bool Vec2::IsZero(float tolerance) const
{
    return (x > -tolerance && x < tolerance && y > -tolerance && y < tolerance);
}

//*///================================================

inline float* Vec2::Base()
{
    return (float*)this;
}

//*///

inline float const* Vec2::Base() const
{
    return (float const*)this;
}

//*/// #####################################################################################

class Color
{
    public:
        char rr;
        char gg;
        char bb;
        char aa;

        Color()
        {
            rr = gg = bb = aa = 0;
        }
    
        Color(char r, char g, char b)
        {
            rr = r; gg = g; bb = b; aa = 0;
        }

        Color(char r, char g, char b, char a)
        {
            rr = r; gg = g; bb = b; aa = a;
        }
    
        Color(const Color &color)
        {
            rr = color.rr;
            gg = color.gg;
            bb = color.bb;
            aa = color.aa;
        }

        inline Color& operator=(const Color &color)
        {
            rr = color.rr;
            gg = color.gg;
            bb = color.bb;
            aa = color.aa;
        }
    
};

class Rect
{
    public:
        Vec2 a;
        Vec2 b;

    public:
        Rect()
        {
            a = Vec2();
            b = Vec2();
        }

        Rect(Vec2 _a, Vec2 _b)
        {
            a = _a;
            b = _b;
        }

        Rect(float ax, float ay, float bx, float by)
        {
            a = Vec2(ax,ay);
            b = Vec2(bx,by);
        }

        Rect(const Rect &rec)
        {
            a = rec.a;
            b = rec.b;
        }

        inline Rect& operator=(const Rect &rec)
        {
            a = rec.a;
            b = rec.b;
        }

};

inline void to_SDL_Rect(const Vec2 &coord, const Vec2 &size, SDL_Rect &dR)
{
    dR.x=coord.x;
    dR.y=coord.y;
    dR.w=size.x;
    dR.h=size.y;
}

inline void to_SDL_Rect(const Rect &rec, SDL_Rect &dR)
{
    dR.x=rec.a.x;
    dR.y=rec.a.y;
    dR.w=rec.b.x;
    dR.h=rec.b.y;
}

#endif