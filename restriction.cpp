#include "restriction.h"

Restriction::Restriction()
{
}

std::vector<std::vector<Pixel*>> getBlock(Image &img, int x,int y, int blockW, int blockH)
{
    int yStart = y - (y % blockH);
    int xStart = x - (x % blockW);
    std::vector<std::vector<Pixel*>> ret;
    for(int y = yStart; y  < (yStart + blockH); ++y) {
        ret.push_back(std::vector<Pixel*>());
        for(int x = xStart; x < (xStart + blockW); ++x) {
            ret[y].push_back(img.getPixel(x,y));
        }
    }
    return ret;
}

bool isUnique(std::vector<std::vector<Pixel*>> &pixels, Vec4 color)
{
    return true;
}
