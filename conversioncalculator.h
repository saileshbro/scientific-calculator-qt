#ifndef CONVERSIONCALCULATOR_H
#define CONVERSIONCALCULATOR_H

#include <QMainWindow>
#include<QWidget>
#include<QGridLayout>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<iostream>
#include<cmath>
#include <QString>
#include <QDebug>

class ConversionCalculator : public QMainWindow
{
    Q_OBJECT
public:
    explicit ConversionCalculator(QWidget *parent = nullptr);
    ~ConversionCalculator();
    QWidget* getConversionWidget();
private:
    QWidget *ConversionWin,
            *UnitWin,
            *TempWin,
            *TimeWin,
            *LengthWin,
            *AreaWin,
            *VolumeWin,
            *MassWin,
            *AngleWin,
            *Co_ordWin;
QGridLayout *ConversionLayout,
            *UnitLayout,
            *TempLayout,
            *TimeLayout,
            *LengthLayout,
            *AreaLayout,
            *VolumeLayout,
            *MassLayout,
            *AngleLayout,
            *Co_ordLayout;
QPushButton      *Unit,
            *Temp,
            *Time,
            *Length,
            *Area,
            *Volume,
            *Mass,
            *Angle,
            *Co_ord,
            *clear;
QLineEdit   *UnitDispaly,
            *Unit1Display,
            *Unit2Display;
QLineEdit   *rect1,
            *rect2,
            *rect3,
            *pol1,
            *pol2,
            *cylin1,
            *cylin2,
            *cylin3,
            *sph1,
            *sph2,
            *sph3;
QPushButton      *SaveResult,
            *Convert1,
            *Convert2,
            *Convert3,
            *Convert4,
            *Convert5,
            *Convert6,
            *Convert7,
            *Convert8,
            *Convert9;

QLabel      *Chooselabel,
            *infoLabel,
            *info1Label,
            *info2Label,
            *UnitLabel,
            *TempLabel,
            *TimeLabel,
            *LengthLabel,
            *AreaLabel,
            *VolumeLabel,
            *MassLabel,
            *AngleLabel,
            *Co_ordLabel;
QLabel      *info,
            *info1,
            *info2,
            *info3,
            *info4,
            *info5,
            *info6,
            *info7,
            *info8,
            *info9,
            *info10;
    void CreateConversionWindow();


private slots:
    void unitPressed();
    void tempPressed();
    void timePressed();
    void lengthPressed();
    void areaPressed();
    void volumePressed();
    void massPressed();
    void anglePressed();
    void co_ordPressed();
//    void CreateMainWidget();
    void convert1Pressed();
    void convert2Pressed();
    void convert3Pressed();
    void convert4Pressed();
    void convert5Pressed();
    void Convert6Pressed();
    void Convert7Pressed();
    void Convert8Pressed();
    void Convert9Pressed();
    void savePressed();
    void clear1Pressed();
    void clear2Pressed();
};

#endif // CONVERSIONCALCULATOR_H
