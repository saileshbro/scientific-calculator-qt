#ifndef FINANCIALCALCULATOR_H
#define FINANCIALCALCULATOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <cmath>
#include "button.h"

class FinancialCalculator : public QMainWindow
{
    Q_OBJECT
public:
    FinancialCalculator(QWidget *parent = 0);
    QWidget* getFinancialCalculatorWidget();
    ~FinancialCalculator();

private:
    QWidget     *FinancialWindow;

    QGridLayout *FinancialLayout;

    QLineEdit   *Principle,
                *InterestText,
                *AmountText,
                *DepreciationText,
                *Rate,
                *Time,
                *CFrequency;

    QLabel      *RateLabel,
                *TimeLabel,
                *PrincipleLabel,
                *DepreciationLabel,
                *InterestLabel,
                *AmountLabel,
                *CompoundingFreqLabel;

    Button       *Clear,
                 *SimpleInterest,
                 *CompoundInterest,
                 *Depreciation;
    void CreateFinancialCalculatorWidget();
public slots:
    void SimpleInterestPressed();
    void CompoundInterestPressed();
    void DepreciationPressed();
    void clearPressed();
};

#endif // FINANCIALCALCULATOR_H
