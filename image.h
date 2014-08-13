#ifndef IMAGE_H
#define IMAGE_H

#include <QDebug>
#include <stdint.h>
#include <vector>
#include "layer.h"

class Image
{

public:
    Image(int width = 320, int height = 240);
    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);
    void setPixel(int x, int y, Vec4 color);
    void fill(Vec4 color);
    Pixel *getPixel(int x, int y);

    void addLayer(int w=320, int h = 200);
    void setLayer(unsigned layer);
    int layer() {return activeLayer;}
    int numLayers() {return layers.size();}
    void zap();

    size_t width() {return layers[activeLayer].width();}
    size_t height() {return layers[activeLayer].height();}
protected:
    vector<Layer> layers;
    unsigned activeLayer;
};

#endif // IMAGE_H
