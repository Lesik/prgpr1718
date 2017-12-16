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
#include "snake.h"
#include "predatorvictim.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void paintUniverse();
    void changeGame(int index);
    void changeMode(int index);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

signals:

public slots:
    void setTimerIntervall(int t);
    void setUniverseSize(int sizeun);
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

    enum GameType { GameOfLife, GameSnake, GamePredatorVictim };
    enum GameMode { Predator, Victim, Food };
    GameType game;
    int currentGame;
    int currentMode;
    CAbase ca;              // CAbase aus vorherigen Aufgaben
    Snake snake;
    predatorvictim predvic;
    int getUniverseSize();
    int getCell(int x, int y);
    void checkGameOver ();  // for Snake
};

#endif // GAMEWIDGET_H
