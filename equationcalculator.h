#ifndef EQUATIONCALCULATOR_H
#define EQUATIONCALCULATOR_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include "button.h"
#include <QLabel>
#include <string>
#include <cmath>
#include "getdeterminant.h"

class EquationCalculator:public QMainWindow {
    Q_OBJECT
public:
    EquationCalculator(QWidget *parent=0);
    ~EquationCalculator();
    QWidget* getEquationWidget();
private:
    QWidget *equationWindow;
    QGridLayout *equationLayout;
    Button *btnSelectQuadratic, *btnSelectLinear;
    QLabel *headerLinear, *headerQuadratic;
    QLineEdit *equationDisplay;
    Button *equationClear;

    Button *calculateLinear, *calculateQuadratic;

     //=============================forlinearmode===========================================

    QLineEdit* linearModeDisplay[3][4];
    QLabel*    linearModeVariables[3][3];

    //================================for quadratic==================
    QLineEdit* quadraticModeDisplay[3];
    QLabel* quadraticModeVariables[2];

    void CreateEquationCalculatorWidget();
private slots:
    void onCalculateLinearClicked();
    void onCalculateQuadraticClicked();
    void onEquationClearPressed();
};

#endif // EQUATIONCALCULATOR_H
