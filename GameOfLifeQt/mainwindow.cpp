#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Button_start, SIGNAL(clicked()), game,SLOT(startGame()));
    connect(ui->Button_stop, SIGNAL(clicked()), game,SLOT(stopGame()));
    connect(ui->Button_clear, SIGNAL(clicked()), game,SLOT(clear()));
    connect(ui->SpinBox_generation_intervall, SIGNAL(valueChanged(int)), game, SLOT(setTimeIntervall(int)));
    connect(ui->SpinBox_universe_size, SIGNAL(valueChanged(int)), game, SLOT(setUniverseSize(int)));
    //connect(ui->Button_savem, SIGNAL(clicked()), this, SLOT(saveGame()));
    //connect(ui->Button_load, SIGNAL(clicked()), this, SLOT(loadGame()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
