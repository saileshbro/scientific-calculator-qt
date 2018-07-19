#ifndef BUTTON_H
#define BUTTON_H

#include <QString>
#include <QPushButton>
#include <QDebug>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(QString text,QWidget *parent = 0);
    Button(){}
protected:
    void mouseReleaseEvent(QMouseEvent *ev);

};
#endif // BUTTON_H
