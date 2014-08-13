#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "pixel.h"

using namespace std;

class Layer
{
public:
    Layer(int w=320, int h=200);
    size_t width() {return pixels[0].size();}
    size_t height() {return pixels.size();}
    vector< vector< Pixel>> pixels;
};

#endif // LAYER_H
