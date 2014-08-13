#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

struct Vec4 {
    uint8_t& r() {return contents_[0];}
    uint8_t& g() {return contents_[1];}
    uint8_t& b() {return contents_[2];}
    uint8_t& a() {return contents_[2];}

    uint8_t& x() {return contents_[0];}
    uint8_t& y() {return contents_[1];}
    uint8_t& z() {return contents_[2];}
    uint8_t& w() {return contents_[3];}

    uint8_t operator [] (unsigned i) const { return contents_[i];}
    uint8_t& operator [] (unsigned i) {return contents_[i];}
private:
    uint8_t contents_[4];
};

Vec4 ColorVec4(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);

#endif // TYPES_H
