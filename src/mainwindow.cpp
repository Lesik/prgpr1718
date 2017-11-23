/*
    Javi (), Lesik (6082200), Kelvin Tsang (5428328)
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    game(new GameWidget(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridLayout->addWidget(game);
}

MainWindow::~MainWindow() {delete ui;}

// Widgets im mainwindow.ui werden zu Funktionen in gamewidget zugewiesen
void MainWindow::on_Button_start_clicked() {game->startGame();}
void MainWindow::on_Button_stop_clicked() {game->stopGame();}
void MainWindow::on_Button_clear_clicked() {game->clear();}
void MainWindow::on_SpinBox_universe_size_valueChanged(int arg1) {game->setUniverseSize(arg1);}
void MainWindow::on_SpinBox_generation_intervall_valueChanged(int arg1) {game->setTimerIntervall(arg1);}
void MainWindow::on_Button_save_clicked() {game->saveToFile();}
void MainWindow::on_Button_load_clicked() {game->loadFromFile();}

void MainWindow::on_ComboBox_universe_mode_activated(int index) {
    game->changeGame(index);
}
