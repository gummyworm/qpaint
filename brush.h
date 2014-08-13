#ifndef BRUSH_H
#define BRUSH_H

#include "tool.h"

class Brush : public Tool
{
public:
    Brush();
    virtual void onMouseDown(DrawWidget *dw, QPoint& pos);
    virtual void onMouseUp(DrawWidget *dw, QPoint& pos);
    virtual void whileMouseDown(DrawWidget *dw, QPoint& pos);
protected:
    QPoint prevPos;

};

#endif // BRUSH_H
