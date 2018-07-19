#ifndef SCIENTIFICCALCULATOR_H
#define SCIENTIFICCALCULATOR_H

#include <QWidget>
#include <QApplication>
#include <QDebug>
#include <QLineEdit>
#include <QKeyEvent>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <cmath>
#include <fstream>
#include <iostream>
#include "button.h"
#include "stringmath.h"
#include "getfactorial.h"
class ScientificCalculator : public QMainWindow
{
    Q_OBJECT
public:
    ScientificCalculator(QWidget *parent = 0);
    ~ScientificCalculator();
    QWidget* getScientificCalculator();
protected:
    bool eventFilter(QObject *obj, QEvent *event);//for mapping keyboard
private:
    QWidget *ScientificWidget;
    QGridLayout *ScientificLayout;
    Button *btn0;
    Button *btn1;
    Button *btn2;
    Button *btn3;
    Button *btn4;
    Button *btn5;
    Button *btn6;
    Button *btn7;
    Button *btn8;
    Button *btn9;
    Button *btnsin;
    Button *btncos;
    Button *btntan;
    Button *btnsininv;
    Button *btncosinv;
    Button *btntaninv;
    Button *btnsinh;
    Button *btncosh;
    Button *btntanh;
    Button *btnsinhinv;
    Button *btncoshinv;
    Button *btntanhinv;
    Button *btne;
    Button *btnxpown;
    Button *btnxpow2;
    Button *btnxpow3;
    Button *btnpowneg1;
    Button *btnlog;
    Button *btnln;
    Button *btnxfact;
    Button *btnroot;
    Button *btncubicroot;
    Button *btnDot;
    Button *btnEquals;
    Button *btnDiv;
    Button *btnMul;
    Button *btnPlus;
    Button *btnMinus;
    Button *btnbksp;
    Button *btnC;
    Button *btnPercent;
    Button *btnPlusMinus;
    Button *btnpi;
    Button *btnbrkt;
    Button *btndel;
    QLineEdit *display;

    void CreateScientificCalculatorWidget();

public slots:
    void numberPressed();
    void decimalPressed();
    void unaryOperatorPressed();
    void clearPressed();
    void binaryOperatorPressed();
    void equalsPressed();
    void bkspPressed();
    void backPressed();
    void trigonometricPressed();
    void bracketPressed();

};

#endif // SCIENTIFICCALCULATOR_H
