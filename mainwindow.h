#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include "basiccalculator.h"
#include "matrixcalculator.h"
#include "equationcalculator.h"
#include "programmercalculator.h"
#include "financialcalculator.h"
#include "conversioncalculator.h"
#include "scientificcalculator.h"
#include "manualmode.h"
#include "formulamode.h"
#include "aboutmode.h"
#include "button.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Button *modeButtons[10];

    QGridLayout *modesLayout;
    QWidget *modesWidget;

    QGridLayout *mainLayout;
    QWidget *mainWidget;

    QGridLayout *modeDisplayLayout;
    QWidget *modeDisplayWidget;

    void createSideBar();
    void SpawnMode(QWidget*);

private slots:
    void spawnBasicMode();
    void spawnScientificMode();
    void spawnMatrixMode();
    void spawnEquationMode();
    void spawnFinancialMode();
    void spawnProgrammerMode();
    void spawnConversionMode();
    void spawnFormulaMode();
    void spawnManualMode();
    void spawnAboutMode();
};

#endif // MAINWINDOW_H
