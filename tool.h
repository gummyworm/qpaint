#ifndef TOOL_H
#define TOOL_H


class Tool;
#include "drawwidget.h"

class Tool
{
public:
    Tool();
    virtual void onMouseDown(DrawWidget *dw, QPoint& pos) {}
    virtual void onMouseUp(DrawWidget *dw, QPoint& pos) {}
    virtual void whileMouseDown(DrawWidget *dw, QPoint& pos) {}
protected:
};

#endif // TOOL_H
