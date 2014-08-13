#ifndef RESTRICTION_H
#define RESTRICTION_H

#include "image.h"
#include <vector>

class Restriction
{
public:
    Restriction();
    virtual bool isValid(Image &img, int x, int y, Vec4 color) = 0;
protected:
    std::vector<std::vector<Pixel*>> getBlock(Image &img, int x,int y, int blockW, int blockH);
    bool isUnique(std::vector<std::vector<Pixel*>> &pixels, Vec4 color);
};

#endif // RESTRICTION_H
