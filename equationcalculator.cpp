#include "equationcalculator.h"

EquationCalculator::EquationCalculator(QWidget *parent):QMainWindow(parent){
    qDebug()<<"Equation Calculator Created";
    equationWindow  = new QWidget;
    equationLayout  = new QGridLayout;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++)
                        linearModeDisplay[i][j] = new QLineEdit;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++)
                        linearModeVariables[i][j] = new QLabel;
    }
    for(int i=0;i<3;i++){
        quadraticModeDisplay[i]=    new QLineEdit;
        if(i!=2)
            quadraticModeVariables[i]   = new QLabel;
    }
    btnSelectQuadratic  = new Button;
    btnSelectLinear     = new Button;
    headerLinear        = new QLabel("Linear");
    headerQuadratic     = new QLabel("Quadratic");
    equationDisplay     = new QLineEdit("");
    equationClear       = new Button("Clear");
    calculateLinear     = new Button("Calculate Linear");
    calculateQuadratic  = new Button("Calculate Quadratic");
    CreateEquationCalculatorWidget();

    equationWindow->setLayout(equationLayout);
}
QWidget* EquationCalculator::getEquationWidget(){
    return equationWindow;
}
void EquationCalculator::CreateEquationCalculatorWidget(){
    QString styleSheetEquationLabel = "QLabel{font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCentre;padding 5px;}";
    QString styleSheetEquationLabelHeader = "QLabel{font: 18pt 'Microsoft YaHei UI'; qproperty-alignment: AlignCentre;padding 5px;}";
    QString styleSheetEquationPushButtons= "QPushButton { font-size: 16px;padding:10px;text-align:center;background-color: #6600CC; color: #f7f7f7; border: 2px solid #f7f7f7; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #7F00FF, stop: 1 #9933FF); }";
    QString styleSheetEquationDisplay="QLineEdit {font: 10pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: none; background-color: white;}";


    headerLinear->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    headerQuadratic->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    equationDisplay->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    calculateLinear->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    calculateQuadratic->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    equationClear->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);


    equationDisplay->setReadOnly(true);
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){

            linearModeDisplay[i][j]->setText("0");
            //linearModeDisplay[i][j]->setFixedHeight(25);
            linearModeDisplay[i][j]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
            linearModeDisplay[i][j]->setStyleSheet(styleSheetEquationDisplay);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            //linearModeVariables[i][j]->setFixedHeight(25);
            linearModeVariables[i][j]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
            linearModeVariables[i][j]->setStyleSheet(styleSheetEquationLabel);
            if(j==0)
                linearModeVariables[i][j]->setText("  x + ");
            else if(j==1)
                linearModeVariables[i][j]->setText("  y + ");
            else
                linearModeVariables[i][j]->setText("   z = ");
        }
    }
    equationLayout->addWidget(headerLinear,0,2,1,1);

    for(int i=0;i<3;i++){
        quadraticModeDisplay[i] = new QLineEdit("0");
        //quadraticModeDisplay[i]->setFixedHeight(25);
        quadraticModeDisplay[i]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        quadraticModeDisplay[i]->setStyleSheet(styleSheetEquationDisplay);
        if(i<2){
            quadraticModeVariables[i]= new QLabel;
            //quadraticModeVariables[i]->setFixedHeight(25);
            quadraticModeVariables[i]->setStyleSheet(styleSheetEquationLabel);
            quadraticModeVariables[i]->setStyleSheet(styleSheetEquationLabel);
        }
    }
    quadraticModeVariables[0]->setText("   x"+QString::fromUtf8("\u00b2"));
    quadraticModeVariables[1]->setText("  x + ");


//====================linear========================================================
//=======================first row elements=========================
   equationLayout->addWidget(linearModeDisplay  [0][0],1,0,1,1);
   equationLayout->addWidget(linearModeVariables[0][0],1,1,1,1);
   equationLayout->addWidget(linearModeDisplay  [0][1],1,2,1,1);
   equationLayout->addWidget(linearModeVariables[0][1],1,3,1,1);
   equationLayout->addWidget(linearModeDisplay  [0][2],1,4,1,1);
   equationLayout->addWidget(linearModeVariables[0][2],1,5,1,1);
   equationLayout->addWidget(linearModeDisplay  [0][3],1,6,1,1);
//=========================Second row elements===========================
   equationLayout->addWidget(linearModeDisplay  [1][0],2,0,1,1);
   equationLayout->addWidget(linearModeVariables[1][0],2,1,1,1);
   equationLayout->addWidget(linearModeDisplay  [1][1],2,2,1,1);
   equationLayout->addWidget(linearModeVariables[1][1],2,3,1,1);
   equationLayout->addWidget(linearModeDisplay  [1][2],2,4,1,1);
   equationLayout->addWidget(linearModeVariables[1][2],2,5,1,1);
   equationLayout->addWidget(linearModeDisplay  [1][3],2,6,1,1);
//==========================Third row elements=====================================
   equationLayout->addWidget(linearModeDisplay  [2][0],3,0,1,1);
   equationLayout->addWidget(linearModeVariables[2][0],3,1,1,1);
   equationLayout->addWidget(linearModeDisplay  [2][1],3,2,1,1);
   equationLayout->addWidget(linearModeVariables[2][1],3,3,1,1);
   equationLayout->addWidget(linearModeDisplay  [2][2],3,4,1,1);
   equationLayout->addWidget(linearModeVariables[2][2],3,5,1,1);
   equationLayout->addWidget(linearModeDisplay  [2][3],3,6,1,1);


   equationLayout->addWidget(headerQuadratic,4,2,1,1);
   //=============================Quadratic======================================
   //======================================first row=========================
   equationLayout->addWidget(quadraticModeDisplay  [0],5,0,1,1);
   equationLayout->addWidget(quadraticModeVariables[0],5,1,1,1);
   equationLayout->addWidget(quadraticModeDisplay  [1],5,2,1,1);
   equationLayout->addWidget(quadraticModeVariables[1],5,3,1,1);
   equationLayout->addWidget(quadraticModeDisplay  [2],5,4,1,1);


   equationLayout->addWidget(equationDisplay,   7,0,1,7);
   equationLayout->addWidget(calculateLinear,   8,0,1,3);
   equationLayout->addWidget(calculateQuadratic,8,3,1,2);
   equationLayout->addWidget(equationClear,     8,5,1,1);

   equationDisplay->setStyleSheet(styleSheetEquationDisplay);
   equationClear->setStyleSheet(styleSheetEquationPushButtons);
   calculateLinear->setStyleSheet(styleSheetEquationPushButtons);
   calculateQuadratic->setStyleSheet(styleSheetEquationPushButtons);
   headerLinear->setStyleSheet(styleSheetEquationLabelHeader);
   headerQuadratic->setStyleSheet(styleSheetEquationLabelHeader);

//    calculateQuadratic->setFixedSize(120,30);
//    calculateLinear->setFixedSize(120,30);
//    headerLinear->setFixedSize(80,60);
//    headerQuadratic->setFixedSize(120,60);
//    equationClear->setFixedSize(80,30);

   connect(calculateLinear,SIGNAL(clicked()),this,SLOT(onCalculateLinearClicked()));
   connect(calculateQuadratic,SIGNAL(clicked()),this,SLOT(onCalculateQuadraticClicked()));
   connect(equationClear,SIGNAL(clicked()),this,SLOT(onEquationClearPressed()));
}
void EquationCalculator::onCalculateLinearClicked(){

        double matrix[3][4],numbers[3][3],det1[3][3],det2[3][3],det3[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                matrix[i][j]=linearModeDisplay[i][j]->text().toDouble();
                if(j<3)
                numbers[i][j]=linearModeDisplay[i][j]->text().toDouble();
            }
        }
        for(int i=0;i<3;i++){
            for(int j=1;j<3;j++){
                det1[i][j]=matrix[i][j];
            }
            det1[i][0]=matrix[i][3];
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(j!=1)
                    det2[i][j]=matrix[i][j];
            }
            det2[i][1]=matrix[i][3];
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(j!=2)
                    det3[i][j]=matrix[i][j];
            }
            det3[i][2]=matrix[i][3];
        }
    std::string s = "x= "+std::to_string(getDeterminant(det1)/getDeterminant(numbers))+"   y= "+std::to_string(getDeterminant(det2)/getDeterminant(numbers))+
                "   z= "+std::to_string(getDeterminant(det3)/getDeterminant(numbers));
    equationDisplay->setText(QString::fromStdString(s));
}

void EquationCalculator::onCalculateQuadraticClicked(){
    long double x1, x2,d,img=0;

    d=pow(quadraticModeDisplay[1]->text().toDouble(),2)-4*quadraticModeDisplay[0]->text().toDouble()*quadraticModeDisplay[2]->text().toDouble();
    if(d>0){
        x1=(-1*quadraticModeDisplay[1]->text().toDouble()+sqrt(d))/(2*quadraticModeDisplay[0]->text().toDouble());
        x2=(-1*quadraticModeDisplay[1]->text().toDouble()-sqrt(d))/(2*quadraticModeDisplay[0]->text().toDouble());

        equationDisplay->setText("x1= "+QString::fromStdString(std::to_string(x1))+" x2= "+QString::fromStdString(std::to_string(x2)));
    }
    else if(d==0){
        x1=(-1*quadraticModeDisplay[1]->text().toDouble())/(2*quadraticModeDisplay[0]->text().toDouble());
        equationDisplay->setText("x= "+QString::fromStdString(std::to_string(x1)));
    }
    else{
        img=sqrt(abs(d))/(2*quadraticModeDisplay[0]->text().toDouble());
        x1=(-1*quadraticModeDisplay[1]->text().toDouble())/(2*quadraticModeDisplay[0]->text().toDouble());
        equationDisplay->setText("x1= "+QString::fromStdString(std::to_string(x1))+"+i"+QString::fromStdString(std::to_string(img))+"    x2= "+QString::fromStdString(std::to_string(x1))+"-i"+QString::fromStdString(std::to_string(img)));
    }
}

void EquationCalculator::onEquationClearPressed(){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            linearModeDisplay[i][j]->setText("0");
        }
    }
    for(int i=0;i<3;i++){
        quadraticModeDisplay[i]->setText("0");
    }
    equationDisplay->clear();
}
EquationCalculator::~EquationCalculator(){
    qDebug()<<"Equation Destructor Running";
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++)
                        delete linearModeDisplay[i][j];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
                        delete linearModeVariables[i][j];
    }
    for(int i=0;i<3;i++){
        delete quadraticModeDisplay[i];
        if(i!=2)
            delete quadraticModeVariables[i];
    }
    delete btnSelectQuadratic;
    delete btnSelectLinear;
    delete headerLinear;
    delete headerQuadratic;
    delete equationDisplay;
    delete equationClear;
    delete calculateLinear;
    delete calculateQuadratic;
    delete equationLayout;
    delete equationWindow;
}
