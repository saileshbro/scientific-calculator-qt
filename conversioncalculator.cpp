#include "conversioncalculator.h"

ConversionCalculator::ConversionCalculator(QWidget *parent) : QMainWindow(parent)
{
    CreateConversionWindow();
}
void ConversionCalculator::CreateConversionWindow(){
    ConversionWin   = new QWidget;

    Unit     = new QPushButton ( " Unit " );
    Temp     = new QPushButton  ("  Temp ");
    Time     = new QPushButton  (" Time ");
    Length   = new QPushButton  (" Length ");
    Area     = new QPushButton  (" Area ");
    Volume   = new QPushButton  (" Volume ");
    Mass     = new QPushButton  (" Mass ");
    Angle    = new QPushButton  (" Angle ");
    Co_ord   = new QPushButton  (" Co-Ordinate ");

    Chooselabel       = new QLabel (" Choose the Conversion type : ");
    ConversionLayout = new QGridLayout;
    this->setFixedSize(1000,600);
    ConversionLayout->addWidget(Chooselabel,0,0,1,2);
    ConversionLayout->addWidget(Unit,1,0,1,1);
    ConversionLayout->addWidget(Temp,1,1,1,1);
    ConversionLayout->addWidget(Time,1,2,1,1);
    ConversionLayout->addWidget(Length,2,0,1,1);
    ConversionLayout->addWidget(Area,2,1,1,1);
    ConversionLayout->addWidget(Volume,2,2,1,1);
    ConversionLayout->addWidget(Mass,3,0,1,1);
    ConversionLayout->addWidget(Angle,3,1,1,1);
    ConversionLayout->addWidget(Co_ord,3,2,1,1);

    Unit               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Temp               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Time               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Length             ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Area               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Volume             ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Mass               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Angle              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Co_ord             ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Chooselabel        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    Unit               ->setFixedHeight(80);
    Temp               ->setFixedHeight(80);
    Time               ->setFixedHeight(80);
    Length             ->setFixedHeight(80);
    Area               ->setFixedHeight(80);
    Volume             ->setFixedHeight(80);
    Mass               ->setFixedHeight(80);
    Angle              ->setFixedHeight(80);
    Co_ord             ->setFixedHeight(80);
    Chooselabel        ->setFixedHeight(60);

    Chooselabel         ->setStyleSheet("QLabel{font: 16pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    Unit      ->setStyleSheet("QPushButton { font-size: 30px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:10px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    Temp      ->setStyleSheet("QPushButton { font-size: 30px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:10px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    Time      ->setStyleSheet("QPushButton { font-size: 30px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:10px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    Length    ->setStyleSheet("QPushButton { font-size: 30px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:10px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    Area      ->setStyleSheet("QPushButton { font-size: 30px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:10px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    Volume    ->setStyleSheet("QPushButton { font-size: 30px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:10px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    Mass      ->setStyleSheet("QPushButton { font-size: 30px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:10px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    Angle     ->setStyleSheet("QPushButton { font-size: 30px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:10px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    Co_ord    ->setStyleSheet("QPushButton { font-size: 30px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:10px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");

    connect(Unit,SIGNAL(clicked()),this,SLOT(unitPressed()));
    connect(Temp,SIGNAL(clicked()),this,SLOT(tempPressed()));
    connect(Time,SIGNAL(clicked()),this,SLOT(timePressed()));
    connect(Length,SIGNAL(clicked()),this,SLOT(lengthPressed()));
    connect(Area,SIGNAL(clicked()),this,SLOT(areaPressed()));
    connect(Volume,SIGNAL(clicked()),this,SLOT(volumePressed()));
    connect(Mass,SIGNAL(clicked()),this,SLOT(massPressed()));
    connect(Angle,SIGNAL(clicked()),this,SLOT(anglePressed()));
    connect(Co_ord,SIGNAL(clicked()),this,SLOT(co_ordPressed()));

    ConversionWin->setLayout(ConversionLayout);
    this->setCentralWidget(ConversionWin);

}
void ConversionCalculator::unitPressed(){
    UnitWin   = new QWidget;
    UnitLayout        = new QGridLayout;

    infoLabel         = new QLabel (" Case No: ");
    info1Label        = new QLabel (" Input  ");
    info2Label        = new QLabel (" Further convert: ");
    Convert4     = new QPushButton ( " convert " );
    SaveResult   = new QPushButton  ("  Save Result  ");
    clear        = new QPushButton  (" Clear ");

    UnitDispaly     = new QLineEdit;
    Unit1Display    = new QLineEdit;
    Unit2Display    = new QLineEdit;
    UnitLabel       = new QLabel;
    Unit2Display->setReadOnly(true);
    UnitLabel->setFixedSize(930,541);
    infoLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info1Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info2Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Convert4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SaveResult->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    clear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    UnitDispaly->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit1Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit2Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    UnitLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    clear              ->setFixedHeight(40);
    UnitDispaly        ->setFixedHeight(40);
    Unit1Display       ->setFixedHeight(40);
    Unit2Display       ->setFixedHeight(40);
    Convert4           ->setFixedHeight(40);
    infoLabel          ->setFixedHeight(40);
    info1Label         ->setFixedHeight(40);
    info2Label         ->setFixedHeight(40);
    SaveResult         ->setFixedHeight(40);



    UnitDispaly        ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit1Display       ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit2Display       ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    info1Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    infoLabel           ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    info2Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    UnitLabel         ->setStyleSheet("QLabel{background-image:url(:/new/images/images/unit.png); background-repeat:no repeat;}");
    Convert4  ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");

    clear     ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    SaveResult->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");


    connect(SaveResult,SIGNAL(clicked(bool)),this,SLOT(savePressed()));
    connect(Convert4,SIGNAL(clicked(bool)),this,SLOT(convert4Pressed()));
    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear1Pressed()));

    UnitLayout->addWidget(infoLabel,0,0,1,1);
    UnitLayout->addWidget(info1Label,0,1,1,1);
    UnitLayout->addWidget(info2Label,2,2,1,1);
    UnitLayout->addWidget(Convert4,1,2,1,1);
    UnitLayout->addWidget(SaveResult,2,3,1,1);
    UnitLayout->addWidget(clear,2,0,1,1);
    UnitLayout->addWidget(UnitDispaly,1,0,1,1);
    UnitLayout->addWidget(Unit1Display,1,1,1,1);
    UnitLayout->addWidget(Unit2Display,1,3,1,1);
    UnitLayout->addWidget(UnitLabel,3,0,1,1);

    UnitWin->setLayout(UnitLayout);
    this->setCentralWidget(UnitWin);
    this->setWindowTitle("Convert Unit");
    show();
}
void ConversionCalculator::tempPressed(){
    TempWin         = new QWidget;
    TempLayout      = new QGridLayout;
    infoLabel       = new QLabel (" Case No: ");
    info1Label      = new QLabel (" Input  ");
    info2Label      = new QLabel (" Further convert: ");
    Convert2        = new QPushButton ( " convert " );
    UnitDispaly     = new QLineEdit;
    Unit1Display    = new QLineEdit;
    Unit2Display    = new QLineEdit;
    TempLabel       = new QLabel;
    clear           = new QPushButton  (" Clear ");

    SaveResult   = new QPushButton  ("  Save Result  ");
    Unit2Display->setReadOnly(true);
    TempLabel->setFixedSize(556,247);
    infoLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info1Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info2Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Convert2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    clear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    UnitDispaly->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit2Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit1Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    TempLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    SaveResult->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    infoLabel          ->setFixedHeight(40);
    info1Label         ->setFixedHeight(40);
    info2Label         ->setFixedHeight(40);
    Convert2           ->setFixedHeight(40);
    clear              ->setFixedHeight(40);
    UnitDispaly        ->setFixedHeight(40);
    Unit1Display       ->setFixedHeight(40);
    Unit2Display       ->setFixedHeight(40);


    SaveResult         ->setFixedHeight(40);

    UnitDispaly        ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit1Display       ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit2Display       ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    info1Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    infoLabel           ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    info2Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    Convert2            ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    clear     ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    TempLabel         ->setStyleSheet("QLabel{background-image:url(:/new/images/images/temp.png);background-repeat:no repeat;}");

    SaveResult->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");

    TempLayout->addWidget(infoLabel,0,0,1,1);
    TempLayout->addWidget(info1Label,0,1,1,1);
    TempLayout->addWidget(info2Label,2,2,1,1);
    TempLayout->addWidget(Convert2,1,2,1,1);
    TempLayout->addWidget(clear,2,0,1,1);
    TempLayout->addWidget(UnitDispaly,1,0,1,1);
    TempLayout->addWidget(Unit1Display,1,1,1,1);
    TempLayout->addWidget(Unit2Display,1,3,1,2);
    TempLayout->addWidget(TempLabel,3,0,6,6);

    TempLayout->addWidget(SaveResult,2,3,1,1);


    connect(Convert2,SIGNAL(clicked(bool)),this,SLOT(convert2Pressed()));
    connect(SaveResult,SIGNAL(clicked(bool)),this,SLOT(savePressed()));
    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear1Pressed()));
    TempWin->setLayout(TempLayout);
    this->setCentralWidget(TempWin);
    this->setWindowTitle("Convert Temperature");
    this->setFixedSize(700,500);
    show();
}
void ConversionCalculator::timePressed(){
    TimeWin = new QWidget;
    TimeLayout  = new QGridLayout;
    infoLabel         = new QLabel (" Case No: ");
    info1Label        = new QLabel (" Input  ");
    info2Label        = new QLabel (" Further convert: ");
    Convert3     = new QPushButton ( " convert " );
    SaveResult   = new QPushButton  ("  Save Result  ");
    clear        = new QPushButton  (" Clear ");

    UnitDispaly     = new QLineEdit;
    Unit1Display    = new QLineEdit;
    Unit2Display    = new QLineEdit;
    TimeLabel       = new QLabel;
    TimeLabel->setFixedSize(698,424);
    TimeLayout->addWidget(infoLabel,0,0,1,1);
    TimeLayout->addWidget(info1Label,0,1,1,1);
    TimeLayout->addWidget(info2Label,2,2,1,1);
    TimeLayout->addWidget(Convert3,1,2,1,1);
    TimeLayout->addWidget(SaveResult,2,3,1,1);
    TimeLayout->addWidget(clear,2,0,1,1);
    TimeLayout->addWidget(UnitDispaly,1,0,1,1);
    TimeLayout->addWidget(Unit1Display,1,1,1,1);
    TimeLayout->addWidget(Unit2Display,1,3,1,1);
    TimeLayout->addWidget(TimeLabel,3,0,6,6);

    Unit2Display->setReadOnly(true);
    infoLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info1Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info2Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Convert3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SaveResult->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    clear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    UnitDispaly->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit1Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit2Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    TimeLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    clear              ->setFixedHeight(40);
    UnitDispaly        ->setFixedHeight(40);
    Unit1Display       ->setFixedHeight(40);
    Unit2Display       ->setFixedHeight(40);
    Convert3           ->setFixedHeight(40);
    infoLabel          ->setFixedHeight(40);
    info1Label         ->setFixedHeight(40);
    info2Label         ->setFixedHeight(40);
    SaveResult         ->setFixedHeight(40);



    UnitDispaly        ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit1Display       ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit2Display       ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    info1Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    infoLabel           ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    info2Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    TimeLabel         ->setStyleSheet("QLabel{background-image:url(:/new/images/images/time.png); background-repeat:no repeat;}");
    Convert3  ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");

    clear     ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    SaveResult->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");


    connect(SaveResult,SIGNAL(clicked(bool)),this,SLOT(savePressed()));
    connect(Convert3,SIGNAL(clicked(bool)),this,SLOT(convert3Pressed()));
    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear1Pressed()));

    TimeWin->setLayout(TimeLayout);
    this->setCentralWidget(TimeWin);
    this->setFixedSize(800,700);
    this->setWindowTitle("Convert Time");
    show();
}
void ConversionCalculator::lengthPressed(){
    LengthWin   = new QWidget;
    LengthLayout        = new QGridLayout;

    infoLabel         = new QLabel (" Case No: ");
    info1Label        = new QLabel (" Input  ");
    info2Label        = new QLabel (" Further convert: ");
    Convert4     = new QPushButton ( " convert " );
    SaveResult   = new QPushButton  ("  Save Result  ");
    clear        = new QPushButton  (" Clear ");

    UnitDispaly     = new QLineEdit;
    Unit1Display    = new QLineEdit;
    Unit2Display    = new QLineEdit;
    LengthLabel       = new QLabel;
    LengthLabel->setFixedSize(804,346);
    Unit2Display->setReadOnly(true);
    infoLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info1Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info2Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Convert4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SaveResult->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    clear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    UnitDispaly->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit1Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit2Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    LengthLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    clear              ->setFixedHeight(40);
    UnitDispaly        ->setFixedHeight(40);
    Unit1Display       ->setFixedHeight(40);
    Unit2Display       ->setFixedHeight(40);
    Convert4           ->setFixedHeight(40);
    infoLabel          ->setFixedHeight(40);
    info1Label         ->setFixedHeight(40);
    info2Label         ->setFixedHeight(40);
    SaveResult         ->setFixedHeight(40);



    UnitDispaly        ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit1Display       ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit2Display       ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    info1Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    infoLabel           ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    info2Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    LengthLabel         ->setStyleSheet("QLabel{background-image:url(:/new/images/images/length.png); background-repeat:no repeat;}");
    Convert4  ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");

    clear     ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    SaveResult->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");


    connect(SaveResult,SIGNAL(clicked(bool)),this,SLOT(savePressed()));
    connect(Convert4,SIGNAL(clicked(bool)),this,SLOT(convert4Pressed()));
    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear1Pressed()));

    LengthLayout->addWidget(infoLabel,0,0,1,1);
    LengthLayout->addWidget(info1Label,0,1,1,1);
    LengthLayout->addWidget(info2Label,2,2,1,1);
    LengthLayout->addWidget(Convert4,1,2,1,1);
    LengthLayout->addWidget(SaveResult,2,3,1,1);
    LengthLayout->addWidget(clear,2,0,1,1);
    LengthLayout->addWidget(UnitDispaly,1,0,1,1);
    LengthLayout->addWidget(Unit1Display,1,1,1,1);
    LengthLayout->addWidget(Unit2Display,1,3,1,1);
    LengthLayout->addWidget(LengthLabel,3,0,1,1);


    LengthWin->setLayout(LengthLayout);
    this->setCentralWidget(LengthWin);
    this->setWindowTitle("Convert Length");
    show();
}
void ConversionCalculator::areaPressed(){
    AreaWin = new QWidget;
    AreaLayout  = new QGridLayout;

    infoLabel         = new QLabel (" Case No: ");
    info1Label        = new QLabel (" Input  ");
    info2Label        = new QLabel (" Further convert: ");
    Convert5     = new QPushButton ( " convert " );
    SaveResult   = new QPushButton  ("  Save Result  ");
    clear        = new QPushButton  (" Clear ");

    UnitDispaly     = new QLineEdit;
    Unit1Display    = new QLineEdit;
    Unit2Display    = new QLineEdit;
    AreaLabel       = new QLabel;
    AreaLabel->setFixedSize(781,303);
    Unit2Display->setReadOnly(true);
    infoLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info1Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info2Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Convert5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SaveResult->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    clear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    UnitDispaly->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit1Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit2Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    AreaLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    clear              ->setFixedHeight(40);
    UnitDispaly        ->setFixedHeight(40);
    Unit1Display       ->setFixedHeight(40);
    Unit2Display       ->setFixedHeight(40);
    Convert5           ->setFixedHeight(40);
    infoLabel          ->setFixedHeight(40);
    info1Label         ->setFixedHeight(40);
    info2Label         ->setFixedHeight(40);
    SaveResult         ->setFixedHeight(40);


    UnitDispaly        ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit1Display       ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit2Display       ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    info1Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    infoLabel           ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    info2Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    AreaLabel         ->setStyleSheet("QLabel{background-image:url(:/new/images/images/area.png); background-repeat:no repeat;}");
    Convert5  ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");

    clear     ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    SaveResult->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");


    connect(SaveResult,SIGNAL(clicked(bool)),this,SLOT(savePressed()));
    connect(Convert5,SIGNAL(clicked(bool)),this,SLOT(convert5Pressed()));
    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear1Pressed()));

    AreaLayout->addWidget(infoLabel,0,0,1,1);
    AreaLayout->addWidget(info1Label,0,1,1,1);
    AreaLayout->addWidget(info2Label,2,2,1,1);
    AreaLayout->addWidget(Convert5,1,2,1,1);
    AreaLayout->addWidget(SaveResult,2,3,1,1);
    AreaLayout->addWidget(clear,2,0,1,1);
    AreaLayout->addWidget(UnitDispaly,1,0,1,1);
    AreaLayout->addWidget(Unit1Display,1,1,1,1);
    AreaLayout->addWidget(Unit2Display,1,3,1,1);
    AreaLayout->addWidget(AreaLabel,3,0,6,6);

    AreaWin->setLayout(AreaLayout);
    this->setCentralWidget(AreaWin);
    this->setWindowTitle("Convert Area");
    this->setFixedSize(800,500);
    show();
}
void ConversionCalculator::volumePressed(){
    VolumeWin= new QWidget;
    VolumeLayout    = new QGridLayout;
    infoLabel         = new QLabel (" Case No: ");
    info1Label        = new QLabel (" Input  ");
    info2Label        = new QLabel (" Further convert: ");
    Convert6     = new QPushButton ( " convert " );
    SaveResult   = new QPushButton  ("  Save Result  ");
    clear        = new QPushButton  (" Clear ");

    UnitDispaly     = new QLineEdit;
    Unit1Display    = new QLineEdit;
    Unit2Display    = new QLineEdit;
    VolumeLabel       = new QLabel;
    Unit2Display->setReadOnly(true);
    VolumeLabel->setFixedSize(712,319);
    infoLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info1Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info2Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Convert6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SaveResult->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    clear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    UnitDispaly->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit1Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit2Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    VolumeLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    clear              ->setFixedHeight(40);
    UnitDispaly        ->setFixedHeight(40);
    Unit1Display       ->setFixedHeight(40);
    Unit2Display       ->setFixedHeight(40);
    Convert6           ->setFixedHeight(40);
    infoLabel          ->setFixedHeight(40);
    info1Label         ->setFixedHeight(40);
    info2Label         ->setFixedHeight(40);
    SaveResult         ->setFixedHeight(40);


    UnitDispaly        ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit1Display       ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit2Display       ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    info1Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    infoLabel           ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    info2Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    VolumeLabel         ->setStyleSheet("QLabel{background-image:url(:/new/images/images/volume.png); background-repeat:no repeat;}");
    Convert6  ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");

    clear     ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    SaveResult->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");


    connect(SaveResult,SIGNAL(clicked(bool)),this,SLOT(savePressed()));
    connect(Convert6,SIGNAL(clicked(bool)),this,SLOT(Convert6Pressed()));
    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear1Pressed()));

    VolumeLayout->addWidget(infoLabel,0,0,1,1);
    VolumeLayout->addWidget(info1Label,0,1,1,1);
    VolumeLayout->addWidget(info2Label,2,2,1,1);
    VolumeLayout->addWidget(Convert6,1,2,1,1);
    VolumeLayout->addWidget(SaveResult,2,3,1,1);
    VolumeLayout->addWidget(clear,2,0,1,1);
    VolumeLayout->addWidget(UnitDispaly,1,0,1,1);
    VolumeLayout->addWidget(Unit1Display,1,1,1,1);
    VolumeLayout->addWidget(Unit2Display,1,3,1,1);
    VolumeLayout->addWidget(VolumeLabel,3,0,1,1);


    VolumeWin->setLayout(VolumeLayout);
    this->setCentralWidget(VolumeWin);
    this->setWindowTitle("Convert Volume");
    this->setFixedSize(800,600);
    show();
}
void ConversionCalculator::massPressed(){
    MassWin = new QWidget;
    MassLayout = new QGridLayout;
    infoLabel         = new QLabel (" Case No: ");
    info1Label        = new QLabel (" Input  ");
    info2Label        = new QLabel (" Further convert: ");
    Convert7     = new QPushButton ( " convert " );
    SaveResult   = new QPushButton  ("  Save Result  ");
    clear        = new QPushButton  (" Clear ");

    UnitDispaly     = new QLineEdit;
    Unit1Display    = new QLineEdit;
    Unit2Display    = new QLineEdit;
    MassLabel       = new QLabel;
    Unit2Display->setReadOnly(true);
    MassLabel->setFixedSize(655,373);
    infoLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info1Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info2Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Convert7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SaveResult->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    clear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    UnitDispaly->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit1Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit2Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    MassLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    clear              ->setFixedHeight(40);
    UnitDispaly        ->setFixedHeight(40);
    Unit1Display       ->setFixedHeight(40);
    Unit2Display       ->setFixedHeight(40);
    Convert7           ->setFixedHeight(40);
    infoLabel          ->setFixedHeight(40);
    info1Label         ->setFixedHeight(40);
    info2Label         ->setFixedHeight(40);
    SaveResult         ->setFixedHeight(40);


    UnitDispaly        ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit1Display       ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit2Display       ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    info1Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    infoLabel           ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    info2Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    MassLabel         ->setStyleSheet("QLabel{background-image:url(:/new/images/images/mass.png); background-repeat:no repeat;}");
    Convert7  ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");

    clear     ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    SaveResult->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");


    connect(SaveResult,SIGNAL(clicked(bool)),this,SLOT(savePressed()));
    connect(Convert7,SIGNAL(clicked(bool)),this,SLOT(Convert7Pressed()));
    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear1Pressed()));
    MassLayout->addWidget(infoLabel,0,0,1,1);
    MassLayout->addWidget(info1Label,0,1,1,1);
    MassLayout->addWidget(info2Label,2,2,1,1);
    MassLayout->addWidget(Convert7,1,2,1,1);
    MassLayout->addWidget(SaveResult,2,3,1,1);
    MassLayout->addWidget(clear,2,0,1,1);
    MassLayout->addWidget(UnitDispaly,1,0,1,1);
    MassLayout->addWidget(Unit1Display,1,1,1,1);
    MassLayout->addWidget(Unit2Display,1,3,1,1);
    MassLayout->addWidget(MassLabel,3,0,6,6);

    MassWin->setLayout(MassLayout);
    this->setCentralWidget(MassWin);
    this->setWindowTitle("Convert Mass");
    this->setFixedSize(800,600);
    show();
}
void ConversionCalculator::anglePressed(){
    AngleWin = new QWidget;
    AngleLayout = new QGridLayout;
    infoLabel         = new QLabel (" Case No: ");
    info1Label        = new QLabel (" Input  ");
    info2Label        = new QLabel (" Further convert: ");
    Convert8     = new QPushButton ( " convert " );
    SaveResult   = new QPushButton  ("  Save Result  ");
    clear        = new QPushButton  (" Clear ");

    UnitDispaly     = new QLineEdit;
    Unit1Display    = new QLineEdit;
    Unit2Display    = new QLineEdit;
    AngleLabel       = new QLabel;
    AngleLabel->setFixedSize(745,258);
    Unit2Display->setReadOnly(true);
    infoLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info1Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    info2Label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Convert8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SaveResult->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    clear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    UnitDispaly->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit1Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Unit2Display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    AngleLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    clear              ->setFixedHeight(40);
    UnitDispaly        ->setFixedHeight(40);
    Unit1Display       ->setFixedHeight(40);
    Unit2Display       ->setFixedHeight(40);
    Convert8           ->setFixedHeight(40);
    infoLabel          ->setFixedHeight(40);
    info1Label         ->setFixedHeight(40);
    info2Label         ->setFixedHeight(40);
    SaveResult         ->setFixedHeight(40);


    UnitDispaly        ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit1Display       ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Unit2Display       ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    info1Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    infoLabel           ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    info2Label          ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
    AngleLabel         ->setStyleSheet("QLabel{background-image:url(:/new/images/images/angle.png); background-repeat:no repeat;}");
    Convert8  ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    clear     ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    SaveResult->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");


    connect(SaveResult,SIGNAL(clicked(bool)),this,SLOT(savePressed()));
    connect(Convert8,SIGNAL(clicked(bool)),this,SLOT(Convert8Pressed()));
    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear1Pressed()));
    AngleLayout->addWidget(infoLabel,0,0,1,1);
    AngleLayout->addWidget(info1Label,0,1,1,1);
    AngleLayout->addWidget(info2Label,2,2,1,1);
    AngleLayout->addWidget(Convert8,1,2,1,1);
    AngleLayout->addWidget(SaveResult,2,3,1,1);
    AngleLayout->addWidget(clear,2,0,1,1);
    AngleLayout->addWidget(UnitDispaly,1,0,1,1);
    AngleLayout->addWidget(Unit1Display,1,1,1,1);
    AngleLayout->addWidget(Unit2Display,1,3,1,1);
    AngleLayout->addWidget(AngleLabel,3,0,6,6);

    AngleWin->setLayout(AngleLayout);
    this->setCentralWidget(AngleWin);
    this->setWindowTitle("Convert Angle");
    this->setFixedSize(800,500);
    show();
}
void ConversionCalculator::co_ordPressed(){
        Co_ordWin   = new QWidget;
        Co_ordLayout    = new QGridLayout;
        info              = new QLabel (" X ");
        info1             = new QLabel (" Y ");
        info2             = new QLabel (" Z ");
        info3             = new QLabel (" R ");
        info4             = new QLabel (" Angle in degree ");
        info5             = new QLabel (" P ");
        info6             = new QLabel (" Phi ");
        info7             = new QLabel (" R ");
        info8             = new QLabel (" Angle in degree ");
        info9             = new QLabel (" Z ");
        info10            = new QLabel (" Angle in degree ");
        rect1                 = new QLineEdit;
        rect2                 = new QLineEdit;
        rect3                 = new QLineEdit;
        pol1                  = new QLineEdit;
        pol2                  = new QLineEdit;
        cylin1                = new QLineEdit;
        cylin2                = new QLineEdit;
        cylin3                = new QLineEdit;
        sph1                  = new QLineEdit;
        sph2                  = new QLineEdit;
        sph3                  = new QLineEdit;
        Convert9= new QPushButton ( " convert " );
        clear= new QPushButton  (" Clear ");



        rect1              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        rect2              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        rect3              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        pol1               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        pol2               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        cylin1             ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        cylin2             ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        cylin3             ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sph1               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sph2               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sph3               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info               ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info1              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info2              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info3              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info4              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info5              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info6              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info7              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info8              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info9              ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        info10             ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

        rect1              ->setFixedHeight(60);
        rect2              ->setFixedHeight(60);
        rect3              ->setFixedHeight(60);
        pol1               ->setFixedHeight(60);
        pol2               ->setFixedHeight(60);
        cylin1             ->setFixedHeight(60);
        cylin2             ->setFixedHeight(60);
        cylin3             ->setFixedHeight(60);
        sph1               ->setFixedHeight(60);
        sph2               ->setFixedHeight(60);
        sph3               ->setFixedHeight(60);
        info               ->setFixedHeight(40);
        info1              ->setFixedHeight(40);
        info2              ->setFixedHeight(40);
        info3              ->setFixedHeight(40);
        info4              ->setFixedHeight(40);
        info5              ->setFixedHeight(40);
        info6              ->setFixedHeight(40);
        info7              ->setFixedHeight(40);
        info8              ->setFixedHeight(40);
        info9              ->setFixedHeight(40);
        info10             ->setFixedHeight(40);

        rect1              ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        rect2              ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        rect3              ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        pol1               ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        pol2               ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        cylin1             ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        cylin2             ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        cylin3             ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        sph1               ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        sph2               ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        sph3               ->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        info ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info1 ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info2 ->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info3->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info4->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info5->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info6->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info7->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info8->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info9->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        info10->setStyleSheet("QLabel{font:14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 5px; }");
        Convert9  ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");

        clear     ->setStyleSheet("QPushButton { font-size: 24px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");



        Co_ordLayout->addWidget(info,0,0,1,1);
        Co_ordLayout->addWidget(info1,0,1,1,1);
        Co_ordLayout->addWidget(info2,0,2,1,1);
        Co_ordLayout->addWidget(info3,2,0,1,1);
        Co_ordLayout->addWidget(info4,2,1,1,1);
        Co_ordLayout->addWidget(info5,6,0,1,1);
        Co_ordLayout->addWidget(info6,6,1,1,1);
        Co_ordLayout->addWidget(info7,4,0,1,1);
        Co_ordLayout->addWidget(info8,4,1,1,1);
        Co_ordLayout->addWidget(info9,4,2,1,1);
        Co_ordLayout->addWidget(info10,6,2,1,1);
        Co_ordLayout->addWidget(rect1,1,0,1,1);
        Co_ordLayout->addWidget(rect2,1,1,1,1);
        Co_ordLayout->addWidget(rect3,1,2,1,1);
        Co_ordLayout->addWidget(pol1,3,0,1,1);
        Co_ordLayout->addWidget(pol2,3,1,1,1);
        Co_ordLayout->addWidget(cylin1,5,0,1,1);
        Co_ordLayout->addWidget(cylin2,5,1,1,1);
        Co_ordLayout->addWidget(cylin3,5,2,1,1);
        Co_ordLayout->addWidget(sph1,7,0,1,1);
        Co_ordLayout->addWidget(sph2,7,1,1,1);
        Co_ordLayout->addWidget(sph3,7,2,1,1);
        Co_ordLayout->addWidget(Convert9,3,6,1,1);
        Co_ordLayout->addWidget(clear,5,6,1,1);



        connect(Convert9,SIGNAL(clicked(bool)),this,SLOT(Convert9Pressed()));
        connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear2Pressed()));
        Co_ordWin->setLayout(Co_ordLayout);
        this->setCentralWidget(Co_ordWin);
        this->setFixedSize(800,700);
        this->setWindowTitle("Convert Coordinates");
        show();
}



void ConversionCalculator::convert1Pressed(){
    int  a = UnitDispaly->text().toInt();
    double  b = Unit1Display->text().toDouble();
    double a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32;
    switch(a){
    case 1:
        a1 = b*10;
        Unit2Display->setText(QString::number(a1));
        break;
    case 2:
        a2 =b*100;
        Unit2Display->setText(QString::number(a2));
        break;
    case 3:
        a3 = b*1000;
        Unit2Display->setText(QString::number(a3));
        break;
    case 4:
        a4= b*pow(10.0,6.0);
        Unit2Display->setText(QString::number(a4));
        break;
    case 5:
        a5 =b*pow(10.0,9.0);
        Unit2Display->setText(QString::number(a5));
        break;
    case 6:
        a6 = b*pow(10.0,10.0);
        Unit2Display->setText(QString::number(a6));
        break;
    case 7:
        a7 = b*pow(10.0,12.0);
        Unit2Display->setText(QString::number(a7));
        break;
    case 8:
        a8 = b*pow(10.0,15.0);
        Unit2Display->setText(QString::number(a8));
        break;
    case 9:
        a9 = b/pow(10.0,1.0);
        Unit2Display->setText(QString::number(a9));
        break;
    case 10:
        a10 =b/pow(10.0,2.0);
        Unit2Display->setText(QString::number(a10));
        break;
    case 11:
        a11 = b/pow(10.0,3.0);
        Unit2Display->setText(QString::number(a11));
        break;
    case 12:
        a12 = b/pow(10.0,6.0);
        Unit2Display->setText(QString::number(a12));
        break;
    case 13:
        a13 = b/pow(10.0,9.0);
        Unit2Display->setText(QString::number(a13));
        break;
    case 14:
        a14 = b/pow(10.0,12.0);
        Unit2Display->setText(QString::number(a14));
        break;
    case 15:
        a15 = b/pow(10.0,15.0);
        Unit2Display->setText(QString::number(a15));
        break;
    case 16:
        a16 = b/pow(10.0,18.0);
        Unit2Display->setText(QString::number(a16));
        break;
    case 17:
        a17 =  b/pow(10.0,1.0);
        Unit2Display->setText(QString::number(a17));
        break;
    case 18:
        a18 =  b/pow(10.0,2.0);
        Unit2Display->setText(QString::number(a18));
        break;
    case 19:
        a19 = b/pow(10.0,3.0);
        Unit2Display->setText(QString::number(a19));
        break;
    case 20:
        a20 =  b/pow(10.0,6.0);
        Unit2Display->setText(QString::number(a20));
        break;
    case 21:
        a21 =  b/pow(10.0,9.0);
        Unit2Display->setText(QString::number(a21));
        break;
    case 22:
        a22 =  b/pow(10.0,10.0);
        Unit2Display->setText(QString::number(a22));
        break;
    case 23:
        a23 =  b/pow(10.0,12.0);
        Unit2Display->setText(QString::number(a23));
        break;
    case 24:
        a24 =  b/pow(10.0,15.0);
        Unit2Display->setText(QString::number(a24));
        break;
    case 25:
        a25 = b*pow(10.0,1.0);
        Unit2Display->setText(QString::number(a25));
        break;
    case 26:
        a26 =  b*pow(10.0,2.0);
        Unit2Display->setText(QString::number(a26));
        break;
    case 27:
        a27 =  b*pow(10.0,3.0);
        Unit2Display->setText(QString::number(a27));
        break;
    case 28:
        a28 =  b*pow(10.0,6.0);
        Unit2Display->setText(QString::number(a28));
        break;
    case 29:
        a29 =  b*pow(10.0,9.0);
        Unit2Display->setText(QString::number(a29));
        break;
    case 30:
        a30 =  b*pow(10.0,12.0);
        Unit2Display->setText(QString::number(a30));
        break;
    case 31:
         a31 =  b*pow(10.0,15.0);
        Unit2Display->setText(QString::number(a31));
        break;
    case 32:
        a32 = b*pow(10.0,18.0);
        Unit2Display->setText(QString::number(a32));
        break;
    default:
        Unit2Display->setText(" Check Case No: ");
    }
}
void ConversionCalculator::convert2Pressed(){
    int  a = UnitDispaly->text().toInt();
    double  b = Unit1Display->text().toDouble();
    double a1,a2,a3,a4;
    switch(a){
    case 1:
         a1 = (9/5)*b +32 ;
        Unit2Display->setText(QString::number(a1));
        break;
    case 2:
         a2 = b -273.16;
        Unit2Display->setText(QString::number(a2));
        break;
    case 3:
         a3 = (5/9)* (b-32);
        Unit2Display->setText(QString::number(a3));
        break;
    case 4:
         a4= b +273.16;
        Unit2Display->setText(QString::number(a4));
        break;
    default:
        Unit2Display->setText(" Check Case No: ");
    }
}
void ConversionCalculator::convert3Pressed(){
    int  a = UnitDispaly->text().toInt();
      double  b = Unit1Display->text().toDouble();
      double a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
      switch(a){
      case 1:
           a1 = b/100 ;
          Unit2Display->setText(QString::number(a1));
          break;
      case 2:
           a2 = b/10;
          Unit2Display->setText(QString::number(a2));
          break;
      case 3:
           a3 = b*12;
          Unit2Display->setText(QString::number(a3));
          break;
      case 4:
           a4= b*(365/7);
          Unit2Display->setText(QString::number(a4));
          break;
      case 5:
           a5 =b*365;
          Unit2Display->setText(QString::number(a5));
          break;
      case 6:
           a6 = b*365*24;
          Unit2Display->setText(QString::number(a6));
          break;
      case 7:
           a7 = b*365*24*60;
          Unit2Display->setText(QString::number(a7));
          break;
      case 8:
           a8 = b*365*24*60*60;
          Unit2Display->setText(QString::number(a8));
          break;
      case 9:
           a9 = b*100;
          Unit2Display->setText(QString::number(a9));
          break;
      case 10:
           a10 = b*10;
          Unit2Display->setText(QString::number(a10));
          break;
      case 11:
           a11 = b/12;
          Unit2Display->setText(QString::number(a11));
          break;
      case 12:
           a12 = b/(365/7);
          Unit2Display->setText(QString::number(a12));
          break;
      case 13:
           a13 = b/365;
          Unit2Display->setText(QString::number(a13));
          break;
      case 14:
           a14 = b/(365*24);
          Unit2Display->setText(QString::number(a14));
          break;
      case 15:
           a14 = b/(365*24*60);
          Unit2Display->setText(QString::number(a14));
          break;
      case 16:
           a14 = b/(365*24*60*60);
          Unit2Display->setText(QString::number(a14));
          break;
      default:
          Unit2Display->setText(" Check Case No: ");
    }
}
void ConversionCalculator::convert4Pressed(){
    int  a = UnitDispaly->text().toInt();
    double  b = Unit1Display->text().toDouble();
    double a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
    switch(a){
    case 1:
         a1 = b*100;
        Unit2Display->setText(QString::number(a1));
        break;
    case 2:
         a2 = b*39.3701 ;
        Unit2Display->setText(QString::number(a2));
        break;
    case 3:
         a3 = b*3.28084;
        Unit2Display->setText(QString::number(a3));
        break;
    case 4:
         a4= b*1.09361;
        Unit2Display->setText(QString::number(a4));
        break;
    case 5:
         a5 =b*0.000621371;
        Unit2Display->setText(QString::number(a5));
        break;
    case 6:
         a6 = b/1000;
        Unit2Display->setText(QString::number(a6));
        break;
    case 7:
         a7 = b/100 ;
        Unit2Display->setText(QString::number(a7));
        break;
    case 8:
         a8 = b/39.3701;
        Unit2Display->setText(QString::number(a8));
        break;
    case 9:
         a9 = b/3.28084;
        Unit2Display->setText(QString::number(a9));
        break;
    case 10:
         a10 =b/1.09361;
        Unit2Display->setText(QString::number(a10));
        break;
    case 11:
         a10 =b/0.000621371;
        Unit2Display->setText(QString::number(a10));
        break;
    case 12:
         a10 =b*1000;
        Unit2Display->setText(QString::number(a10));
        break;
    default:
        Unit2Display->setText(" Check Case No: ");
    }
}
void ConversionCalculator::convert5Pressed(){
    int  a = UnitDispaly->text().toInt();
    double  b = Unit1Display->text().toDouble();
    double a1,a2,a3,a4,a5,a6,a7,a8;
    switch(a){
    case 1:
         a1 = b*0.000247105;
        Unit2Display->setText(QString::number(a1));
        break;
    case 2:
         a2 =b*0.0001;
        Unit2Display->setText(QString::number(a2));
        break;
    case 3:
         a3 = b/pow(1000.0,2.0);
        Unit2Display->setText(QString::number(a3));
        break;
    case 4:
         a4= b*pow(10.0,4);
        Unit2Display->setText(QString::number(a4));
        break;
    case 5:
         a5 =b/0.000247105;
        Unit2Display->setText(QString::number(a5));
        break;
    case 6:
         a6 = b/0.0001;
        Unit2Display->setText(QString::number(a6));
        break;
    case 7:
         a7 = b*pow(1000.0,2.0);
        Unit2Display->setText(QString::number(a7));
        break;
    case 8:
         a8 = b/pow(10.0,4.0);
        Unit2Display->setText(QString::number(a8));
        break;
    default:
        Unit2Display->setText(" Check Case No: ");
    }
}
void ConversionCalculator::Convert6Pressed(){
    int  a = UnitDispaly->text().toInt();
    double  b = Unit1Display->text().toDouble();
    double a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
    switch(a){
        case 1:
            a1 = b/1000;
           Unit2Display->setText(QString::number(a1));
           break;
        case 2:
            a2 = b*1000;
           Unit2Display->setText(QString::number(a2));
           break;
        case 3:
            a3 = b*1000;
           Unit2Display->setText(QString::number(a3));
           break;
        case 4:
            a4= b/159;
           Unit2Display->setText(QString::number(a4));
           break;
        case 5:
            a5 =b*0.264172;
           Unit2Display->setText(QString::number(a5));
           break;
        case 6:
            a6 = b*1000;
           Unit2Display->setText(QString::number(a6));
           break;
        case 7:
            a7 = b/1000;
           Unit2Display->setText(QString::number(a7));
           break;
        case 8:
            a8 = b/1000;
           Unit2Display->setText(QString::number(a8));
           break;
        case 9:
            a9 = b*159;
           Unit2Display->setText(QString::number(a9));
           break;
        case 10:
            a10 =b/0.264172;
           Unit2Display->setText(QString::number(a10));
           break;
        default:
           Unit2Display->setText(" Check Case No: ");
    }
}
void ConversionCalculator::Convert7Pressed(){
    int  a = UnitDispaly->text().toInt();
       double  b = Unit1Display->text().toDouble();
       double a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
       switch(a){
       case 1:
            a1 = b*1000;
           Unit2Display->setText(QString::number(a1));
           break;
       case 2:
            a2 =b*pow(10.0,6.0);
           Unit2Display->setText(QString::number(a2));
           break;
       case 3:
            a3 = b*2.20462;
           Unit2Display->setText(QString::number(a3));
           break;
       case 4:
            a4= b/100;
           Unit2Display->setText(QString::number(a4));
           break;
       case 5:
            a5 =b*0.00110231;
           Unit2Display->setText(QString::number(a5));
           break;
       case 6:
            a6 = b*6.022*pow(10.0,26.0);
           Unit2Display->setText(QString::number(a6));
           break;
       case 7:
            a7 = b*5000;
           Unit2Display->setText(QString::number(a7));
           break;
       case 8:
            a8 = b/1000;
           Unit2Display->setText(QString::number(a8));
           break;
       case 9:
            a9 = b/pow(10.0,6.0);
           Unit2Display->setText(QString::number(a9));
           break;
       case 10:
            a10 =b/2.20462;
           Unit2Display->setText(QString::number(a10));
           break;
       case 11:
            a11 = b*100;
           Unit2Display->setText(QString::number(a11));
           break;
       case 12:
            a12 = b/0.00110231;
           Unit2Display->setText(QString::number(a12));
           break;
       case 13:
            a13 = b/(6.022*pow(10.0,26.0));
           Unit2Display->setText(QString::number(a13));
           break;
       case 14:
            a14 = b/5000;
           Unit2Display->setText(QString::number(a14));
           break;

       default:
           Unit2Display->setText(" Check Case No: ");
    }
}
void ConversionCalculator::Convert8Pressed(){
    int  a = UnitDispaly->text().toInt();
    double  b = Unit1Display->text().toDouble();
    double a1,a2,a3,a4;
    switch(a){
        case 1:
             a1 = b*0.0174533;
            Unit2Display->setText(QString::number(a1));
            break;
        case 2:
             a2 =b*57.29;
            Unit2Display->setText(QString::number(a2));
            break;
        case 3:
            a3 = b/0.0174533;
           Unit2Display->setText(QString::number(a3));
           break;
       case 4:
            a4= b/57.29;
           Unit2Display->setText(QString::number(a4));
           break;
           default:
           Unit2Display->setText(" Check Case No: ");
   }
}
void ConversionCalculator::Convert9Pressed(){
    double  b = rect1->text().toDouble();
    double  c = rect2->text().toDouble();
    double  d = rect3->text().toDouble();
    double  e = pol1->text().toDouble();
    double  f = pol2->text().toDouble();
    double  g = cylin1->text().toDouble();
    double  h = cylin2->text().toDouble();
    double  i = cylin3->text().toDouble();
    double  j = sph1->text().toDouble();
    double  k = sph2->text().toDouble();
    double  l = sph3->text().toDouble();
    double r     = sqrt(b*b + c*c);
    double theta = atan(c/b);
    double rho   = sqrt(b*b + c*c + d*d);
    double phi   = asin(rho/r);
    double x     = e * cos(f);
    double y     = e * sin(f);
    double z     = 0.0;
    double phi2  = 90;
    double x3    = g* cos(h);
    double y3    = g* sin(h);
    double rho2  = sqrt(g*g +i*i);
    double phi3  = asin(rho2/g);
    double r2    = j* sin(k);
    double x2    = r2 * cos(l);
    double y2    = r2 * sin (l);
    double z2    = j  * cos(k);
    pol1->setReadOnly(false);
    pol2->setReadOnly(false);
    cylin1->setReadOnly(false);
    cylin2->setReadOnly(false);
    cylin3->setReadOnly(false);
    sph1->setReadOnly(false);
    sph2->setReadOnly(false);
    sph3->setReadOnly(false);
    rect1->setReadOnly(false);
    rect2->setReadOnly(false);
    rect3->setReadOnly(false);

    if(b!=0 && c!=0 && d!=0){
        pol1->setText(QString::number(r));
        pol2->setText(QString::number(theta));
        cylin1->setText(QString::number(r));
        cylin2->setText(QString::number(theta));
        cylin3->setText(QString::number(d));
        sph1->setText(QString::number(rho));
        sph2->setText(QString::number(phi));
        sph3->setText(QString::number(theta));
        pol1->setReadOnly(true);
        pol2->setReadOnly(true);
        cylin1->setReadOnly(true);
        cylin2->setReadOnly(true);
        cylin3->setReadOnly(true);
        sph1->setReadOnly(true);
        sph2->setReadOnly(true);
        sph3->setReadOnly(true);
    }
    if(e!=0 && f!=0){
        rect1->setText(QString::number(x));
        rect2->setText(QString::number(y));
        rect3->setText(QString::number(z));
        cylin1->setText(QString::number(e));
        cylin2->setText(QString::number(f));
        cylin3->setText(QString::number(z));
        sph1->setText(QString::number(e));
        sph2->setText(QString::number(phi2));
        sph3->setText(QString::number(f));
        rect1->setReadOnly(true);
        rect2->setReadOnly(true);
        rect3->setReadOnly(true);
        cylin1->setReadOnly(true);
        cylin2->setReadOnly(true);
        cylin3->setReadOnly(true);
        sph1->setReadOnly(true);
        sph2->setReadOnly(true);
        sph3->setReadOnly(true);
    }
    if(g!=0 && h!=0 && i!=0){
        pol1->setText(QString::number(g));
        pol2->setText(QString::number(h));
        rect1->setText(QString::number(x3));
        rect2->setText(QString::number(y3));
        rect3->setText(QString::number(i));
        sph1->setText(QString::number(rho2));
        sph2->setText(QString::number(phi3));
        sph3->setText(QString::number(h));
        pol1->setReadOnly(true);
        pol2->setReadOnly(true);
        rect1->setReadOnly(true);
        rect2->setReadOnly(true);
        rect3->setReadOnly(true);
        sph1->setReadOnly(true);
        sph2->setReadOnly(true);
        sph3->setReadOnly(true);
    }
    if(j!=0 && k!=0 && l!=0){
        pol1->setText(QString::number(r2));
        pol2->setText(QString::number(l));
        cylin1->setText(QString::number(r2));
        cylin2->setText(QString::number(l));
        cylin3->setText(QString::number(z2));
        rect1->setText(QString::number(x2));
        rect2->setText(QString::number(y2));
        rect3->setText(QString::number(z2));
        pol1->setReadOnly(true);
        pol2->setReadOnly(true);
        cylin1->setReadOnly(true);
        cylin2->setReadOnly(true);
        cylin3->setReadOnly(true);
        rect1->setReadOnly(true);
        rect2->setReadOnly(true);
        rect3->setReadOnly(true);
    }
}
void ConversionCalculator::savePressed(){
    double x = Unit2Display->text().toDouble();
    UnitDispaly->clear();
    Unit1Display->setText(QString::number(x));
    Unit2Display->clear();
}
void ConversionCalculator::clear1Pressed(){
    UnitDispaly->setText("");
    Unit2Display->setText("");
    Unit1Display->setText("");
}
void ConversionCalculator::clear2Pressed(){
    rect1->setText("");
    rect2->setText("");
    rect3->setText("");
    pol1->setText("");
    pol2->setText("");
    cylin1->setText("");
    cylin2->setText("");
    cylin3->setText("");
    sph1->setText("");
    sph2->setText("");
    sph3->setText("");
    pol1->setReadOnly(false);
    pol2->setReadOnly(false);
    cylin1->setReadOnly(false);
    cylin2->setReadOnly(false);
    cylin3->setReadOnly(false);
    sph1->setReadOnly(false);
    sph2->setReadOnly(false);
    sph3->setReadOnly(false);
    rect1->setReadOnly(false);
    rect2->setReadOnly(false);
    rect3->setReadOnly(false);
}
QWidget* ConversionCalculator::getConversionWidget(){
    return ConversionWin;
}
ConversionCalculator::~ConversionCalculator()
{

                delete UnitWin;
                delete TempWin;
                delete TimeWin;
                delete LengthWin;
                delete AreaWin;
                delete VolumeWin;
                delete MassWin;
                delete AngleWin;
                delete Co_ordWin;
                delete ConversionLayout;
                delete UnitLayout;
                delete TempLayout;
                delete TimeLayout;
                delete LengthLayout;
                delete AreaLayout;
                delete VolumeLayout;
                delete MassLayout;
                delete AngleLayout;
                delete Co_ordLayout;
                delete Unit;
                delete Temp;
                delete Time;
                delete Length;
                delete Area;
                delete Volume;
                delete Mass;
                delete Angle;
                delete Co_ord;
                delete clear;
                delete UnitDispaly;
                delete Unit1Display;
                delete Unit2Display;
                delete rect1;
                delete rect2;
                delete rect3;
                delete pol1;
                delete pol2;
                delete cylin1;
                delete cylin2;
                delete cylin3;
                delete sph1;
                delete sph2;
                delete sph3;
                delete SaveResult;
                delete Convert1;
                delete Convert2;
                delete Convert3;
                delete Convert4;
                delete Convert5;
                delete Convert6;
                delete Convert7;
                delete Convert8;
                delete Convert9;

                delete Chooselabel;
                delete infoLabel;
                delete info1Label;
                delete info2Label;
                delete UnitLabel;
                delete TempLabel;
                delete TimeLabel;
                delete LengthLabel;
                delete AreaLabel;
                delete VolumeLabel;
                delete MassLabel;
                delete AngleLabel;
                delete Co_ordLabel;
                delete info;
                delete info1;
                delete info2;
                delete info3;
                delete info4;
                delete info5;
                delete info6;
                delete info7;
                delete info8;
                delete info9;
                delete info10;
}
