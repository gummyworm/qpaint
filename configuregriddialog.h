#ifndef CONFIGUREGRIDDIALOG_H
#define CONFIGUREGRIDDIALOG_H

#include <QPushButton>
#include <QDialog>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QLabel>
#include "grid.h"

class ConfigureGridDialog : public QDialog
{
    Q_OBJECT
public:
    ConfigureGridDialog();

    static Grid getGrid();
protected:
    QSpinBox *widthSpinBox1;
    QSpinBox *heightSpinBox1;
    QSpinBox *widthSpinBox2;
    QSpinBox *heightSpinBox2;
};

#endif // CONFIGUREGRIDDIALOG_H
