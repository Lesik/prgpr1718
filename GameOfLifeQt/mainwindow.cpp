#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(new GameWidget(this))
{
    ui->setupUi(this);
    ui->gameWidget1->addWidget(game);
    game->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked() { game->startGame(); }
void MainWindow::on_stopButton_clicked() { game->stopGame(); }
void MainWindow::on_clearButton_clicked() { game->clear(); }
void MainWindow::on_SpinBox_generation_intervall_valueChanged(int msec)
{
    game->setTimerIntervall(msec);
}

void MainWindow::on_SpinBox_universe_size_valueChanged(int size)
{
    game->setUniverseSize(size);
}
