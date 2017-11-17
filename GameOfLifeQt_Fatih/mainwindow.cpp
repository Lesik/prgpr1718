#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(new GameWidget(this))
{
    ui->setupUi(this);
    ui->gridLayout->addWidget(game);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_start_clicked()
{
    game->startGame();
}

void MainWindow::on_Button_stop_clicked()
{
    game->stopGame();
}

void MainWindow::on_Button_clear_clicked()
{
    game->clear();
}

void MainWindow::on_SpinBox_universe_size_valueChanged(int arg1)
{
    game->setUniverseSize(arg1);
}

void MainWindow::on_SpinBox_generation_intervall_valueChanged(int arg1)
{
    game->setTimerIntervall(arg1);
}
