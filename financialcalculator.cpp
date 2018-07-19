#include "financialcalculator.h"

FinancialCalculator::FinancialCalculator(QWidget *parent) : QMainWindow(parent){
    FinancialWindow  = new QWidget;
    FinancialLayout  = new QGridLayout;

    InterestText     = new QLineEdit;
    AmountText       = new QLineEdit;
    DepreciationText = new QLineEdit;
    Principle        = new QLineEdit;
    Rate             = new QLineEdit;
    Time             = new QLineEdit;
    CFrequency       = new QLineEdit;
    CompoundingFreqLabel = new QLabel("Compounding Frequency = ");

    RateLabel        = new QLabel ("Rate= ");
    TimeLabel        = new QLabel ("Time= ");
    PrincipleLabel   = new QLabel ("Principle= ");
    InterestLabel    = new QLabel ("Interest is Rs ");
    AmountLabel      = new QLabel ("Amount is Rs");
    DepreciationLabel= new QLabel ("Depreciation is Rs");

    SimpleInterest     = new Button ("Simple Interest") ;
    CompoundInterest   = new Button ("Compound Interest") ;
    Depreciation       = new Button ("Depreciation") ;
    Clear              = new Button ("Clear");

    CreateFinancialCalculatorWidget();
    FinancialWindow->setLayout(FinancialLayout);
}
QWidget* FinancialCalculator::getFinancialCalculatorWidget(){
    return FinancialWindow;
}
void FinancialCalculator::CreateFinancialCalculatorWidget(){
    FinancialLayout->addWidget(PrincipleLabel,0,0,1,1);
    FinancialLayout->addWidget(Principle,0,1,1,1);
    FinancialLayout->addWidget(RateLabel,0,2,1,1);
    FinancialLayout->addWidget(Rate,0,3,1,1);
    FinancialLayout->addWidget(TimeLabel,0,4,1,1);
    FinancialLayout->addWidget(Time,0,5,1,1);

    FinancialLayout->addWidget(CompoundingFreqLabel,1,1,1,1);
    FinancialLayout->addWidget(CFrequency,1,2,1,1);

    FinancialLayout->addWidget(SimpleInterest,2,0,1,1);
    FinancialLayout->addWidget(CompoundInterest,2,1,1,1);
    FinancialLayout->addWidget(Depreciation,2,2,1,1);

    FinancialLayout->addWidget(InterestLabel,3,0,1,1);
    FinancialLayout->addWidget(InterestText,3,1,1,1);
    FinancialLayout->addWidget(DepreciationLabel,3,2,1,1);
    FinancialLayout->addWidget(DepreciationText,3,3,1,1);

    FinancialLayout->addWidget(AmountLabel,4,0,1,1);
    FinancialLayout->addWidget(AmountText,4,1,1,1);
    FinancialLayout->addWidget(Clear,4,3,1,1);

    Principle->setFixedHeight(40);
    Rate->setFixedHeight(40);
    Time->setFixedHeight(40);
    CFrequency->setFixedHeight(40);
    SimpleInterest->setFixedHeight(40);
    CompoundInterest->setFixedHeight(40);
    InterestText->setFixedHeight(40);
    DepreciationText->setFixedHeight(40);
    AmountText->setFixedHeight(40);

    CFrequency       ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    CompoundingFreqLabel  ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SimpleInterest  ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    CompoundInterest->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Depreciation->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    InterestText     ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    InterestLabel    ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    AmountText       ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    AmountLabel      ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    DepreciationText ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    DepreciationLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Principle        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    PrincipleLabel   ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Time             ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    TimeLabel        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Rate             ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    RateLabel        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Clear            ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    InterestText      ->setReadOnly(true);
    AmountText        ->setReadOnly(true);
    DepreciationText  ->setReadOnly(true);

    CFrequency        ->setStyleSheet("QLineEdit {font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; border: 1px solid black; background-color: white;}");
    Rate              ->setStyleSheet("QLineEdit {font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; border: 1px solid black; background-color: white;}");
    Time              ->setStyleSheet("QLineEdit {font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; border: 1px solid black; background-color: white;}");
    Principle         ->setStyleSheet("QLineEdit {font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; border: 1px solid black; background-color: white;}");
    InterestText      ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; border: 1px solid black; background-color: white;}");
    AmountText        ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; border: 1px solid black; background-color: white;}");
    DepreciationText  ->setStyleSheet("QLineEdit {font: 20pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; border: 1px solid black; background-color: white;}");
    Clear             ->setStyleSheet("QPushButton { font-size: 14px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    SimpleInterest    ->setStyleSheet("QPushButton { font-size: 14px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    CompoundInterest  ->setStyleSheet("QPushButton { font-size: 14px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    Depreciation      ->setStyleSheet("QPushButton { font-size: 14px; background-color:#FFE4C4; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF6347, stop: 1 #FFFFE0); }");
    InterestLabel     ->setStyleSheet("QLabel{font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; }");
    AmountLabel       ->setStyleSheet("QLabel{font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; }");
    DepreciationLabel ->setStyleSheet("QLabel{font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; }");
    PrincipleLabel    ->setStyleSheet("QLabel{font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; }");
    TimeLabel         ->setStyleSheet("QLabel{font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; }");
    RateLabel         ->setStyleSheet("QLabel{font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; }");
    CompoundingFreqLabel         ->setStyleSheet("QLabel{font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignLeft; padding: 5px; }");

    connect(SimpleInterest,SIGNAL(clicked()),this,SLOT(SimpleInterestPressed()));
    connect(CompoundInterest,SIGNAL(clicked()),this,SLOT(CompoundInterestPressed()));
    connect(Depreciation,SIGNAL(clicked()),this,SLOT(DepreciationPressed()));
    connect(Clear,SIGNAL(clicked()),this,SLOT(clearPressed()));
}
void FinancialCalculator :: SimpleInterestPressed(){

    double p,t,r,i,a,n;
    p = Principle->text().toDouble();
    t = Time->text().toDouble();
    r = Rate->text().toDouble();
    if(CFrequency->text() == 0)
        n = 1;
    else
    n = CFrequency->text().toDouble();
    i = (p*t*r)/(n*100) ;
    a =  p +i ;
    InterestText ->setText(QString::number(i));
    AmountText   ->setText(QString::number(a));
}
void FinancialCalculator::CompoundInterestPressed(){
    double cp ,ct ,cn ,cr ,ci, ca;
    cp = Principle->text().toDouble();
    ct = Time->text().toDouble();
    cr = Rate->text().toDouble();
    if(CFrequency->text() == 0)
        cn =1;
    else
    cn = CFrequency->text().toDouble();
    ca = cp * pow( (1 + (cr/(100*cn))), cn*ct );
    ci = ca-cp;
    InterestText->setText(QString::number(ci));
    AmountText  ->setText(QString::number(ca));
}
void FinancialCalculator::DepreciationPressed(){
    double dp, dr , dn, dt, da;
    dp = Principle->text().toDouble();
    dt = Time->text().toDouble();
    dr = Rate->text().toDouble();
    if(CFrequency->text() == 0)
        dn =1;
    else
    dn = CFrequency->text().toDouble();
    da = dp* pow((1-(dr/(dn*100))),dt);
    DepreciationText ->setText(QString :: number (da));
}
void FinancialCalculator::clearPressed(){
    Principle       ->clear();
    Rate            ->clear();
    Time            ->clear();
    InterestText    ->clear();
    AmountText      ->clear();
    DepreciationText->clear();
    CFrequency      ->clear();
}
FinancialCalculator::~FinancialCalculator(){
    qDebug()<<"Financial Destructor running";

    delete InterestText;
    delete AmountText;
    delete DepreciationText;
    delete Principle;
    delete Rate;
    delete Time;
    delete CFrequency;

    delete CompoundingFreqLabel;
    delete RateLabel;
    delete TimeLabel;
    delete PrincipleLabel;
    delete InterestLabel;
    delete AmountLabel;
    delete DepreciationLabel;

    delete SimpleInterest;
    delete CompoundInterest;
    delete Depreciation;
    delete Clear;

    delete FinancialLayout;
    delete FinancialWindow;
}
