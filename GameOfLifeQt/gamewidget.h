#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QColor>
#include <QTimer>
#include <QWidget>
#include "CAbase.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    // setTimerIntervall (timer->setInterval(int));
    // setUniverseSize (ca1.ResetWorldSize(int,int));
    // connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
    void startGame();
    void stopGame();
    void clear();
    void newGeneration();
    void mousePressEvent();
    void mouseMoveEvent();
    void paintGrid();
    void paintUniverse();
signals:

public slots:

private:
    QTimer timer;
    QColor colour;
};

#endif // GAMEWIDGET_H
