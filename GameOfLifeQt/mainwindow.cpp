#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(new GameWidget(this))
{
    ui->setupUi(this);
    ui->gameWidget->addWidget(game);
    game->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked() { game->startGame(); }
void MainWindow::on_stopButton_clicked() { game->stopGame(); }
