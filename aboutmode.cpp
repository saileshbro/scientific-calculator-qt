#include "aboutmode.h"

aboutMode::aboutMode(QWidget *parent) : QMainWindow(parent)
{
    aboutWindow = new QWidget;
    aboutLayout = new QVBoxLayout;
    aboutScrollArea = new QScrollArea;
    aboutLabel = new QLabel;

    CreateAboutWidget();
}
QWidget* aboutMode::getAboutWidget(){
    return aboutWindow;
}
void aboutMode::CreateAboutWidget(){
    this->setFixedWidth(900);
    aboutLabel->setPixmap(QPixmap(":/new/misc/about.jpg"));
    aboutScrollArea->setWidget(aboutLabel);
    aboutLayout->addWidget(aboutScrollArea);
    aboutWindow->setLayout(aboutLayout);
    setCentralWidget(aboutWindow);

}
