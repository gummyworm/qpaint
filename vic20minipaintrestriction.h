#ifndef VIC20MINIPAINTRESTRICTION_H
#define VIC20MINIPAINTRESTRICTION_H

#include "restriction.h"

class vic20MINIPAINTRestriction : public Restriction
{
public:
    vic20MINIPAINTRestriction();
    bool isValid(Image &img, int x, int y, Vec4 Color);
};

#endif // VIC20MINIPAINTRESTRICTION_H
