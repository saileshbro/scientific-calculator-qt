#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <button.h>
class MatrixCalculator: public QMainWindow
{
    Q_OBJECT
private:
    QWidget *matrixWindow;
    QGridLayout *matrixLayout;
    QLineEdit *matrixA[3][3],*matrixB[3][3],*matrixC[3][3],*displayMatrix;
    Button *btnSwapMatrix[2],
                *btnAddMatrix,
                *btnSubtractMatrix,
                *btnMultiplyMatrix,
                *btnDetA,
                *btnDetB,
                *btnInvA,
                *btnInvB,
                *btnTransA,
                *btnTransB,
                *btnDetC,
                *btnTransC,
                *btnInvC,
                *btnMatrixClear;
    QLabel  *matrixATitle,
            *matrixBTitle,
            *matrixCTitle;
    void CreateMatrixCalculatorWidget();
public:
    MatrixCalculator(QWidget *parent=0);
    QWidget* getMatrixWidget();
private slots:
    void onClearMatrixClicked();
    void onSwapMatrixPressed();
    void onAddMatrixPressed();
    void onSubtractMatrixPressed();
    void onTransPressed();
    void onDeterminantPressed();
    void onInversePressed();
    void onMultiplyMatrixPressed();
};

#endif // `_H
