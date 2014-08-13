#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <Qt>
#include <QGraphicsView>
#include <QtOpenGL/QGLWidget>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QFile>
#include "image.h"
#include "cursor.h"
#include "grid.h"

class DrawWidget;
#include "tool.h"

class DrawWidget : public QGLWidget
{
    Q_OBJECT
public:
    DrawWidget(QWidget *parent = 0);

    void resizeGL(int w, int h);
    void initializeGL();
    void paintGL();

    void setTool(Tool *tool) {activeTool = tool;}

    const float pixelAR() {return pixelAR_;}
    const unsigned zoom() {return zoom_;}
    const unsigned maximumZoom() {return 32;}
    const unsigned minimumZoom() {return 1;}
    const unsigned xScroll() {return xScroll_;}
    const unsigned yScroll() {return yScroll_;}

    const Vec4& activeColor() {return activeColor_;}
    void setActiveColor(Vec4 c) {activeColor_ = c;}

    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void setPixel(int x, int y, Vec4 c);
    void drawLine(QPoint& p1, QPoint& p2, const Vec4& color);

    void showGrid() {gridActive = true;}
    void hideGrid() {gridActive = false;}
    bool gridVisible() {return gridActive;}
    void setGrid(Grid grid) {this->grid = grid;}

    void setImage(Image image) {this->image = image;}
    bool saveImage(QString filename);
    bool loadImage(QString filename);
protected:
    Image image;
    ///the magnification factor of
    unsigned zoom_;
    ///the pixel aspect ratio
    float pixelAR_;
    ///if true, mouse button is down
    bool mouseDown;
    ///last mouse position
    QPoint prevMousePos;

    ///if true, display the grid
    bool gridActive;
    ///the grid
    Grid grid;

    ///the cursor
    Cursor cursor;

    Tool *activeTool;
    Vec4 activeColor_;

    unsigned xScroll_;
    unsigned yScroll_;

    ///the number of pixels to render each pixel as in the x dimension
    float xStep;
    ///the number of pixels to render each pixel as in the y dimension
    float yStep;
    ///the number of visible horizontal pixels
    unsigned visibleW;
    ///the number of visible vertical pixels
    unsigned visibleH;

    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void mouseMoveEvent(QMouseEvent *ev);
    virtual void wheelEvent(QWheelEvent *ev);
};

#endif // DRAWWIDGET_H
