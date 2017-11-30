#ifndef SNAKE_H
#define SNAKE_H

#include <QRectF>
#include <QKeyEvent>
#include <QWidget>
#include <QPainter>

#define SIZE 30

class Snake : public QWidget
{
public:
    Snake(QWidget *parent = nullptr);

// Getter
    int getSize();
    int getCell(int x, int y);
    QPoint getFood();

    void prepareFieldSnake();
    void generateFood();

    enum Direction { Stop, Up, Left, Down, Right };
    void setDirection(Direction direction);

    void evolve();

private:
    void gameOver();

    // 2-dim Array
    int currentworld[SIZE][SIZE];

    QPoint head;
    QPoint tail;
    QPoint food;
    Direction headDirection;
    void doHead();
    void doTail();
};

#endif // SNAKE_H
