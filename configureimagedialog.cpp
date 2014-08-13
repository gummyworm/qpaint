#include "configureimagedialog.h"

ConfigureImageDialog::ConfigureImageDialog()
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *dimensionsLayout = new QHBoxLayout();
    QHBoxLayout *buttonsLayout = new QHBoxLayout();

    widthBox = new QSpinBox(this);
    heightBox = new QSpinBox(this);
    widthBox->setRange(1,1024);
    heightBox->setRange(1,1024);
    machineSelectBox = new QComboBox(this);
    machineSelectBox->addItem("C64");
    machineSelectBox->addItem("Vic20");
    machineSelectBox->addItem("Custom");

    dimensionsLayout->addWidget(new QLabel("width"));
    dimensionsLayout->addWidget(widthBox);
    dimensionsLayout->addWidget(new QLabel("height"));
    dimensionsLayout->addWidget(heightBox);

    okayButton = new QPushButton("Okay");
    cancelButton = new QPushButton("Cancel");
    buttonsLayout->addWidget(okayButton);
    buttonsLayout->addWidget(cancelButton);
    connect(okayButton, SIGNAL(clicked()), this, SLOT(confirm()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    mainLayout->addWidget(machineSelectBox);
    mainLayout->addLayout(dimensionsLayout);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    keepChanges = false;

    connect(machineSelectBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setMachine(int)));
    setMachine(0);
}

Image ConfigureImageDialog::getImage()
{
    ConfigureImageDialog dlg;
    dlg.exec();
    if(dlg.keepChanges) {
        Image img(dlg.widthBox->value(), dlg.heightBox->value());
        return img;
    }
    else {
        return Image(1,1);
    }
}

void ConfigureImageDialog::setMachine(int index)
{
    switch(index) {
    case 0:
        widthBox->setValue(320);
        heightBox->setValue(200);
        break;
    case 1:
        widthBox->setValue(160);
        heightBox->setValue(192);
        break;
    }
}

void ConfigureImageDialog::confirm()
{
    keepChanges = true;
    close();
}

void ConfigureImageDialog::cancel()
{
    close();
}
