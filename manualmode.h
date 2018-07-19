#ifndef MANUALMODE_H
#define MANUALMODE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDebug>

class ManualMode : public QMainWindow
{
    Q_OBJECT
public:
    ManualMode(QWidget *parent = nullptr);
    ~ManualMode();
    QWidget* getManualWidget();
private:
    QWidget *manualMode;
    QLabel *manualimage;
    QVBoxLayout *manualLayout;
    QScrollArea *manualScrolArea;
    void CreateManualWidget();
};

#endif // MANUALMODE_H
