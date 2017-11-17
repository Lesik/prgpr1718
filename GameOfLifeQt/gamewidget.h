#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QColor>
#include <QMouseEvent>
#include <QTimer>
#include <QWidget>
#include "CAbase.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void setTimerIntervall(int t);
    void setUniverseSize(int size);
    void startGame();
    void stopGame();
    void clear();
    //void mouseMoveEvent(QMouseEvent *event);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

public slots:
    //void newGeneration();
    //void paintGrid();
    //void paintUniverse();

private:
    QTimer* timer;
    QColor colour;
    int worldSize;
    CAbase ca;
};

#endif // GAMEWIDGET_H
