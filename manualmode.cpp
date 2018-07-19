#include "manualmode.h"

ManualMode::ManualMode(QWidget *parent) : QMainWindow(parent)
{
    manualMode = new QWidget;
    manualimage = new QLabel;
    manualLayout = new QVBoxLayout;
    manualScrolArea = new QScrollArea;
    CreateManualWidget();
}
ManualMode::~ManualMode(){}
void ManualMode::CreateManualWidget(){
    manualimage->setPixmap(QPixmap(":/new/misc/img.jpeg"));
    manualimage->setFixedWidth(830);
    manualScrolArea->setWidget(manualimage);
    manualimage->setFixedHeight(13238);
    manualLayout->addWidget(manualScrolArea);
    manualScrolArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    manualScrolArea->setFixedWidth(825);
    manualMode->setLayout(manualLayout);
    setCentralWidget(manualMode);
}
QWidget* ManualMode::getManualWidget(){
    return manualMode;
}
