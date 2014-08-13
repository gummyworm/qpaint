#include "layer.h"
using namespace std;

Layer::Layer(int w, int h)
{
    pixels.clear();
    pixels.resize(h);
    for(int i = 0; i < h; ++i) {
        pixels[i].resize(w, Pixel(255,255,255,255));
    }
}

