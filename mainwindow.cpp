#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainLayout = new QGridLayout;
    mainWidget = new QWidget;

    createSideBar();

    BasicCalculator *basicCalculator = new BasicCalculator;
    QWidget *basicWidget = basicCalculator->getCalculatorWidget();


    modeDisplayWidget = new QWidget;
    modeDisplayLayout = new QGridLayout;

    modeDisplayLayout->addWidget(basicWidget);
    modeDisplayWidget->setLayout(modeDisplayLayout);

    mainLayout->addWidget(modeDisplayWidget,0,1,1,10);
    mainLayout->addWidget(modesWidget,0,0,1,1);

    mainWidget->setLayout(mainLayout);
    this->setWindowTitle("Basic Calculator");
    this->setWindowIcon(QIcon(":/new/icons/icon.png"));
    setCentralWidget(mainWidget);

    this->setFixedSize(1245,550);


}


void MainWindow::spawnBasicMode() {
    BasicCalculator *basicCalculator = new BasicCalculator;
    QWidget *basicWidget = basicCalculator->getCalculatorWidget();
    this->setWindowTitle("Basic Calculator");
    SpawnMode(basicWidget);
}
void MainWindow::spawnScientificMode(){
    ScientificCalculator *scientificCalculator = new ScientificCalculator;
    QWidget *scientificWidget = scientificCalculator->getScientificCalculator();
    SpawnMode(scientificWidget);
    this->setWindowTitle("Scientific Calculator");
}
void MainWindow::spawnMatrixMode() {
    MatrixCalculator *matrixCalculator = new MatrixCalculator;
    QWidget *matrixWidget = matrixCalculator->getMatrixWidget();
    SpawnMode(matrixWidget);
    this->setWindowTitle("Matrix Calculator");
}

void MainWindow::spawnEquationMode() {
    EquationCalculator *equationCalculator = new EquationCalculator;
    QWidget *equationWidget = equationCalculator->getEquationWidget();
    SpawnMode(equationWidget);
    this->setWindowTitle("Equation Calculator");
    }
void MainWindow::spawnFinancialMode() {
    FinancialCalculator *financialCalculator = new FinancialCalculator;
    QWidget *financialWidget = financialCalculator->getFinancialCalculatorWidget();
    this->setWindowTitle("Financial Calculator");
    SpawnMode(financialWidget);
}
void MainWindow::spawnProgrammerMode() {
    ProgrammerCalculator *programmerCalculator = new ProgrammerCalculator;
    QWidget *programmerWidget = programmerCalculator->getProgrammerCalculatorWidget();
    SpawnMode(programmerWidget);
    this->setWindowTitle("Programmer Calculator");

}
void MainWindow::spawnConversionMode() {
    ConversionCalculator *conversionCalculator= new ConversionCalculator;

    QWidget *conversionWidget = conversionCalculator->getConversionWidget();
    this->setWindowTitle("Conversion Calculator");
    SpawnMode(conversionWidget);
}
void MainWindow::spawnManualMode(){
    ManualMode *manualMode = new ManualMode;
    QWidget *manualWidget = manualMode->getManualWidget();
    SpawnMode(manualWidget);
    this->setWindowTitle("Manual");
}
void MainWindow::spawnFormulaMode(){
    FormulaMode *formulaMode = new FormulaMode;
    QWidget *formulaWidget = formulaMode->getFormulaWidget();
    SpawnMode(formulaWidget);
    this->setWindowTitle("Manual");
}
void MainWindow::spawnAboutMode(){
    aboutMode *abtMode = new aboutMode;
    QWidget *aboutWidget = abtMode->getAboutWidget();
    SpawnMode(aboutWidget);
    this->setWindowTitle("About");
}

void MainWindow::SpawnMode(QWidget *tempWidget) {
    delete mainLayout;//if not deleted
    delete modeDisplayLayout;//the windows
    delete modeDisplayWidget;//will overlap

    modeDisplayWidget = new QWidget;
    modeDisplayLayout = new QGridLayout;

    modeDisplayLayout->addWidget(tempWidget);
    modeDisplayWidget->setLayout(modeDisplayLayout);

    mainLayout = new QGridLayout;

    mainLayout->addWidget(modeDisplayWidget,0,1,1,10);
    mainLayout->addWidget(modesWidget,0,0,1,1);
    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);

}

void MainWindow::createSideBar() {
    modesLayout = new QGridLayout;
    modesWidget = new QWidget;
    QString styleSheetModeButtons = "QPushButton { color:#ffffff;font-size: 14pt; background-color:#000000; border: 1px solid gray;border-radius:3px; } QPushButton:pressed {color:#000000;background-color:#ffffff;}";
    QString modes[10];
    modes[0]=" Basic Calculator ";
    modes[1]="Scientific Calculator";
    modes[2]=" Matrix Calculator ";
    modes[3]=" Equation Calculator ";
    modes[4]=" Financial Calculator";
    modes[5]=" Programmer Calculator ";
    modes[6]=" Conversion Calculator ";
    modes[7]=" Important Formulas ";
    modes[8]=" Manual ";
    modes[9]=" About ";
    for(int i = 0; i < 10; i++) {
        modeButtons[i] = new Button(modes[i], this);
        modeButtons[i]->setStyleSheet(styleSheetModeButtons);
        modeButtons[i]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        modesLayout->addWidget(modeButtons[i]);

    }
    modesWidget->setLayout(modesLayout);

    connect(modeButtons[0], SIGNAL(clicked()), this, SLOT( spawnBasicMode() ));
    connect(modeButtons[1], SIGNAL(clicked()), this, SLOT( spawnScientificMode()));
    connect(modeButtons[2], SIGNAL(clicked()), this, SLOT( spawnMatrixMode() ));
    connect(modeButtons[3], SIGNAL(clicked()), this, SLOT( spawnEquationMode() ));
    connect(modeButtons[4], SIGNAL(clicked()), this, SLOT( spawnFinancialMode() ));
    connect(modeButtons[5], SIGNAL(clicked()), this, SLOT( spawnProgrammerMode() ));
    connect(modeButtons[6], SIGNAL(clicked()), this, SLOT( spawnConversionMode() ));
    connect(modeButtons[7], SIGNAL(clicked()), this, SLOT( spawnFormulaMode() ));
    connect(modeButtons[8], SIGNAL(clicked()), this, SLOT( spawnManualMode() ));
    connect(modeButtons[9], SIGNAL(clicked()), this, SLOT( spawnAboutMode()) );
}


MainWindow::~MainWindow()
{
    delete ui;
}
