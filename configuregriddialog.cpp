#include "configuregriddialog.h"

ConfigureGridDialog::ConfigureGridDialog()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *minorGridLayout = new QHBoxLayout;
    QHBoxLayout *majorGridLayout = new QHBoxLayout;

    QLabel *l1 = new QLabel("W");
    QLabel *l2 = new QLabel("H");
    QLabel *l3 = new QLabel("W");
    QLabel *l4 = new QLabel("H");
    QLabel *l5 = new QLabel("Minor Grid");
    QLabel *l6 = new QLabel("Major Grid");

    widthSpinBox1 = new QSpinBox(this);
    widthSpinBox2 = new QSpinBox(this);
    heightSpinBox1 = new QSpinBox(this);
    heightSpinBox2 = new QSpinBox(this);

    widthSpinBox1->setMinimum(1);
    widthSpinBox2->setMinimum(1);
    heightSpinBox1->setMinimum(1);
    heightSpinBox2->setMinimum(1);

    minorGridLayout->addWidget(l1);
    minorGridLayout->addWidget(widthSpinBox1);
    minorGridLayout->addWidget(l2);
    minorGridLayout->addWidget(heightSpinBox1);

    majorGridLayout->addWidget(l3);
    majorGridLayout->addWidget(widthSpinBox2);
    majorGridLayout->addWidget(l4);
    majorGridLayout->addWidget(heightSpinBox2);

    mainLayout->addWidget(l5);
    mainLayout->addLayout(minorGridLayout);
    mainLayout->addWidget(l6);
    mainLayout->addLayout(majorGridLayout);
    setLayout(mainLayout);
    setWindowTitle("Configure Grid");
}

Grid ConfigureGridDialog::getGrid()
{
    ConfigureGridDialog dlg;
    dlg.exec();
    Grid g(dlg.widthSpinBox2->value(), dlg.heightSpinBox2->value(), dlg.widthSpinBox1->value(), dlg.heightSpinBox1->value());
    return g;
}
