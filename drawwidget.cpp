#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent)
    : QGLWidget(parent)
    , xScroll_(0)
    , yScroll_(0)
    , zoom_(8)
    , pixelAR_(1.5f)
    , gridActive(true)
{
    grid.setMajorColor(ColorVec4(0,0,0));
    grid.setMinorColor(ColorVec4(0,0,0));
    activeColor_.r() = 255;
    activeColor_.a() = 255;
    setFocusPolicy(Qt::StrongFocus);
}

void DrawWidget::initializeGL()
{
    glClearColor(1.0,1.0,1.0,0.0);
}
void DrawWidget::resizeGL(int w, int h)
{
    //TODO: horizontal scrollbar
    if(image.width()*zoom_ > w) {

    }
    //TODO: vertical scrollbar
    if(image.height()*zoom_ > h) {

    }
    //glViewport(0,h - (GLint)image.height()*zoom_,(GLint)image.width()*zoom_,(GLint)image.height()*zoom_);
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,image.width()*zoom_,image.height()*zoom_,0,-1,100);

    qDebug() << "Window dims: " << this->size();
    resize(image.width()*zoom_, image.height()*zoom_);  //resize the widget
}
void DrawWidget::paintGL()
{
    xStep = pixelAR_ * (float)zoom_;
    yStep = 1.0/pixelAR_ * (float)zoom_;
    visibleW = width() / (xStep);
    visibleH = height() / (yStep);

    //render the image
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_QUADS);
    for(int y = 0; y < image.height()-yScroll_; ++y) {
        for(int x = 0; x < image.width()-xScroll_; ++x) {
            Vec4 c = image.getPixel(x+xScroll_, y+yScroll_)->getVec4();
            glColor3ub(c.r(), c.g(), c.b());
            glVertex2f(x*xStep,y*yStep);
            glVertex2f(x*xStep+xStep,y*yStep);
            glVertex2f(x*xStep+xStep,y*yStep+yStep);
            glVertex2f(x*xStep,y*yStep+yStep);
        }
    }
    glEnd();
    //render the grid?
    if(gridActive) {
        //render the minor grid
        glLineWidth(grid.minorStroke());
        glBegin(GL_LINES);
        glColor3ub(grid.minorColor().r(), grid.minorColor().g(), grid.minorColor().b());
        //draw the horizontal lines
        for(int y = 0; y < image.height()-yScroll_; y += grid.vMinorSpacing()) {
            glVertex2f(0,y*yStep);
            glVertex2f((image.width()-xScroll_) * xStep, y*yStep);
        }
        //draw the vertical lines
        for(int x = 0; x < image.width()-xScroll_; x += grid.hMinorSpacing()) {
            glVertex2f(x*xStep,0);
            glVertex2f(x*xStep, (image.height()-yScroll_) * yStep);
        }
        glEnd();

        //render the major grid
        glLineWidth(grid.majorStroke());
        glBegin(GL_LINES);
        glColor3ub(grid.majorColor().r(), grid.majorColor().g(), grid.majorColor().b());
        //draw the horizontal lines
        for(int y = (grid.vMajorSpacing()-(yScroll_%grid.vMajorSpacing())); y < image.height()-yScroll_; y += grid.vMajorSpacing()) {
            glVertex2f(0,y*yStep);
            glVertex2f((image.width()-xScroll_) * xStep, y*yStep);
        }
        //draw the vertical lines
        for(int x = grid.hMajorSpacing()-(xScroll_%grid.hMajorSpacing()); x < image.width()-xScroll_; x += grid.hMajorSpacing()) {
            glVertex2f(x*xStep,0);
            glVertex2f(x*xStep, (image.height()-yScroll_) * yStep);
        }
        glEnd();
    }
    //render the cursor
    glLineWidth(cursor.size());
    glBegin(GL_LINE_LOOP);
        glColor3ub(cursor.color().r(), cursor.color().g(), cursor.color().b());
        glVertex2f(cursor.x() * xStep, cursor.y() * yStep);
        glVertex2f(cursor.x() * xStep + xStep, cursor.y() * yStep);
        glVertex2f(cursor.x() * xStep + xStep, cursor.y() * yStep + yStep);
        glVertex2f(cursor.x() * xStep, cursor.y() * yStep + yStep);
    glEnd();
}

void DrawWidget::keyPressEvent(QKeyEvent *ev)
{
    switch(ev->key()) {
    case Qt::Key_Space:
        setPixel(cursor.x()+xScroll_, cursor.y()+yScroll_, activeColor_);
        break;
    case Qt::Key_Equal: //plus
        if(zoom_ < maximumZoom()) {
            ++zoom_;
        }
        break;
    case Qt::Key_Minus: //minus
        if(zoom_ > minimumZoom()) {
            --zoom_;
        }
        break;
    case Qt::Key_Left:
        if(cursor.x() > 0) {
            cursor.moveX(-1);
        }
        else if(xScroll_ > 0) {
            --xScroll_;
        }
        break;
    case Qt::Key_Right:
        if(cursor.x() < visibleW) {
            cursor.moveX(1);
        }
        else if(xScroll_ <= image.width()) {
            ++xScroll_;
        }
        break;
    case Qt::Key_Down:
        if(cursor.y() < visibleH) {
            cursor.moveY(1);
        }
        else if(yScroll_  < image.height()) {
            cursor.moveY(1);
            ++yScroll_;
        }
        break;
    case Qt::Key_Up:
        if(cursor.y() > 0) {
            cursor.moveY(-1);
        }
        else if(yScroll_  > 0) {
            --yScroll_;
        }
        break;
    }
    paintGL();
    update();
}

void DrawWidget::mousePressEvent(QMouseEvent *ev)
{
    mouseDown = true;
    float step_x = zoom() * pixelAR();
    float step_y = zoom() * (1.0f / pixelAR());
    int x = (int)(xScroll() + (float)ev->x() / step_x);
    int y = (int)(yScroll() + (float)ev->y() / step_y);
    if(activeTool) {
        activeTool->onMouseDown(this, QPoint(x,y));
    }
}
void DrawWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    mouseDown = false;
    float step_x = zoom() * pixelAR();
    float step_y = zoom() * (1.0f / pixelAR());
    int x = (int)(xScroll() + (float)ev->x() / step_x);
    int y = (int)(yScroll() + (float)ev->y() / step_y);
    if(activeTool) {
        activeTool->onMouseUp(this, QPoint(x,y));
    }
}

void DrawWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(mouseDown && activeTool) {
        float step_x = zoom() * pixelAR();
        float step_y = zoom() * (1.0f / pixelAR());
        int x = (int)(xScroll() + (float)ev->x() / step_x);
        int y = (int)(yScroll() + (float)ev->y() / step_y);
        activeTool->whileMouseDown(this, QPoint(x,y));
    }
}

void DrawWidget::wheelEvent(QWheelEvent *ev)
{
    //TODO:
}

void DrawWidget::setPixel(int x, int y, Vec4 color)
{
    //make sure this is a valid pixel
    if(x > image.width() || y > image.height()) {
        return;
    }
    image.setPixel(x, y, color);
}

void DrawWidget::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0)
{
    //make sure this is a valid pixel
    if(x > image.width() || y > image.height()) {
        return;
    }
    image.setPixel(x, y, r, g, b, a);
}


void DrawWidget::drawLine(QPoint& p1, QPoint& p2, const Vec4& color)
{
    // Bresenham's line algorithm
    float x1 = p1.x();
    float x2 = p2.x();
    float y1 = p1.y();
    float y2 = p2.y();

    const bool steep = (qAbs(y2 - y1) > qAbs(x2 - x1));

    if(steep)
    {
        qSwap(x1, y1);
        qSwap(x2, y2);
    }
    if(x1 > x2)
    {
        qSwap(x1, x2);
        qSwap(y1, y2);
    }
    const float dx = x2 - x1;
    const float dy = qAbs(y2 - y1);

    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;

    const int maxX = (int)x2;

    for(int x=(int)x1; x<maxX; x++)
    {
        if(steep)
        {
            setPixel(y,x, color);
        }
        else
        {
            setPixel(x,y, color);
        }
        error -= dy;
        if(error < 0)
        {
            y += ystep;
            error += dx;
        }
    }
}

bool DrawWidget::saveImage(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    int saveLayer = image.layer();

    QDataStream out(&file);
    out << (qint32)image.numLayers();
    for(int i = 0; i < image.numLayers(); ++i) {
        image.setLayer(i);
        out << (qint32)image.width();
        out << (qint32)image.height();
    }

    for(int i = 0; i < image.numLayers(); ++i) {
        image.setLayer(i);
        for(int x = 0; x < image.width(); ++x) {
            for(int y = 0; y < image.height(); ++y) {
                Vec4 c = image.getPixel(x,y)->getVec4();
                out << (quint8)c.r();
                out << (quint8)c.g();
                out << (quint8)c.b();
                out << (quint8)c.a();
            }
        }
    }

    file.close();
    image.setLayer(saveLayer);
    return true;
}

bool DrawWidget::loadImage(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    image.zap();
    QDataStream in(&file);
    int numLayers;
    in >> numLayers;

    for(int i = 0; i < numLayers; ++i) {
        qint32 w, h;
        in >> w;
        in >> h;
        image.zap();
        image.addLayer(w,h);
    }
    for(int i = 0; i < numLayers; ++i) {
        image.setLayer(i);
        for(int x = 0; x < image.width(); ++x) {
            for(int y = 0; y < image.height(); ++y) {
                quint8 r,g,b,a;
                in >> r >> g >> b >> a;
                image.setPixel(x,y,r,g,b,a);
            }
        }
    }
    file.close();
    return true;
}
