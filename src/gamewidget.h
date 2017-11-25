/*
    Javi (), Lesik (6082200), Kelvin Tsang (5428328)
*/

#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QColor>
#include <QMouseEvent>
#include <QTimer>
#include <QWidget>

#include "cabase.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void paintUniverse();
    void changeGame(int index);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

signals:

public slots:
    void setTimerIntervall(int t);
    void setUniverseSize(int size);
    void startGame();
    void stopGame();
    void clear();
    void newGeneration();
    void saveToFile();
    void loadFromFile();

    void paintGrid(QPaintEvent *, double cellWidth, double cellHeight);

private:                    // Private Variablen
    QTimer *timer;
    QColor colour;
    int universeSize;
    CAbase ca;              // CAbase aus vorherigen Aufgaben
};

#endif // GAMEWIDGET_H
