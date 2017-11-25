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

    void paintHead(QPaintEvent *);
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
    void keyPressEvent(QKeyEvent *event) override;
    void onUp();
    void onLeft();
    void onDown();
    void onRight();

    void collision();
    void gameOver();

    int** currentworld;
    int** nextgenworld;

    QPoint ws; //worldSize
    QPointF cs; //cellSize

    QPoint head;
    QPoint food;
    Direction headDirection;
};

#endif // SNAKE_H
