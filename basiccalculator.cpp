#include "basiccalculator.h"

BasicCalculator::BasicCalculator(QWidget *parent) : QMainWindow(parent){
  qDebug() << "Basic Calculator Created." ;


  mainWidget = new QWidget;
  mainLayout = new QGridLayout;

  CreateBasicCalcWidget();
  CreateDisplayTextWidget();
  // layout set
  mainLayout->addWidget(displayWidget,0,0,1,1);
  mainLayout->addWidget(basicCalcWidget,1,0,1,1);
  qApp->installEventFilter(this);

  mainWidget->setLayout(mainLayout);
}
QWidget* BasicCalculator::getCalculatorWidget() {
    return mainWidget;
}
void BasicCalculator::CreateBasicCalcWidget() {
    for(int i=0;i<10;i++){
        QString s= QString::number(i);
        btn[i] = new Button(s);
    }
    btnDot         = new Button(".");
    btnEquals      = new Button("=");
    btnDiv         = new Button("/");
    btnMul         = new Button("*" );
    btnPlus        = new Button("+");
    btnMinus       = new Button("-");
    btnbksp        = new Button( QString::fromUtf8("\u21d0") );
    btnC           = new Button("C");
    btnPercent     = new Button("%");
    btnPlusMinus   = new Button( QString::fromUtf8("\u00B1") );


    // Step 1: create widgets (buttons)
    QString setStyleSheetNumbers = "QPushButton { font-size: 48px;border: 2px solid #f7f7f7; } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa); }";
    QString setStyleSheetClear = "QPushButton { font-size: 48px; background-color: rgb(215, 215, 215); border: 2px solid #f7f7f7; } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7); }";
    QString setStyleSheetSigns = "QPushButton { font-size: 48px;background-color: #6600CC; color: #f7f7f7; border: 2px solid #f7f7f7; } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #7F00FF, stop: 1 #9933FF); }";
    QString setStyleSheetBackSpace = "QPushButton { font-size: 48px;background-color: #6600CC; color: #f7f7f7; border: 2px solid #f7f7f7; } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #7F00FF, stop: 1 #9933FF); }";

    for(int i=0;i<10;i++){
        btn[i]->setStyleSheet(setStyleSheetNumbers);

    }

    btnDiv->setStyleSheet(setStyleSheetSigns);
    btnMul->setStyleSheet(setStyleSheetSigns);
    btnPlus->setStyleSheet(setStyleSheetSigns);
    btnMinus->setStyleSheet(setStyleSheetSigns);
    btnEquals->setStyleSheet(setStyleSheetSigns);
    btnPlusMinus->setStyleSheet(setStyleSheetClear);

    btnDot->setStyleSheet(setStyleSheetClear);

    btnC->setStyleSheet(setStyleSheetClear);
    btnPercent->setStyleSheet(setStyleSheetClear);

    btnbksp->setStyleSheet(setStyleSheetBackSpace);

    for(int i=0;i<10;i++){
        btn[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    }

    btnDot->setSizePolicy(      QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnEquals->setSizePolicy(   QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnDiv->setSizePolicy(      QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnMul->setSizePolicy(      QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnPlus->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnMinus->setSizePolicy(    QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnbksp->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnC->setSizePolicy(        QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnPercent->setSizePolicy(  QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnPlusMinus->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    btnPlus->setCheckable(true);
    btnMinus->setCheckable(true);
    btnMul->setCheckable(true);
    btnDiv->setCheckable(true);


    // Step 2: Create basic_calculator layout
    basicLayout = new QGridLayout;
    basicLayout->setSpacing(0);
    basicLayout->setContentsMargins(0,0,0,0);


    // Step 3: Add widgets to basic_calculator layout

    basicLayout->addWidget(btnC,   0,0,1,1);
    basicLayout->addWidget(btnPercent,0,1,1,1);
    basicLayout->addWidget(btnbksp, 0,2,1,1);
    basicLayout->addWidget(btnDiv,  0,3,1,1);

    basicLayout->addWidget(btnMul,1,3,1,1);
    for(int i=1;i<5;i++){
        for(int j=0;j<3;j++){
                if(i==1){
                    basicLayout->addWidget(btn[j+7],i,j,1,1);
                }else if(i==2){
                    basicLayout->addWidget(btn[j+4],i,j,1,1);
                }else if(i==3){
                    basicLayout->addWidget(btn[j+1],i,j,1,1);
                }else{
                    basicLayout->addWidget(btn[0],i,j+1,1,1);
                    break;
                }
        }
    }


    basicLayout->addWidget(btnPlus,2,3,1,1);
    basicLayout->addWidget(btnMinus,3,3,1,1);
    basicLayout->addWidget(btnPlusMinus,4,0,1,1);
    basicLayout->addWidget(btnDot,4,2,1,1);
    basicLayout->addWidget(btnEquals,4,3,1,1);

    // Step 4; Create basic calculator widget
    basicCalcWidget = new QWidget;

    // Step 5: Add basic calculator layout to baisc calculator widget
    basicCalcWidget->setLayout(basicLayout);

    // Step 6: Create slots and QObject::connect to button
    for(int i=0;i<10;i++){
        QObject::connect(btn[i],SIGNAL(clicked()),this,SLOT(numberPressed()));
    }


    QObject::connect(btnDot,SIGNAL(clicked()),      this,SLOT(decimalPressed()));
    QObject::connect(btnPlusMinus,SIGNAL(clicked()),this,SLOT(unaryOperatorPressed()));
    QObject::connect(btnPercent,SIGNAL(clicked()),  this,SLOT(unaryOperatorPressed()));
    QObject::connect(btnC,SIGNAL(clicked()),        this,SLOT(clearPressed()));

    QObject::connect(btnPlus,SIGNAL(clicked()),     this,SLOT(binaryOperatorPressed()));
    QObject::connect(btnMinus,SIGNAL(clicked()),    this,SLOT(binaryOperatorPressed()));
    QObject::connect(btnMul,SIGNAL(clicked()),      this,SLOT(binaryOperatorPressed()));
    QObject::connect(btnDiv,SIGNAL(clicked()),      this,SLOT(binaryOperatorPressed()));

    QObject::connect(btnbksp,SIGNAL(clicked()),     this,SLOT(bkspPressed()));
    QObject::connect(btnEquals,SIGNAL(clicked()),   this,SLOT(equalsPressed()));

}

void BasicCalculator::CreateDisplayTextWidget() {\

    QString StyleSheetLine = "QLineEdit {font: 26pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: none; background-color: #EFEFEF;}";

    /*** Step 1: Create widgets(elements) btns, textfields, etc ***/
    display = new QLineEdit;

    display->setStyleSheet(StyleSheetLine);

    /*** Step 2: Create layout ***/
    displayTextLayout = new QGridLayout;

    /*** Step 3: Add widgets(1) to layout(2) ***/
    displayTextLayout->addWidget(display,0,0,2,3);

    /*** Step 4: Create new Widget ***/
    displayWidget = new QWidget;

    /*** Step 5: Set layout(2) on widget(4) ***/
    displayWidget->setLayout( displayTextLayout );

    /*** Step 6: Set Slots ***/
}
void BasicCalculator::numberPressed(){
    QPushButton *Button = (QPushButton*)sender();//https://doc.qt.io/archives/qq/qq10-signalmapper.html
    QString displayNumber = Button->text();

    display->setText(display->text() + displayNumber);
}


void BasicCalculator::decimalPressed(){
    display->setText(display->text()+".");
}
void BasicCalculator::unaryOperatorPressed(){
    QPushButton *Button = (QPushButton*)sender();
    double displayNumber;
    QString newDisplay;
    if(Button->text()==QString::fromUtf8("\u00B1")){
        displayNumber=display->text().toDouble();
        displayNumber=displayNumber*(-1);
        newDisplay =  QString::number(displayNumber,'g',16);
        display->setText(newDisplay);
    }
    if(Button->text()=="%"){
        displayNumber=display->text().toDouble();
        displayNumber=displayNumber*0.01;
        newDisplay =  QString::number(displayNumber,'g',16);
        display->setText(newDisplay);
    }
}
void BasicCalculator::clearPressed(){
    QString Button = ((QPushButton*)sender())->text(); //https://doc.qt.io/archives/qq/qq10-signalmapper.html
    display->clear();
}
void BasicCalculator::binaryOperatorPressed(){
    QPushButton *Button = (QPushButton*)sender();
    QString newDisplay;
    newDisplay=display->text();
    if(Button->text()=="+"){
        newDisplay+="+";
        display->setText(newDisplay);
    }
    else if(Button->text()=="-"){
        newDisplay+="-";
        display->setText(newDisplay);
    }
    else if(Button->text()=="*"){
        newDisplay+="*";
        display->setText(newDisplay);
    }
    else if(Button->text()=="/"){
        newDisplay+="/";
        display->setText(newDisplay);
    }
}
void BasicCalculator::equalsPressed(){
    std::string displayText;
    displayText = display->text().toStdString();
    display->setText(QString::fromStdString(processSum(processArithmetic(processFunctions(strtolower(displayText))))));
}
void BasicCalculator::bkspPressed(){
    QString newDisplay;
    newDisplay= display->text();
    if(newDisplay.size()>0){
        newDisplay.resize(newDisplay.size()-1);
        display->setText(newDisplay);
    }
}
bool BasicCalculator::eventFilter(QObject *obj, QEvent *event){
    if (obj == display && event->type() == QEvent::KeyPress)
        {
            QKeyEvent *key = static_cast<QKeyEvent *>(event);
            QString setStyleSheetNumbers = "font-size: 48px;border: 2px solid #f7f7f7;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa); ";
            QString setStyleSheetSigns = "font-size: 48px;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #7F00FF, stop: 1 #9933FF);";
            QString setStyleSheetClear = "font-size:50px;qalignment:AlignCenter;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);";

//            qDebug()<<key->key();
            switch (key->key()) {
                case 46:
                    btnDot->setStyleSheet(setStyleSheetClear);
                    break;

                case 48://for 0
                    btn[0]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 49://for 1
                    btn[1]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 50://for 2
                    btn[2]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 51://for 3
                    btn[3]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 52://for 4
                    btn[4]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 53://for 5
                    btn[5]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 54://for 6
                    btn[6]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 55://for 7
                    btn[7]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 56://for 8
                    btn[8]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 57://for 9
                    btn[9]->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 47://for /
                    btnDiv->setStyleSheet(setStyleSheetSigns);
                    break;
                case 42://for *
                    btnMul->setStyleSheet(setStyleSheetSigns);
                    break;
                case 43://for +
                    btnPlus->setStyleSheet(setStyleSheetSigns);
                    break;
                case 45://for -
                    btnMinus->setStyleSheet(setStyleSheetSigns);
                    break;
                case 16777220:
                case 16777221:
                     equalsPressed();
                    break;
                case 16777219:
                     btnbksp->setStyleSheet(setStyleSheetSigns);
                     break;
                default:
                   break;
               }
           }
    if(obj==display && event->type()==QEvent::KeyRelease)
        {
            QKeyEvent *key = static_cast<QKeyEvent *>(event);
            QString setStyleSheetNumbers = "font-size: 48px;border: 2px solid #f7f7f7;";
            QString setStyleSheetSigns = "font-size: 48px;background-color: #6600CC; color: #f7f7f7; border: 2px solid #f7f7f7;";
            QString setStyleSheetClear = "font-size: 48px; background-color: rgb(215, 215, 215); border: 2px solid #f7f7f7;";

            switch (key->key()) {
               case 46:
                    btnDot->setStyleSheet(setStyleSheetClear);
                break;
               case 48:
                   btn[0]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 49:
                   btn[1]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 50:
                   btn[2]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 51:
                   btn[3]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 52:
                   btn[4]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 53:
                   btn[5]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 54:
                   btn[6]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 55:
                   btn[7]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 56:
                   btn[8]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 57:
                   btn[9]->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 47:
                   btnDiv->setStyleSheet(setStyleSheetSigns);
                   break;
               case 42:
                   btnMul->setStyleSheet(setStyleSheetSigns);
                   break;
               case 43:
                   btnPlus->setStyleSheet(setStyleSheetSigns);
                   break;
               case 45:
                   btnMinus->setStyleSheet(setStyleSheetSigns);
                   break;
               case 16777219://for bksp
                   btnbksp->setStyleSheet(setStyleSheetSigns);
                   break;


               default:
                   break;
               }
    }
 return QObject::eventFilter(obj, event);

}
BasicCalculator::~BasicCalculator(){
    qDebug()<<"Basic Destructor running";
    delete display;



    for(int i=0;i<10;i++){
        delete btn[i];
    }

    delete btnDot;
    delete btnEquals;
    delete btnDiv;
    delete btnMul;
    delete btnPlus;
    delete btnMinus;
    delete btnbksp;
    delete btnC;
    delete btnPercent;
    delete btnPlusMinus;
    delete basicLayout;
    delete mainLayout;
    delete displayTextLayout;
    delete displayWidget;
    delete basicCalcWidget;
    delete mainWidget;
}
