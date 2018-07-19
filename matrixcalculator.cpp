#include "matrixcalculator.h"
MatrixCalculator::MatrixCalculator(QWidget *parent):QMainWindow(parent){
    qDebug()<<"Matrix Calculator Created";
    matrixWindow = new QWidget;
    matrixLayout = new QGridLayout;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixA[i][j] = new QLineEdit("0");
            matrixB[i][j] = new QLineEdit("0");
            matrixC[i][j] = new QLineEdit("0");
        }
    }
    displayMatrix       = new QLineEdit;
    btnSwapMatrix[0]    = new Button(QString::fromUtf8("\u21c6"));
    btnSwapMatrix[1]    = new Button(QString::fromUtf8("\u296e"));
    btnAddMatrix        = new Button("A+B");
    btnSubtractMatrix   = new Button("A-B");
    btnMultiplyMatrix   = new Button("AxB");
    btnDetA             = new Button(QString::fromUtf8("\u2206")+"A");
    btnDetB             = new Button(QString::fromUtf8("\u2206")+"B");
    btnInvA             = new Button("inv(A)");
    btnInvB             = new Button("inv(B)");
    btnTransA           = new Button("trans(A)");
    btnTransB           = new Button("trans(B)");
    btnDetC             = new Button(QString::fromUtf8("\u2206")+"C");
    btnTransC           = new Button("trans(C)");
    btnInvC             = new Button("inv(C)");

    btnMatrixClear      = new Button("Clear");

    matrixATitle        = new QLabel("Matrix A");
    matrixBTitle        = new QLabel("Matrix B");
    matrixCTitle        = new QLabel("Matrix C");


    CreateMatrixCalculatorWidget();
    matrixWindow->setLayout(matrixLayout);

}
QWidget* MatrixCalculator::getMatrixWidget(){
    return matrixWindow;
}

void MatrixCalculator::CreateMatrixCalculatorWidget(){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixA[i][j]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
            matrixB[i][j]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
            matrixC[i][j]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        }
    }
    displayMatrix->setReadOnly(true);

    btnSwapMatrix[0]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnSwapMatrix[1]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnAddMatrix->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnSubtractMatrix->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnMultiplyMatrix->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnDetA->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnDetB->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnInvA->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnInvB->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnTransA->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    btnTransB->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    matrixATitle->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    matrixBTitle->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    matrixCTitle->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    displayMatrix->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    matrixLayout->addWidget(matrixATitle,0,1,1,1);
    matrixLayout->addWidget(btnSwapMatrix[0],0,3,1,1);
    matrixLayout->addWidget(matrixBTitle,0,6,1,1);
    matrixLayout->addWidget(btnAddMatrix,1,3,1,1);
    matrixLayout->addWidget(btnSubtractMatrix,2,3,1,1);
    matrixLayout->addWidget(btnMultiplyMatrix,3,3,1,1);
    btnDetA->setFixedHeight(35);
    btnMatrixClear->setFixedHeight(35);
    btnDetC->setFixedHeight(35);
    btnTransC->setFixedHeight(35);
    btnInvC->setFixedHeight(35);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          matrixLayout->addWidget(matrixA[i][j],i+1,j,1,1);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixLayout->addWidget(matrixB[i][j],i+1,j+5,1,1);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixLayout->addWidget(matrixC[i][j],i+6,j,1,1);
        }
    }
    matrixLayout->addWidget(displayMatrix,6,5,3,3);

    matrixLayout->addWidget(btnDetA,4,0,1,1);
    matrixLayout->addWidget(btnTransA,4,1,1,1);
    matrixLayout->addWidget(btnInvA,4,2,1,1);

    matrixLayout->addWidget(btnDetB,4,5,1,1);
    matrixLayout->addWidget(btnTransB,4,6,1,1);
    matrixLayout->addWidget(btnInvB,4,7,1,1);

    matrixLayout->addWidget(matrixCTitle,5,1,1,1);
    matrixLayout->addWidget(btnSwapMatrix[1],5,2,1,1);
    matrixLayout->addWidget(btnDetC,6,3,1,1);
    matrixLayout->addWidget(btnTransC,7,3,1,1);
    matrixLayout->addWidget(btnInvC,8,3,1,1);
    matrixLayout->addWidget(btnMatrixClear,4,3,1,1);


    //========================================StyleSheets======================================================
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixA[i][j]->setStyleSheet("QLineEdit {font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 2px solid #afeeee;border-radius:5px; background-color: white;}");
            matrixB[i][j]->setStyleSheet("QLineEdit {font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 2px solid #afeeee;border-radius:5px; background-color: white;}");
            matrixC[i][j]->setStyleSheet("QLineEdit {font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 2px solid #afeeee;border-radius:5px; background-color: white;}");
        }
    }


    btnSwapMatrix[0]->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnSwapMatrix[1]->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnAddMatrix->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnSubtractMatrix->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnMultiplyMatrix->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnDetA->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnDetB->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnInvA->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnInvB->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnTransA->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnTransB->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    matrixATitle->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    matrixBTitle->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    matrixCTitle->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    displayMatrix->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnMatrixClear->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnDetC->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnTransC->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");
    btnInvC->setStyleSheet("QPushButton { font-size: 14px; background-color:#ffb1a3; border: 2px solid #f7f7f7;border-radius:5px; } QPushButton:hover { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffb1a3, stop: 1 #FFFFE0); }");

    matrixATitle->setStyleSheet("font-size:14pt 'Microsoft YaHei UI';qproperty-alignment: AlignHCenter;padding 2px;");
    matrixBTitle->setStyleSheet("font-size:14pt 'Microsoft YaHei UI';qproperty-alignment: AlignHCenter;padding 2px;");
    matrixCTitle->setStyleSheet("font-size:14pt 'Microsoft YaHei UI';qproperty-alignment: AlignHCenter;padding 2px;");

    displayMatrix->setStyleSheet("font: 12pt 'Microsoft YaHei UI'; qproperty-alignment: AlignRight; padding: 5px; border: 2px solid #afeeee;border-radius:5px; background-color: white;");

    //======================================Connect Here=====================================================================================================
    connect(btnMatrixClear,SIGNAL(clicked()),this,SLOT(onClearMatrixClicked()));
    connect(btnSwapMatrix[0],SIGNAL(clicked()),this,SLOT(onSwapMatrixPressed()));
    connect(btnSwapMatrix[1],SIGNAL(clicked()),this,SLOT(onSwapMatrixPressed()));
    connect(btnAddMatrix,SIGNAL(clicked()),this,SLOT(onAddMatrixPressed()));
    connect(btnSubtractMatrix,SIGNAL(clicked()),this,SLOT(onSubtractMatrixPressed()));
    connect(btnTransA,SIGNAL(clicked()),this,SLOT(onTransPressed()));
    connect(btnTransB,SIGNAL(clicked()),this,SLOT(onTransPressed()));
    connect(btnTransC,SIGNAL(clicked()),this,SLOT(onTransPressed()));
    connect(btnDetA,SIGNAL(clicked()),this,SLOT(onDeterminantPressed()));
    connect(btnDetB,SIGNAL(clicked()),this,SLOT(onDeterminantPressed()));
    connect(btnDetC,SIGNAL(clicked()),this,SLOT(onDeterminantPressed()));
    connect(btnInvA,SIGNAL(clicked()),this,SLOT(onInversePressed()));
    connect(btnInvB,SIGNAL(clicked()),this,SLOT(onInversePressed()));
    connect(btnInvC,SIGNAL(clicked()),this,SLOT(onInversePressed()));
    connect(btnMultiplyMatrix,SIGNAL(clicked()),this,SLOT(onMultiplyMatrixPressed()));

    matrixWindow->setLayout(matrixLayout);
    setCentralWidget(matrixWindow);
}
void MatrixCalculator::onClearMatrixClicked(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixA[i][j]->setText("0");
            matrixB[i][j]->setText("0");
            matrixC[i][j]->setText("0");
        }
    }
    displayMatrix->clear();
}
void MatrixCalculator::onSwapMatrixPressed(){
    QPushButton* btn = (QPushButton*)sender();
    if(btn->text()==QString::fromUtf8("\u21c6")){
         double *temp1[3][3],*temp2[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp1[i][j]     = new  double;
                *temp1[i][j]    = matrixA[i][j]->text().toDouble();
                temp2[i][j]     = new  double;
                *temp2[i][j]    = matrixB[i][j]->text().toDouble();
                matrixA[i][j]->setText(QString::number(*temp2[i][j]));
                matrixB[i][j]->setText(QString::number(*temp1[i][j]));
                delete temp1[i][j];
                delete temp2[i][j];
            }
        }
    }
    else if(btn->text()==QString::fromUtf8("\u296e")){
        double *temp1[3][3],*temp2[3][3];
       for(int i=0;i<3;i++){
           for(int j=0;j<3;j++){
               temp1[i][j]     = new  double;
               *temp1[i][j]    = matrixA[i][j]->text().toDouble();
               temp2[i][j]     = new  double;
               *temp2[i][j]    = matrixC[i][j]->text().toDouble();
               matrixA[i][j]->setText(QString::number(*temp2[i][j]));
               matrixC[i][j]->setText(QString::number(*temp1[i][j]));
               delete temp1[i][j];
               delete temp2[i][j];
           }
       }
    }
}
void MatrixCalculator::onAddMatrixPressed(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixC[i][j]->setText(QString::number(matrixA[i][j]->text().toDouble()+matrixB[i][j]->text().toDouble()));

        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixA[i][j]->setText("0");
            matrixB[i][j]->setText("0");
        }
    }
}
void MatrixCalculator::onSubtractMatrixPressed(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixC[i][j]->setText(QString::number(matrixA[i][j]->text().toDouble()-matrixB[i][j]->text().toDouble()));

        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixA[i][j]->setText("0");
            matrixB[i][j]->setText("0");
        }
    }
}
void MatrixCalculator::onTransPressed(){
    QPushButton* button = (QPushButton*)sender();
    QString buttonText = button->text();
    if(buttonText=="trans(A)"){
        double *temp1[3][3],*temp2[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp1[i][j] = new double;
                temp2[i][j] = new double;
                *temp1[i][j] = matrixA[i][j]->text().toDouble();
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                *temp2[i][j]= *temp1[j][i];
                matrixA[i][j]->setText(QString::number(*temp2[i][j]));
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                delete temp1[i][j];
                delete temp2[i][j];
            }
        }
    }

    else if(buttonText=="trans(B)")
    {
        double *temp1[3][3],*temp2[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp1[i][j] = new double;
                temp2[i][j] = new double;
                *temp1[i][j] = matrixB[i][j]->text().toDouble();
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                *temp2[i][j]= *temp1[j][i];
                matrixB[i][j]->setText(QString::number(*temp2[i][j]));
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                delete temp1[i][j];
                delete temp2[i][j];
            }
        }
    }
    else if(buttonText=="trans(C)"){
        double *temp1[3][3],*temp2[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp1[i][j] = new double;
                temp2[i][j] = new double;
                *temp1[i][j] = matrixC[i][j]->text().toDouble();
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                *temp2[i][j]= *temp1[j][i];
                matrixC[i][j]->setText(QString::number(*temp2[i][j]));
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                delete temp1[i][j];
                delete temp2[i][j];
            }
        }
    }
}
void MatrixCalculator::onDeterminantPressed(){
    QPushButton* button = (QPushButton*)sender();
    if(button->text()==QString::fromUtf8("\u2206")+"A"){
        double *a[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j] = new double;
                *a[i][j] = matrixA[i][j]->text().toDouble();
            }
        }
        displayMatrix->setText(QString::number(*a[0][0]*(*a[1][1]**a[2][2]-*a[2][1]**a[1][2])-*a[0][1]*(*a[1][0]**a[2][2]-*a[2][0]**a[1][2])+*a[0][2]*(*a[1][0]**a[2][1]-*a[1][1]**a[2][0])));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                delete a[i][j];
            }
        }
    }
    else if(button->text()==QString::fromUtf8("\u2206")+"B"){
        double *a[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j] = new double;
                *a[i][j] = matrixB[i][j]->text().toDouble();
            }
        }
        displayMatrix->setText(QString::number(*a[0][0]*(*a[1][1]**a[2][2]-*a[2][1]**a[1][2])-*a[0][1]*(*a[1][0]**a[2][2]-*a[2][0]**a[1][2])+*a[0][2]*(*a[1][0]**a[2][1]-*a[1][1]**a[2][0])));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                delete a[i][j];
            }
        }
    }
    else if(button->text()==QString::fromUtf8("\u2206")+"C"){
        double *a[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j] = new double;
                *a[i][j] = matrixC[i][j]->text().toDouble();
            }
        }
        displayMatrix->setText(QString::number(*a[0][0]*(*a[1][1]**a[2][2]-*a[2][1]**a[1][2])-*a[0][1]*(*a[1][0]**a[2][2]-*a[2][0]**a[1][2])+*a[0][2]*(*a[1][0]**a[2][1]-*a[1][1]**a[2][0])));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                delete a[i][j];
            }
        }
    }
}
void MatrixCalculator::onInversePressed(){
    QPushButton* button = (QPushButton*)sender();
    if(button->text()=="inv(A)"){
        double *a[3][3],*adj[3][3],*det;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j]     = new double;
                adj[i][j]   = new double;
                *a[i][j]    = matrixA[i][j]->text().toDouble();
            }
        }
        det = new double;
        *det=*a[0][0]*(*a[1][1]**a[2][2]-*a[2][1]**a[1][2])-*a[0][1]*(*a[1][0]**a[2][2]-*a[2][0]**a[1][2])+*a[0][2]*(*a[1][0]**a[2][1]-*a[1][1]**a[2][0]);
        *adj[0][0] = *a[0][0]**a[2][2]-*a[2][1]**a[1][2];
        *adj[0][1] = -1*(*a[0][1]**a[2][2]-*a[2][1]**a[0][2]);
        *adj[0][2] = *a[0][1]**a[1][2]-*a[0][2]**a[1][1];
        *adj[1][0] = -1*(*a[1][0]**a[2][2]-*a[1][2]**a[2][0]);
        *adj[1][1] = *a[0][0]**a[2][2]-*a[0][2]**a[2][0];
        *adj[1][2] = -1*(*a[0][0]**a[1][2]-*a[0][2]**a[1][0]);
        *adj[2][0] = *a[1][0]**a[2][1]-*a[1][1]**a[2][0];
        *adj[2][1] = -1*(*a[0][0]**a[2][1]-*a[0][1]**a[2][0]);
        *adj[2][2] = *a[0][0]**a[1][1]-*a[1][0]**a[0][1];
        if(*det!=0.0){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    matrixA[i][j]->setText(QString::number(*adj[i][j]/(*det)));
                }
            }
        }
        else if(*det==0.0)
            displayMatrix->setText("NO INVERSE EXISTS");
        delete det;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                delete a[i][j];
                delete adj[i][j];
            }
        }
    }
    else if(button->text()=="inv(B)"){
        double *a[3][3],*adj[3][3],*det;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j]     = new double;
                adj[i][j]   = new double;
                *a[i][j]    = matrixB[i][j]->text().toDouble();
            }
        }
        det = new double;
        *det=*a[0][0]*(*a[1][1]**a[2][2]-*a[2][1]**a[1][2])-*a[0][1]*(*a[1][0]**a[2][2]-*a[2][0]**a[1][2])+*a[0][2]*(*a[1][0]**a[2][1]-*a[1][1]**a[2][0]);
        *adj[0][0] = *a[0][0]**a[2][2]-*a[2][1]**a[1][2];
        *adj[0][1] = -1*(*a[0][1]**a[2][2]-*a[2][1]**a[0][2]);
        *adj[0][2] = *a[0][1]**a[1][2]-*a[0][2]**a[1][1];
        *adj[1][0] = -1*(*a[1][0]**a[2][2]-*a[1][2]**a[2][0]);
        *adj[1][1] = *a[0][0]**a[2][2]-*a[0][2]**a[2][0];
        *adj[1][2] = -1*(*a[0][0]**a[1][2]-*a[0][2]**a[1][0]);
        *adj[2][0] = *a[1][0]**a[2][1]-*a[1][1]**a[2][0];
        *adj[2][1] = -1*(*a[0][0]**a[2][1]-*a[0][1]**a[2][0]);
        *adj[2][2] = *a[0][0]**a[1][1]-*a[1][0]**a[0][1];
        if(*det!=0.0){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    matrixB[i][j]->setText(QString::number(*adj[i][j]/(*det)));
                }
            }
        }
        else if(*det==0.0)
            displayMatrix->setText("NO INVERSE EXISTS");
        delete det;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                delete a[i][j];
                delete adj[i][j];
            }
        }
    }
    else if(button->text()=="inv(C)"){
        double *a[3][3],*adj[3][3],*det;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j]     = new double;
                adj[i][j]   = new double;
                *a[i][j]    = matrixC[i][j]->text().toDouble();
            }
        }
        det = new double;
        *det=*a[0][0]*(*a[1][1]**a[2][2]-*a[2][1]**a[1][2])-*a[0][1]*(*a[1][0]**a[2][2]-*a[2][0]**a[1][2])+*a[0][2]*(*a[1][0]**a[2][1]-*a[1][1]**a[2][0]);
        *adj[0][0] = *a[0][0]**a[2][2]-*a[2][1]**a[1][2];
        *adj[0][1] = -1*(*a[0][1]**a[2][2]-*a[2][1]**a[0][2]);
        *adj[0][2] = *a[0][1]**a[1][2]-*a[0][2]**a[1][1];
        *adj[1][0] = -1*(*a[1][0]**a[2][2]-*a[1][2]**a[2][0]);
        *adj[1][1] = *a[0][0]**a[2][2]-*a[0][2]**a[2][0];
        *adj[1][2] = -1*(*a[0][0]**a[1][2]-*a[0][2]**a[1][0]);
        *adj[2][0] = *a[1][0]**a[2][1]-*a[1][1]**a[2][0];
        *adj[2][1] = -1*(*a[0][0]**a[2][1]-*a[0][1]**a[2][0]);
        *adj[2][2] = *a[0][0]**a[1][1]-*a[1][0]**a[0][1];
        if(*det!=0.0){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    matrixC[i][j]->setText(QString::number(*adj[i][j]/(*det)));
                }
            }
        }
        else if(*det==0.0)
            displayMatrix->setText("NO INVERSE EXISTS");
        delete det;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                delete a[i][j];
                delete adj[i][j];
            }
        }
    }
}
void MatrixCalculator::onMultiplyMatrixPressed(){
    double *temp1[3][3],*temp2[3][3],*temp[3][3],*sum;
    sum= new double(0.0);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp1[i][j]     = new double;
            temp[i][j]      = new double;
            *temp1[i][j]    = matrixA[i][j]->text().toDouble();
            temp2[i][j]     = new double;
            *temp2[i][j]    = matrixB[i][j]->text().toDouble();
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                *sum+=*temp1[i][k]**temp2[k][j];
            }
            *temp[i][j]=*sum;
            *sum=0.0;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrixC[i][j]->setText(QString::number(*temp[i][j]));
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            delete temp1[i][j];
            delete temp2[i][j];
            delete temp[i][j];
        }
    }
    delete sum;
}


