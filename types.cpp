#include "types.h"

Vec4 ColorVec4(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
   Vec4 c;
   c.r() = r;
   c.g() = g;
   c.b() = b;
   c.a() = a;
   return c;
}
