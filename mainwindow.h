#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QToolBar>
#include <QMenuBar>
#include <QFileDialog>
#include <QColorDialog>
#include <QScrollArea>
#include "drawwidget.h"
#include "brush.h"
#include "configuregriddialog.h"
#include "configureimagedialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void newImage();
    void open();
    void save();
    void setColor();
    void toggleGrid(bool checked);
    void configureGrid();
private:
    QScrollArea *drawScrollArea;
    QWidget *baseWidget;
    QVBoxLayout *mainLayout;
    DrawWidget *drawWidget;
    QToolBar *toolbar;
    Tool *brushTool;

    QMenuBar *menuBar;

    QMenu *fileMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;

    QMenu *viewMenu;
    QAction *toggleGridAct;

    QMenu *optionsMenu;
    QAction *configureGridAct;

    QAction *setColorAct;

    void createToolbar();
    void createMenubar();
};

#endif // MAINWINDOW_H
