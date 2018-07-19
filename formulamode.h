#ifndef FORMULAMODE_H
#define FORMULAMODE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDebug>

class FormulaMode : public QMainWindow
{
    Q_OBJECT

public:
    FormulaMode(QWidget *parent = 0);
    ~FormulaMode();
    QWidget* getFormulaWidget();
private:
    QWidget *formulaMode;
    QLabel *formulaImage;
    QVBoxLayout *formulaLayout;
    QScrollArea *formulaScrollArea;
    void CreateFormulaWidget();
};

#endif // FORMULAMODE_H
