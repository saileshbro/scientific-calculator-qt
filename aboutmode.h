#ifndef ABOUTMODE_H
#define ABOUTMODE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>

class aboutMode : public QMainWindow
{
    Q_OBJECT
public:
    aboutMode(QWidget *parent = 0);
    QWidget* getAboutWidget();
private:
    QWidget *aboutWindow;
    QVBoxLayout *aboutLayout;
    QScrollArea *aboutScrollArea;
    QLabel *aboutLabel;
    void CreateAboutWidget();
};

#endif // ABOUTMODE_H
