#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    drawScrollArea = new QScrollArea(this);
    drawWidget = new DrawWidget();
    drawWidget->setMinimumSize(640,480);
    drawScrollArea->setWidget(drawWidget);

    createMenubar();
    //do this last
    createToolbar();

    brushTool = new Brush();
    drawWidget->setTool(brushTool);

    //create the layout and base widget
    mainLayout = new QVBoxLayout();
    baseWidget = new QWidget();
    mainLayout->addWidget(drawScrollArea);
    mainLayout->addWidget(toolbar);
    baseWidget->setLayout(mainLayout);

    setCentralWidget(baseWidget);
    setMenuBar(menuBar);

    resize(800,600);
}

MainWindow::~MainWindow()
{
    delete drawWidget;
    delete menuBar;
}

void MainWindow::createToolbar()
{
    setColorAct = new QAction("color",this);
    toolbar = new QToolBar("tools");
    toolbar->addAction("paint");
    toolbar->addAction(setColorAct);

    connect(setColorAct, SIGNAL(triggered()), this, SLOT(setColor()));
}

void MainWindow::createMenubar()
{
    menuBar = new QMenuBar();

    newAct = new QAction("&New", this);
    openAct = new QAction("&Open",this);
    saveAct = new QAction("&Save",this);
    fileMenu = new QMenu("&File");
    fileMenu->addAction(newAct);
    fileMenu->addSeparator();
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction("&Quit");
    connect(newAct, SIGNAL(triggered()), this, SLOT(newImage()));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    toggleGridAct = new QAction("Grid", this);
    toggleGridAct->setCheckable(true);
    toggleGridAct->setChecked(true);
    viewMenu = new QMenu("&View");
    viewMenu->addAction(toggleGridAct);
    connect(toggleGridAct, SIGNAL(triggered(bool)), this, SLOT(toggleGrid(bool)));

    configureGridAct = new QAction("Configure Grid", this);
    optionsMenu = new QMenu("&Options");
    optionsMenu->addAction(configureGridAct);
    connect(configureGridAct, SIGNAL(triggered()), this, SLOT(configureGrid()));

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(viewMenu);
    menuBar->addMenu(optionsMenu);
}


void MainWindow::save()
{
    QString filename = QFileDialog::getSaveFileName(this, "Open Image File", NULL, "Image file (*.stn)");
    drawWidget->saveImage(filename);
}

void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open Image File", NULL, "Image file (*.stn)");
    drawWidget->loadImage(filename);
}

void MainWindow::setColor()
{
    QColor c = QColorDialog::getColor();
    QRgb rgb = c.rgb();
    Vec4 v;
    v[0] = c.red();
    v[1] = c.green();
    v[2] = c.blue();
    qDebug() << c.red() << c.green() << c.blue() << c.alpha();
    qDebug() << v.r() << v.g() << v.b() << v.a();
    drawWidget->setActiveColor(v);
}

void MainWindow::toggleGrid(bool checked)
{
    if(toggleGridAct->isChecked()) {
        drawWidget->showGrid();
    }
    else {
        drawWidget->hideGrid();
    }
}

void MainWindow::configureGrid()
{
    drawWidget->setGrid(ConfigureGridDialog::getGrid());
}

void MainWindow::newImage()
{
    Image i = ConfigureImageDialog::getImage();
    if(i.width() != 1) {
        drawWidget->setImage(i);
    }
}
