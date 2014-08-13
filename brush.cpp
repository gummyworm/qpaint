#include "brush.h"

Brush::Brush()
    :Tool()
{
}
void Brush::onMouseDown(DrawWidget* dw, QPoint& pos)
{
    dw->setPixel(pos.x(), pos.y(), dw->activeColor());
    ///redraw
    dw->paintGL();
    dw->update();
    prevPos = pos;
}
void Brush::onMouseUp(DrawWidget* dw, QPoint& pos)
{

}
void Brush::whileMouseDown(DrawWidget* dw, QPoint& pos)
{
    ///redraw
    dw->drawLine(pos, prevPos, dw->activeColor());
    dw->paintGL();
    dw->update();
    prevPos = pos;
}
