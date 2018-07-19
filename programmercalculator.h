#ifndef PROGRAMMERCALCULATOR_H
#define PROGRAMMERCALCULATOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include "button.h"
#include <QLabel>
#include <cmath>
#include <reversestring.h>

#include "numberconversion.h"
class ProgrammerCalculator : public QMainWindow
{
    Q_OBJECT
public:
    ProgrammerCalculator(QWidget *parent = 0);
    ~ProgrammerCalculator();
    QWidget* getProgrammerCalculatorWidget();
private:
    QWidget         *programmerModeWindow;
    QGridLayout     *programmerModeLayout;
    Button          *btnClear;


    Button     *btnGenerateFibonacci;
    Button     *btnGeneratePrime;

    QTextEdit       *GeneratorDisplay;
    QLineEdit       *GeneratorMaxDisplay;


    Button  *btnCheckPrefect;
    Button  *btnCheckAms;

//-----------------------------------------
    QLineEdit   *Display;
    Button      *btnCheckPalindrome;

    //=================FOR CONVERSIONS===========================
    QLabel      *programmerConversionHeader[4];
    QLineEdit   *programmerConversionDisplay[4];
    void CreateProgrammerCalculatorWidget();



public slots:
    void onGeneratePressed();
    void onClearPressed();
    void onCheckPalindromePressed();
    void onCheckPerfectPressed();
    void onCheckArmsPressed();
    void convertFromDecimal();
    void convertFromBinary();
    void convertFromHexa();
    void convertFromOctal();
};

#endif // PROGRAMMERCALCULATOR_H
