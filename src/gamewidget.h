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
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void paintGrid();
    void paintUniverse();
    void changeGame(int index);

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
    void keyPressEvent(QKeyEvent *event);

private:                    // Private Variablen
    QTimer *timer;
    QColor colour;
    int universeSize;
    CAbase ca;              // CAbase aus vorherigen Aufgaben
};

#endif // GAMEWIDGET_H
