#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_clearButton_clicked();

    void on_SpinBox_generation_intervall_valueChanged(int msec);

    void on_SpinBox_universe_size_valueChanged(int size);

private:
    Ui::MainWindow *ui;
    GameWidget* game;
};

#endif // MAINWINDOW_H
