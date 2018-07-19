#ifndef FORMULADISPLAY_H
#define FORMULADISPLAY_H
#include "button.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class FormulaDisplay:public QMainWindow{
public:
    FormulaDisplay(QWidget *parent = 0);
    ~FormulaDisplay();
    QWidget* getFormulaDisplay();
};

#endif // FORMULADISPLAY_H
