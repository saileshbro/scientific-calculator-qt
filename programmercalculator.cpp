#include "programmercalculator.h"

ProgrammerCalculator::ProgrammerCalculator(QWidget *parent) : QMainWindow(parent){
    qDebug()<<"Programmer Calculator Created";
    programmerModeWindow    = new QWidget;
    programmerModeLayout    = new QGridLayout;
    btnGenerateFibonacci    = new Button("Generate Fibonacci");
    btnClear                = new Button("Clear");
    GeneratorDisplay        = new QTextEdit;
    GeneratorMaxDisplay     = new QLineEdit;
    Display                 = new QLineEdit("");
    btnCheckPalindrome      = new Button("Check Palindrome");
    btnCheckAms             = new Button("Check Armstrong");
    btnCheckPrefect         = new Button("Check Perfect");
    btnGeneratePrime        = new Button("Generate Prime");
    for(int i=0;i<4;i++){
        programmerConversionDisplay[i] = new QLineEdit;
        programmerConversionHeader[i] = new QLabel;
    }
    CreateProgrammerCalculatorWidget();
    programmerModeWindow->setLayout(programmerModeLayout);

}
QWidget* ProgrammerCalculator::getProgrammerCalculatorWidget(){
    return programmerModeWindow;
}
void ProgrammerCalculator::CreateProgrammerCalculatorWidget(){
    for(int i=0;i<4;i++){
        programmerConversionDisplay[i]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        programmerConversionHeader[i]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    }
    programmerConversionHeader[0]->setText("Decimal");
    programmerConversionHeader[1]->setText("Binary");
    programmerConversionHeader[2]->setText("Hexadecimal");
    programmerConversionHeader[3]->setText("Octal");

    programmerModeLayout->addWidget(GeneratorDisplay,0,0,1,5);
    programmerModeLayout->addWidget(GeneratorMaxDisplay,1,2);
    programmerModeLayout->addWidget(btnGeneratePrime,1,3);
    programmerModeLayout->addWidget(btnGenerateFibonacci,1,4);


    programmerModeLayout->addWidget(Display,2,0,1,5);
    programmerModeLayout->addWidget(btnCheckPalindrome,3,1);
    programmerModeLayout->addWidget(btnCheckAms,3,2);
    programmerModeLayout->addWidget(btnCheckPrefect,3,3);
    programmerModeLayout->addWidget(btnClear,3,4);
    for(int i=0;i<4;i++){
        programmerModeLayout->addWidget(programmerConversionHeader[i],4,i+1);

    }
    for(int i=0;i<4;i++){
        programmerModeLayout->addWidget(programmerConversionDisplay[i],5,i+1);
    }

    btnGenerateFibonacci->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    GeneratorDisplay->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    GeneratorMaxDisplay->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnCheckPalindrome->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    Display-> setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    Display-> setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnCheckPalindrome->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnClear->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnCheckAms->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnCheckPrefect->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnGeneratePrime->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    GeneratorDisplay->setReadOnly(true);
    btnCheckAms->setFixedHeight(40);
    btnCheckPalindrome->setFixedHeight(40);
    btnCheckPrefect->setFixedHeight(40);
    btnClear->setFixedHeight(40);
    GeneratorDisplay->setStyleSheet("QTextEdit {font: 12pt 'Microsoft YaHei UI'; padding: 5px; border: 1px solid black; background-color: white;}");
    GeneratorMaxDisplay->setStyleSheet("QLineEdit {font: 24pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    Display->setStyleSheet("QLineEdit {font: 28pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
    btnCheckAms->setStyleSheet("QPushButton { font-size: 16px; background-color:#00DD5C; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7); }");
    btnClear->setStyleSheet("QPushButton { font-size: 16px; background-color:#00DD5C; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7); }QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7); }");
    btnCheckPalindrome->setStyleSheet("QPushButton { font-size: 16px; background-color:#00DD5C; border: 2px solid #f7f7f7; border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7); }");
    btnCheckPrefect->setStyleSheet("QPushButton { font-size: 16px; background-color:#00DD5C; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7); }");
    btnGenerateFibonacci->setStyleSheet("QPushButton { font-size: 16px; background-color:#00DD5C; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7); }");
    btnGeneratePrime->setStyleSheet("QPushButton { font-size: 16px; background-color:#00DD5C; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7); }");

    for(int i=0;i<4;i++){
        programmerConversionDisplay[i]->setStyleSheet("QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 1px solid black; background-color: white;}");
        programmerConversionHeader[i]->setStyleSheet("QLabel{font: 14pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCenter; padding: 2px;}");
    }

    connect(programmerConversionDisplay[0],SIGNAL(textEdited(QString)),this,SLOT(convertFromDecimal()));
    connect(programmerConversionDisplay[1],SIGNAL(textEdited(QString)),this,SLOT(convertFromBinary()));
    connect(programmerConversionDisplay[2],SIGNAL(textEdited(QString)),this,SLOT(convertFromHexa()));
    connect(programmerConversionDisplay[3],SIGNAL(textEdited(QString)),this,SLOT(convertFromOctal()));


    connect(btnClear,SIGNAL(clicked()),this,SLOT(onClearPressed()));
    connect(btnGenerateFibonacci,SIGNAL(clicked()),this,SLOT(onGeneratePressed()));
    connect(btnCheckPalindrome,SIGNAL(clicked()),this,SLOT(onCheckPalindromePressed()));
    connect(btnCheckAms,SIGNAL(clicked()),this,SLOT(onCheckArmsPressed()));
    connect(btnCheckPrefect,SIGNAL(clicked()),this,SLOT(onCheckPerfectPressed()));
    connect(btnGeneratePrime,SIGNAL(clicked()),this,SLOT(onGeneratePressed()));

    GeneratorDisplay->setAlignment(Qt::AlignHCenter);
    GeneratorDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
void ProgrammerCalculator::onClearPressed(){
    GeneratorDisplay->clear();
    GeneratorMaxDisplay->clear();
    Display->setReadOnly(false);
    for(int i=0;i<4;i++){
        programmerConversionDisplay[i]->clear();
    }
    Display->clear();

}
void ProgrammerCalculator::onGeneratePressed(){
    QPushButton* button = (QPushButton*)sender();
    QString text=button->text();
    if(text=="Generate Fibonacci"){
    unsigned long long int x1=-1,x2=1,n=GeneratorMaxDisplay->text().toInt();
    QString  s;
    for(unsigned long long int i=0;i<n;i++){
        unsigned long long int temp=x1+x2;
        s.append(QString::number(temp)+" ");

        x1=x2;
        x2=temp;
    }
//WE NEED TO RESOLVE THE STRING LENGTH ERROR
    GeneratorDisplay->setText(s);
    //GeneratorDisplay->scroll(5,0);
    GeneratorMaxDisplay->clear();
    }
    if(text=="Generate Prime"){
        long long int n,num=1,primeCount=0;
        QString s;
        n=GeneratorMaxDisplay->text().toInt();
        GeneratorMaxDisplay->clear();
        //s.append(QString::number(1)+" ");
        for(int i=2;i<=n;i++){
            num++;
            primeCount=0;
            for(long long int j=1;j<=num;j++){
                if(num%j==0){
                    primeCount++;
                }
            }
            if(primeCount==2)
                s.append(QString::number(i)+" ");
        }
        GeneratorDisplay->setText(s);
    }
}
void ProgrammerCalculator::onCheckPalindromePressed(){
    std::string str1= Display->text().toStdString();
    std::string str2 = reversestr(str1);
    if(str1==str2){
        Display->setText("It's a palindrome.");
    }
    else
        Display->setText("It's not a palindrome.");
}
void ProgrammerCalculator::onCheckPerfectPressed(){
    if(Display->text()==""||Display->text().toInt()==0){
       Display->setText("Enter a number first.");
    }
    else{
            unsigned long long n1 = Display->text().toULongLong();
            unsigned long long  i, sum, num;
            sum = 0;
            num = n1;
            for(i=1; i<num; i++)
            {
                /* If i is a divisor of n1 */
                if(num%i == 0)
                {
                 sum += i;
                }
            }
       if(n1 == sum)
           Display->setText("It's a perect number.");
       else
           Display->setText("It's not a perfect number.");
    }
}
void ProgrammerCalculator::onCheckArmsPressed(){
    if(Display->text()==""||Display->text().toInt()==0)
        Display->setText("Enter a number first.");
    else{
    long long int   sum=0, a;
    a = Display->text().toLongLong();
    while(a!=0){
        sum += pow(a%10,3);
        a/=10;
        }
    if(sum==Display->text().toLongLong()){
      Display->setText("Armstrong Number");
    }
    else
        Display->setText("Not an Armstrong Number");
    }
}

void ProgrammerCalculator::convertFromDecimal(){
    programmerConversionDisplay[1]->setText(QString::fromStdString(decToBin(programmerConversionDisplay[0]->text().toStdString())));
    programmerConversionDisplay[2]->setText(QString::fromStdString(decToHex(programmerConversionDisplay[0]->text().toStdString())));
    programmerConversionDisplay[3]->setText(QString::fromStdString(decToOct(programmerConversionDisplay[0]->text().toStdString())));
}
void ProgrammerCalculator::convertFromBinary(){
    programmerConversionDisplay[0]->setText(QString::fromStdString(binToDec(programmerConversionDisplay[1]->text().toStdString())));
    programmerConversionDisplay[2]->setText(QString::fromStdString(binToHex(programmerConversionDisplay[1]->text().toStdString())));
    programmerConversionDisplay[3]->setText(QString::fromStdString(binToOct(programmerConversionDisplay[1]->text().toStdString())));
}
void ProgrammerCalculator::convertFromHexa(){
    programmerConversionDisplay[0]->setText(QString::fromStdString(hexToDec(programmerConversionDisplay[2]->text().toStdString())));
    programmerConversionDisplay[1]->setText(QString::fromStdString(decToBin(programmerConversionDisplay[0]->text().toStdString())));
    programmerConversionDisplay[3]->setText(QString::fromStdString(decToOct(programmerConversionDisplay[0]->text().toStdString())));

}
void ProgrammerCalculator::convertFromOctal(){
    programmerConversionDisplay[0]->setText(QString::fromStdString(octToDec(programmerConversionDisplay[3]->text().toStdString())));
    programmerConversionDisplay[1]->setText(QString::fromStdString(decToBin(programmerConversionDisplay[0]->text().toStdString())));
    programmerConversionDisplay[2]->setText(QString::fromStdString(decToHex(programmerConversionDisplay[0]->text().toStdString())));
}
ProgrammerCalculator::~ProgrammerCalculator(){
    qDebug()<<"Programmer Destructor Running";
    delete btnClear;


    delete btnGenerateFibonacci;
    delete btnGeneratePrime;

    delete GeneratorDisplay;
    delete GeneratorMaxDisplay;


    delete btnCheckPrefect;
    delete btnCheckAms;


    delete Display;
    delete btnCheckPalindrome;

    for(int i=0;i<4;i++){
        delete programmerConversionHeader[i];
        delete programmerConversionDisplay[i];
    }
    delete programmerModeLayout;
    delete programmerModeWindow;
}
