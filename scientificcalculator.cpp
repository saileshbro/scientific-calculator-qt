#include "scientificcalculator.h"
#include <QKeyEvent>

ScientificCalculator::ScientificCalculator(QWidget *parent) : QMainWindow(parent){
    ScientificWidget  = new QWidget;
    ScientificLayout  = new QGridLayout;
    qApp->installEventFilter(this);
    CreateScientificCalculatorWidget();
    ScientificWidget->setLayout(ScientificLayout);

}
QWidget* ScientificCalculator::getScientificCalculator(){
    return ScientificWidget;
}
void ScientificCalculator::CreateScientificCalculatorWidget() {
    // step 1:create scientific layout
    btn0           = new Button("0");
    btn1           = new Button("1");
    btn2           = new Button("2");
    btn3           = new Button("3");
    btn4           = new Button("4");
    btn5           = new Button("5");
    btn6           = new Button("6");
    btn7           = new Button("7");
    btn8           = new Button("8");
    btn9           = new Button("9");
    btnsin         = new Button("sin");
    btncos         = new Button("cos");
    btntan         = new Button("tan");
    btnsininv      = new Button("sin-1");
    btncosinv      = new Button("cos-1");
    btntaninv      = new Button("tan-1");
    btnsinh        = new Button("sinh");
    btncosh        = new Button("cosh");
    btntanh        = new Button("tanh");
    btnsinhinv     = new Button("sinh-1");
    btncoshinv     = new Button("cosh-1");
    btntanhinv     = new Button("tanh-1");
    btne           = new Button("e");
    btnxpown       = new Button("x"+QString::fromUtf8("\u207f"));
    btnxpow2       = new Button("x"+QString::fromUtf8("\u00b2"));
    btnxpow3       = new Button("x"+QString::fromUtf8("\u00b3"));
    btnpowneg1     = new Button("x^-1");
    btnlog         = new Button("log");
    btnln          = new Button("ln");
    btnxfact       = new Button("x!");
    btnroot        = new Button("x"+QString::fromUtf8("\u00bd"));
    btncubicroot   = new Button("x^(1/3)");
    btnDot         = new Button(".");
    btnEquals      = new Button("=");
    btnDiv         = new Button("/");
    btnMul         = new Button("*" );
    btnPlus        = new Button("+");
    btnMinus       = new Button("-");
    btnbksp        = new Button( QString::fromUtf8("\u21b6") );
    btnC           = new Button("C");
    btnPercent     = new Button("%");
    btnPlusMinus   = new Button( QString::fromUtf8("\u00B1") );
    btnpi          = new Button(QString::fromUtf8("\u03c0"));
    btnbrkt        = new Button("()");
    btndel          = new Button("CE");
    display         = new QLineEdit;
    display->setFixedHeight(100);

    btnbrkt->setCheckable(true);
    btnbrkt->setChecked(false);
    // step 4:add widget to layout
    ScientificLayout->addWidget(display,0,0,1,9);
    ScientificLayout->addWidget(btn0,5,6,1,1);
    ScientificLayout->addWidget(btn1,4,5,1,1);
    ScientificLayout->addWidget(btn2,4,6,1,1);
    ScientificLayout->addWidget(btn3,4,7,1,1);
    ScientificLayout->addWidget(btn4,3,5,1,1);
    ScientificLayout->addWidget(btn5,3,6,1,1);
    ScientificLayout->addWidget(btn6,3,7,1,1);
    ScientificLayout->addWidget(btn7,2,5,1,1);
    ScientificLayout->addWidget(btn8,2,6,1,1);
    ScientificLayout->addWidget(btn9,2,7,1,1);
    ScientificLayout->addWidget(btnsin,1,2,1,1);
    ScientificLayout->addWidget(btncos,1,3,1,1);
    ScientificLayout->addWidget(btntan,1,4,1,1);
    ScientificLayout->addWidget(btnsininv,2,2,1,1);
    ScientificLayout->addWidget(btncosinv,2,3,1,1);
    ScientificLayout->addWidget(btntaninv,2,4,1,1);
    ScientificLayout->addWidget(btnsinh,3,2,1,1);
    ScientificLayout->addWidget(btncosh,3,3,1,1);
    ScientificLayout->addWidget(btntanh,3,4,1,1);
    ScientificLayout->addWidget(btnsinhinv,4,2,1,1);
    ScientificLayout->addWidget(btncoshinv,4,3,1,1);
    ScientificLayout->addWidget(btntanhinv,4,4,1,1);
    ScientificLayout->addWidget(btne,4,1,1,1);
    ScientificLayout->addWidget(btnxpown,1,1,1,1);
    ScientificLayout->addWidget(btnxpow2,1,0,1,1);
    ScientificLayout->addWidget(btnxpow3,2,1,1,1);
    ScientificLayout->addWidget(btnpowneg1,2,0,1,1);
    ScientificLayout->addWidget(btnlog,5,3,1,1);
    ScientificLayout->addWidget(btnln,5,2,1,1);
    ScientificLayout->addWidget(btnxfact,3,1,1,1);
    ScientificLayout->addWidget(btnroot,3,0,1,1);
    ScientificLayout->addWidget(btncubicroot,4,0,1,1);
    ScientificLayout->addWidget(btnDot,5,7,1,1);
    ScientificLayout->addWidget(btnEquals,5,8,1,1);
    ScientificLayout->addWidget(btnMinus,3,8,1,1);
    ScientificLayout->addWidget(btnMul,2,8,1,1);
    ScientificLayout->addWidget(btnDiv,1,8,1,1);
    ScientificLayout->addWidget(btnbksp,1,7,1,1);
    ScientificLayout->addWidget(btnPlus,4,8,1,1);
    ScientificLayout->addWidget(btnPlusMinus,5,5,1,1);
    ScientificLayout->addWidget(btnC,1,6,1,1);
    ScientificLayout->addWidget(btnPercent,5,0,1,1);
    ScientificLayout->addWidget(btnpi,5,1,1,1);
    ScientificLayout->addWidget(btndel,1,5,1,1);
    ScientificLayout->addWidget(btnbrkt,5,4,1,1);


    btn0->setStyleSheet("QPushButton {color:#333333;padding:10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btn1->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btn2->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btn3->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btn4->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btn5->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btn6->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btn7->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btn8->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btn9->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnsin->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9; border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btncos->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btntan->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnsininv->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btncosinv->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btntaninv->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnsinh->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btncosh->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color:#A9A9A9; }");
    btntanh->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnsinhinv->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btncoshinv->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btntanhinv->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#e9e9e9;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btne->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnxpown->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnxpow2->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnxpow3->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnpowneg1->setStyleSheet("QPushButton {color:#333333; padding: 10px 20px;font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnlog->setStyleSheet("QPushButton {color:#333333; padding: 10px 20px;font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnln->setStyleSheet("QPushButton { color:#333333;padding: 10px 20px;font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color:  #A9A9A9; }");
    btnxfact->setStyleSheet("QPushButton {color:#333333; padding: 10px 20px;font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnroot->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btncubicroot->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 20px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnDot->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnDiv->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3; border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnPlus->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3; border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnPlusMinus->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnMinus->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3; border-radius:1px; } QPushButton:hover { background-color:#A9A9A9; }");
    btnMul->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnPercent->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3; border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnC->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3;  border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btndel->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnEquals->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3; border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnpi->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3; border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnbksp->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 40px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    btnbrkt->setStyleSheet("QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3;border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }");
    display->setStyleSheet("QLineEdit {font: 26pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: none; background-color: #EFEFEF;}");


    btn0        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn1        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn2        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn3        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn4        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn5        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn6        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn7        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn8        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn9        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnsin      ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btncos      ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btntan      ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnsininv       ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btncosinv       ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btntaninv       ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnsinh     ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btncosh     ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btntanh     ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnsinhinv      ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btncoshinv      ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btntanhinv      ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btne        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnxpown        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnxpow2        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnxpow3        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnpowneg1      ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnlog      ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnln       ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnxfact        ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnroot     ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btncubicroot    ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy:: Preferred);
    btnDot      ->setSizePolicy(      QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnEquals       ->setSizePolicy(   QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnDiv      ->setSizePolicy(      QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnMul      ->setSizePolicy(      QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnPlus     ->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnMinus        ->setSizePolicy(    QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnbksp     ->setSizePolicy(     QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnC        ->setSizePolicy(        QSizePolicy::Preferred, QSizePolicy::Preferred);
    btndel        ->setSizePolicy(        QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnPercent      ->setSizePolicy(  QSizePolicy::Preferred, QSizePolicy::Preferred);
    btnPlusMinus    ->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    // Step 5: Create slots and connect to button

    connect(btn0,SIGNAL(clicked()),this,SLOT( numberPressed() ));
    connect(btn1,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btn2,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btn3,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btn4,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btn5,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btn6,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btn7,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btn8,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btn9,SIGNAL(clicked()),this,SLOT(numberPressed()));


    connect(btnsin,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btncos,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btntan,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btnsininv,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btncosinv,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btntaninv,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btnsinh,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btncosh,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btntanh,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btnsinhinv,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btncoshinv,SIGNAL(clicked()),this,SLOT(numberPressed()));
    connect(btntanhinv,SIGNAL(clicked()),this,SLOT(numberPressed()));

    connect(btnDot,SIGNAL(clicked()),this,SLOT(decimalPressed()));
    connect(btnPlusMinus,SIGNAL(clicked()),this,SLOT(unaryOperatorPressed()));
    connect(btnPercent,SIGNAL(clicked()),this,SLOT(unaryOperatorPressed()));
    connect(btnC,SIGNAL(clicked()),this,SLOT(clearPressed()));

    connect(btnPlus,SIGNAL(clicked()),this,SLOT(binaryOperatorPressed()));
    connect(btnMinus,SIGNAL(clicked()),this,SLOT(binaryOperatorPressed()));
    connect(btnMul,SIGNAL(clicked()),this,SLOT(binaryOperatorPressed()));
    connect(btnDiv,SIGNAL(clicked()),this,SLOT(binaryOperatorPressed()));

    connect(btndel,SIGNAL(clicked()),this,SLOT(bkspPressed()));
    connect(btnEquals,SIGNAL(clicked()),this,SLOT(equalsPressed()));

    connect(btnbksp, SIGNAL(clicked()), this, SLOT(backPressed()));
    connect(btnbrkt,SIGNAL(clicked(bool)),this,SLOT(bracketPressed()));
    connect(btnxfact, SIGNAL(clicked()),this ,SLOT(unaryOperatorPressed()));
    connect(btnxpow2, SIGNAL(clicked()),this ,SLOT(unaryOperatorPressed()));
    connect(btnxpow3, SIGNAL(clicked()),this ,SLOT(unaryOperatorPressed()));
    connect(btncubicroot, SIGNAL(clicked()),this ,SLOT(unaryOperatorPressed()));
    connect(btnroot, SIGNAL(clicked()),this ,SLOT(unaryOperatorPressed()));
    connect(btnpowneg1, SIGNAL(clicked()),this ,SLOT(unaryOperatorPressed()));
    connect(btnxpown, SIGNAL(clicked()),this ,SLOT(unaryOperatorPressed()));
    connect(btnlog, SIGNAL(clicked()),this ,SLOT(unaryOperatorPressed()));
    connect(btnln, SIGNAL(clicked()),this ,SLOT(unaryOperatorPressed()));
    connect(btne,SIGNAL(clicked()),this,SLOT(unaryOperatorPressed()));
    connect(btnpi,SIGNAL(clicked()),this,SLOT(unaryOperatorPressed()));




}
bool ScientificCalculator::eventFilter(QObject *obj, QEvent *event){
    if (obj == display && event->type() == QEvent::KeyPress)
        {
            QKeyEvent *key = static_cast<QKeyEvent *>(event);
            QString setStyleSheetNumbers    = "background-color: #A9A9A9;font-size:35px;border:none;";
            QString setStyleSheetSigns      = "background-color: #A9A9A9;font-size:35px;border:none;";
            QString setStyleSheetClear      = "background-color: #A9A9A9;font-size:35px;border:none;";


//            qDebug()<<key->key();
            switch (key->key()) {
                case 46:
                    btnDot->setStyleSheet(setStyleSheetClear);
                    break;

                case 48://for 0
                    btn0->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 49://for 1
                    btn1->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 50://for 2
                    btn2->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 51://for 3
                    btn3->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 52://for 4
                    btn4->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 53://for 5
                    btn5->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 54://for 6
                    btn6->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 55://for 7
                    btn7->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 56://for 8
                    btn8->setStyleSheet(setStyleSheetNumbers);
                    break;
                case 57://for 9
                    btn9->setStyleSheet(setStyleSheetNumbers);
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
                     btndel->setStyleSheet(setStyleSheetSigns);
                     break;
                default:
                   break;
               }
           }
    if(obj==display && event->type()==QEvent::KeyRelease)
        {
            QKeyEvent *key = static_cast<QKeyEvent *>(event);
            QString setStyleSheetNumbers    = "QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#ffffff; border-radius:1px; }QPushButton:hover { background-color: #A9A9A9; }";
            QString setStyleSheetSigns      = "QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3; border-radius:1px; } QPushButton:hover { background-color: #A9A9A9; }";
            QString setStyleSheetClear      = "QPushButton {color:#333333;padding: 10px 20px; font-size: 35px; background-color:#D3D3D3; border-radius:1px; }QPushButton:hover { background-color: #A9A9A9; }";


            switch (key->key()) {
               case 46:
                    btnDot->setStyleSheet(setStyleSheetClear);
                break;
               case 48:
                   btn0->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 49:
                   btn1->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 50:
                   btn2->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 51:
                   btn3->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 52:
                   btn4->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 53:
                   btn5->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 54:
                   btn6->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 55:
                   btn7->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 56:
                   btn8->setStyleSheet(setStyleSheetNumbers);
                   break;
               case 57:
                   btn9->setStyleSheet(setStyleSheetNumbers);
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
                   btndel->setStyleSheet(setStyleSheetSigns);
                   break;


               default:
                   break;
               }
    }
 return QObject::eventFilter(obj, event);

}
ScientificCalculator::~ScientificCalculator(){}
void ScientificCalculator::numberPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString btnText = button->text();

    if(btnText.indexOf("h-") > 0){
        QString split = "a" + btnText.split("-")[0];
        display->setText(display->text()+split);
    } else if(btnText.indexOf("-") > 0){
        QString split = "arc" + btnText.split("-")[0];
        display->setText(display->text()+split);
        }
     else {
        display->setText( display->text()+button->text());
    }

}
void ScientificCalculator::decimalPressed(){
    // check if there is another dot
    numberPressed();
}
void ScientificCalculator::unaryOperatorPressed(){
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
    if(Button->text()=="x!"){
        if((display->text().toStdString()).find(".")!=-1 ||(display->text().toStdString()).find("-")!=-1){
            display->setText("Enter a positive integer number.");
        }else if((display->text().toStdString()).find(".")==-1 ||(display->text().toStdString()).find("-")==-1){
            unsigned long long s= getFactorial(display->text().toULongLong());
            display->setText(QString::fromStdString(std::to_string(s)));
        }
    }
    if(Button->text()=="x"+QString::fromUtf8("\u00b2")){
        if(display->text()==""){}
        else
        display->setText(QString::fromStdString(std::to_string((pow(std::stod(display->text().toStdString()),2)))));
    }
    if(Button->text()=="x"+QString::fromUtf8("\u00b3")){
        if(display->text()==""){}
        else
        display->setText(QString::fromStdString(std::to_string((pow(std::stod(display->text().toStdString()),3)))));
    }
    if(Button->text()=="x^-1"){
        if(display->text()==""){}
        else
        display->setText(QString::fromStdString(std::to_string(1/display->text().toDouble())));
    }
    if(Button->text()=="x"+QString::fromUtf8("\u00bd")){
        if(display->text()==""){}
        else
        display->setText(QString::fromStdString(std::to_string((sqrt(std::stod(display->text().toStdString()))))));
    }
    if(Button->text()=="x^(1/3)"){
        if(display->text()==""){}
        else
        display->setText(QString::fromStdString(std::to_string((cbrt(std::stod(display->text().toStdString()))))));
    }
    if(Button->text()=="()"){
        display->setText(display->text()+")");
    }
    if(Button->text()=="x"+QString::fromUtf8("\u207f")){
        if(display->text()==""){}
        else
            display->setText(display->text()+"^");
    }if(Button->text()=="log"){
        display->setText(display->text()+"log(");
    }if(Button->text()=="ln"){
        display->setText(display->text()+"ln(");
    }if(Button->text()=="e"){
        display->setText(display->text()+"2.7183");
    }if(Button->text()==QString::fromUtf8("\u03c0")){
        display->setText(display->text()+"3.14");
    }


}
void ScientificCalculator::clearPressed(){
    display->setText("");
}
void ScientificCalculator::binaryOperatorPressed(){
    // check if more bad binary symbol
    numberPressed();
}
void ScientificCalculator::equalsPressed(){
    QString text = display->text();

    std::ofstream writer(qApp->applicationDirPath().toStdString() + "/data/history.txt");

    writer << text.toStdString();

    writer.close();


    if (countOccurances(text.toStdString(),"(") != countOccurances(text.toStdString(),")")){
        return;
    }

    string exp = processSum(processArithmetic(processFunctions(strtolower(strip_spaces(text.toStdString())))));

    display->setText(QString::fromStdString(exp));}
void ScientificCalculator::backPressed(){
    std::ifstream reader(qApp->applicationDirPath().toStdString() + "/data/history.txt");

    std::string line;

    while(!reader.eof()){
       std::getline(reader,line);
    }

    reader.close();

    display->setText(QString::fromStdString(line));
}
void ScientificCalculator::trigonometricPressed(){
    QPushButton *btn = (QPushButton*)sender();
    if(btn->text()=="sin("){
        display->setText(display->text()+"sin(");
    }
    if(btn->text()=="cos("){
        display->setText(display->text()+"cos(");
    }
    if(btn->text()=="tan("){
        display->setText(display->text()+"tan(");
    }

}
void ScientificCalculator::bkspPressed() {
    QString text = display->text();
    if((countOccurances(text.toStdString(),"(") != countOccurances(text.toStdString(),")"))){
        display->setText(text+")");
    }
    else if((countOccurances(text.toStdString(),")") != countOccurances(text.toStdString(),"(")))
        display->setText(text+"(");
}
void ScientificCalculator::bracketPressed(){


}
//add default x^2 == 0 when no string is given
//same for others also
//add inverse trigo function
//fix conversion problem
//comlete scientific
//integrate formula mode and user manual and about page
//if pi found in the string then replace it with its value
//work CE
