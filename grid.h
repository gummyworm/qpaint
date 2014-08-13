#ifndef GRID_H
#define GRID_H

#include "types.h"

class Grid
{
public:
    Grid(unsigned hMajor=8, unsigned vMajor=8, unsigned hMinor=1, unsigned vMinor=1);

    unsigned hMinorSpacing() {return hMinor;}
    unsigned vMinorSpacing() {return vMinor;}
    unsigned hMajorSpacing() {return hMajor;}
    unsigned vMajorSpacing() {return vMajor;}
    unsigned minorStroke() {return minorWidth;}
    unsigned majorStroke() {return majorWidth;}
    Vec4 &minorColor() {return minorColor_;}
    Vec4 &majorColor() {return majorColor_;}

    void setHMajor(unsigned size) {hMajor = size;}
    void setVMajor(unsigned size) {vMajor = size;}
    void setHMinor(unsigned size) {hMinor = size;}
    void setVMinor(unsigned size) {vMinor = size;}
    void setMajorStroke(unsigned size) {majorWidth = size;}
    void setMinorStroke(unsigned size) {minorWidth = size;}
    void setMinorColor(Vec4 &color) {minorColor_ = color;}
    void setMajorColor(Vec4 &color) {majorColor_ = color;}
protected:
    ///the number of pixels between each horizontal minor
    unsigned hMinor;
    ///the number of pixels between each vertical minor
    unsigned vMinor;
    ///the number of pixels between each horizontal major
    unsigned hMajor;
    ///the number of pixels between each vertical major
    unsigned vMajor;
    ///the number of pixels between each minor horizontal  division
    unsigned minorWidth;
    ///the number of pixels between each minor vertical  division
    unsigned majorWidth;
    ///the color of the major
    Vec4 minorColor_;
    ///the color of the minor
    Vec4 majorColor_;
};

#endif // GRID_H
