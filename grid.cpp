#include "grid.h"

Grid::Grid(unsigned hMajor, unsigned vMajor, unsigned hMinor, unsigned vMinor)
{
    this->hMajor=hMajor;
    this->vMajor=vMajor;
    this->hMinor = hMinor;
    this->vMinor = vMinor;

    majorWidth = 2;
    minorWidth = 1;
}
