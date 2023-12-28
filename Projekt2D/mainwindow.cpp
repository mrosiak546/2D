
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Przesuwanie
    ui->transX->setRange(-250, 250);
    ui->transY->setRange(-250, 250);
    connect(ui->transX, SIGNAL(valueChanged(int)), ui->widget, SLOT(przesuwanieDX(int)));
    connect(ui->transY, SIGNAL(valueChanged(int)), ui->widget, SLOT(przesuwanieDY(int)));

    //Obracanie
    ui->rotation->setRange(0, 360);
    connect(ui->rotation, SIGNAL(valueChanged(int)), ui->widget, SLOT(obracanie(int)));

    //Skalowanie
    ui->scalingX->setRange(0, 200);
    ui->scalingY->setRange(0, 200);
    ui->scalingX->setValue(100);
    ui->scalingY->setValue(100);
    connect(ui->scalingX, SIGNAL(valueChanged(int)), ui->widget, SLOT(skalowanieSX(int)));
    connect(ui->scalingY, SIGNAL(valueChanged(int)), ui->widget, SLOT(skalowanieSY(int)));

    //Pochylanie
    ui->shearingX->setRange(-100, 100);
    ui->shearingY->setRange(-100, 100);
    connect(ui->shearingX, SIGNAL(valueChanged(int)), ui->widget, SLOT(pochylanieSHX(int)));
    connect(ui->shearingY, SIGNAL(valueChanged(int)), ui->widget, SLOT(pochylanieSHY(int)));


    //Reset
    connect(ui->resetB,SIGNAL(clicked()),this,SLOT(reset2()));
    connect(ui->resetB,SIGNAL(clicked()),ui->widget,SLOT(reset2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset2()
{
    ui->transX->setValue(0);
    ui->transY->setValue(0);
    ui->rotation->setValue(0);
    ui->scalingX->setValue(100);
    ui->scalingY->setValue(100);
    ui->shearingX->setValue(0);
    ui->shearingY->setValue(0);
    update();
}


