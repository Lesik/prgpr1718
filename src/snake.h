#ifndef SNAKE_H
#define SNAKE_H

#include <QRectF>
#include <QKeyEvent>
#include <QWidget>
#include <QPainter>

class Snake : public QWidget
{
public:
    Snake(QWidget *parent = nullptr);

    void paintSnake(QPaintEvent *);
    void paintFood(QPaintEvent *);

    void PrepareFieldSnake();
    void generateWorld(int worldX, int worldY);
    void generateFood();

    enum Direction { Stop, Up, Left, Down, Right };
    void setDirection(Direction direction);
    Direction getDirection();

    void evolve();
    void eatFood();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void onUp();
    void onLeft();
    void onDown();
    void onRight();

    void body();

    void collision();
    void gameOver();

    // 2-dim dynm Array
    int** currentworld;
    int** nextgenworld;

    QPoint ws; //worldSize
    QPointF cs; //cellSize

    QPoint head;
    QPoint tail;
    int length; // snake length
    QPoint food;
    Direction headDirection;
};

#endif // SNAKE_H
