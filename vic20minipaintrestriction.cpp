#include "vic20minipaintrestriction.h"

vic20MINIPAINTRestriction::vic20MINIPAINTRestriction()
{
}

bool vic20MINIPAINTRestriction::isValid(Image &img, int x, int y, Vec4 color)
{
    getBlock(img,x,y,8,16);
    return true;
}
