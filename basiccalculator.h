#ifndef BASICCALCULATOR_H
#define BASICCALCULATOR_H
#include "button.h"

#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QKeyEvent>

#include <QGridLayout>
#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QMainWindow>

#include "stringmath.h"

class BasicCalculator:public QMainWindow {
    Q_OBJECT
public:
    BasicCalculator(QWidget *parent = 0);
    ~BasicCalculator();
    QWidget* getCalculatorWidget();
protected:
    bool eventFilter(QObject *obj, QEvent *event);//for mapping keyboard

private:

    QLineEdit *display;

    QGridLayout *basicLayout,
                *displayTextLayout,
                *mainLayout;

    QWidget *basicCalcWidget;
    QWidget *displayWidget;

    QWidget *mainWidget;

    Button *btn[10];

    Button *btnDot ;
    Button *btnEquals;
    Button *btnDiv;
    Button *btnMul;
    Button *btnPlus;
    Button *btnMinus;
    Button *btnbksp;
    Button *btnC;
    Button *btnPercent;
    Button *btnPlusMinus;

    void CreateBasicCalcWidget();
    void CreateDisplayTextWidget();

private slots:
    void numberPressed();
    void decimalPressed();
    void unaryOperatorPressed();
    void clearPressed();
    void binaryOperatorPressed();
    void equalsPressed();
    void bkspPressed();
};

#endif // BASICCALCULATOR_H
