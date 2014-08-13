#include "image.h"

Image::Image(int width, int height)
    : activeLayer(0)
{
    layers.clear();
    if(width > 0 && height > 0) {
        layers.push_back(Layer(width, height));
    }
}

void Image::zap()
{
    layers.clear();
}

Pixel* Image::getPixel(int x, int y)
{
    //make sure the x and y given are within a valid range
    if(x > width() || y > height()) {
        //error!
        return NULL;
    }
    //get the pixel
    return &layers.at(activeLayer).pixels[y][x];
}

void Image::addLayer(int w, int h)
{
    layers.push_back(Layer(w, h));
}

void Image::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    //make sure the x and y given are within a valid range
    if(x >= width() || y >= height()) {
        qDebug() << "Failed to set pixel";
        return;
    }
    //set the pixel
    layers.at(activeLayer).pixels[y][x].Set(r,g,b,a);
}

void Image::fill(Vec4 color)
{
    for(int y = 0; y < height(); ++y) {
        for(int x = 0; x < width(); ++x) {
            setPixel(x,y,color);
        }
    }
}

void Image::setPixel(int x, int y, Vec4 color)
{
    //make sure the x and y given are within a valid range
    if(x >= width() || y >= height()) {
        qDebug() << "Failed to set pixel";
        return;
    }
    //set the pixel
    layers.at(activeLayer).pixels[y][x].Set(color);
}

void Image::setLayer(unsigned layer)
{
    //make sure layer is within #-of-layers range
    if(layers.size() > layer) {
        activeLayer = layer;
    }
    else {
        qDebug() << "Failed to set pixel";
    }
}
