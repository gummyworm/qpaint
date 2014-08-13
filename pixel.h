#ifndef PIXEL_H
#define PIXEL_H

#include "types.h"

class Pixel
{
public:
    Pixel(unsigned r=0, unsigned g=0, unsigned b=0, unsigned a=0) {Set(r,g,b,a);}
    void Set(unsigned r, unsigned g, unsigned b, unsigned a = 0) {color.r() = r; color.g() = g; color.b() = b; color.a() = a;}
    void Set(Vec4 c) {color = c;}
    unsigned r() {return color.r();}
    unsigned g() {return color.g();}
    unsigned b() {return color.b();}
    unsigned a() {return color.a();}
    unsigned getRGBA8() {return (color.r() << 24) | (color.g() << 16) | (color.b() << 8) | color.a();}
    Vec4 getVec4() {return color;}
protected:
    Vec4 color;
};

#endif // PIXEL_H
