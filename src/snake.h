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

// Getter
    int getCell(int x, int y);
    int getFoodCoordX();
    int getFoodCoordY();

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

    void generateBody();

    void collision();
    void gameOver();

    // 2-dim dynm Array
    int** currentworld;
    int** nextgenworld;

    QPoint ws; //worldSize

    QPoint head;
    QPoint tail;
    int length; // snake length
    QPoint food;
    Direction headDirection;
};

#endif // SNAKE_H
