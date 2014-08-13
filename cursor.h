#ifndef CURSOR_H
#define CURSOR_H

#include "types.h"

class Cursor
{
public:
    Cursor() {Vec4 c; c.r()=0;c.g()=0;c.b()=0;c.a()=255; x_=0; y_=0; size_ = 3;}
    Cursor(Vec4 &color, unsigned x=0, unsigned y=0) {color_ = color; x_ = x; y_ = y; size_ = 3;}
    void setX(unsigned x) {x_ = x;}
    void setY(unsigned y) {y_ = y;}
    void moveX(int dx) {x_ += dx;}
    void moveY(int dy) {y_ += dy;}
    void setColor(Vec4 &color) {color_ = color;}
    void setSize(unsigned size) {size_ = size;}

    unsigned x() {return x_;}
    unsigned y() {return y_;}
    unsigned size() {return size_;}
    Vec4 &color() {return color_;}
protected:
    unsigned x_;
    unsigned y_;
    unsigned size_;
    Vec4 color_;
};

#endif // CURSOR_H
