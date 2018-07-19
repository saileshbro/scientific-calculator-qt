#include "formulamode.h"

FormulaMode::FormulaMode(QWidget *parent) : QMainWindow(parent)
{
    formulaMode = new QWidget;
    formulaImage = new QLabel;
    formulaLayout = new QVBoxLayout;
    formulaScrollArea = new QScrollArea;
    CreateFormulaWidget();
}
FormulaMode::~FormulaMode(){}
void FormulaMode::CreateFormulaWidget(){
    formulaImage->setPixmap(QPixmap(":/new/misc/formulaimg.jpeg"));
    formulaImage->setFixedWidth(830);
    formulaScrollArea->setWidget(formulaImage);
    formulaImage->setFixedHeight(11897);
    formulaLayout->addWidget(formulaScrollArea);
    formulaScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    formulaScrollArea->setFixedWidth(825);
    formulaMode->setLayout(formulaLayout);
    setCentralWidget(formulaMode);
}
QWidget* FormulaMode::getFormulaWidget(){
    return formulaMode;
}
