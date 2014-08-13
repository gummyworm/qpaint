#ifndef CONFIGUREIMAGEDIALOG_H
#define CONFIGUREIMAGEDIALOG_H


#include <QPushButton>
#include <QSpinBox>
#include <QDialog>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "image.h"

class ConfigureImageDialog : public QDialog
{
    Q_OBJECT
public:
    ConfigureImageDialog();

    static Image getImage();
public slots:
    void setMachine(int index);
    void confirm();
    void cancel();

protected:
    QComboBox *machineSelectBox;
    QSpinBox *widthBox;
    QSpinBox *heightBox;
    QPushButton *okayButton;
    QPushButton *cancelButton;

    bool keepChanges;
};

#endif // CONFIGUREIMAGEDIALOG_H
