/*
    Javi (), Lesik (6082200), Kelvin Tsang (5428328)
*/

#include <QTimer>
#include <QMouseEvent>
#include <QRectF>
#include <QPainter>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "gamewidget.h"
using namespace std;

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this)),
    snake(new Snake(this))
{
    // der Timer wird mit dem Slot newGeneration verbunden
    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
    setFocusPolicy(Qt::ClickFocus);
}

// Setter
void GameWidget::setTimerIntervall(int t) {timer->setInterval(t);}
void GameWidget::setUniverseSize(int size) {
    switch (currentGame) {
        case GameOfLife:
            ca.setSize(size, size);
            break;
    }
    // update damit die neue Groeße die mit der Spinbox veraendert wurde
    // angezeigt wird
    update();

}

// Start, Stop und Clear Funktion
void GameWidget::startGame() {timer->start();}
void GameWidget::stopGame() {timer->stop();}
void GameWidget::clear()
{
    switch (currentGame) {
    case GameOfLife:            setUniverseSize(getUniverseSize()); break;
    case GameSnake:             snake.prepareFieldSnake(); break;
    case GamePredatorVictim:    predvic.prepareField(); break;
    }
    update();
}

void GameWidget::newGeneration() {
    switch (currentGame) {
    case GameOfLife:
        ca.evolve();    // evolve() von CAbase
        break;
    case GameSnake:
        snake.evolve();
        checkGameOver();
        break;
    case GamePredatorVictim:
        predvic.worldEvolutionLifePredator();
        break;
    }
    update();
}

// wenn die Maustaste geklickt worden ist, soll die Funktion ausgeführt werden
void GameWidget::mousePressEvent(QMouseEvent *event)
{
    // 580 ist die Groeße die wir im mainwindow.ui festgelegt haben
    double cellGeometry = 580.00 / getUniverseSize();
    // hier wird die Position des Mauszeigers abgefragt
    int xPosition = event->x()/cellGeometry;
    int yPosition = event->y()/cellGeometry;

    switch (currentGame) {
    case GameOfLife: {
        // je nach dem ob die lebendig war oder nicht wird sie invertiert
        if (ca.getCell(xPosition, yPosition) == 0) {
            ca.setCell(xPosition, yPosition, 1);
        }
        else ca.setCell(xPosition, yPosition, 0);
        break;
    }
    case GamePredatorVictim: {
        int value = 0;
        switch (currentMode) {
        case Predator:
            value = 1;
            break;
        case Victim:
            value = 2;
            break;
        case Food:
            value = 3;
            break;
        default: break;
        }
        if (predvic.getCell(xPosition, yPosition) == value)
            predvic.setCell(xPosition, yPosition, 0);
        else predvic.setCell(xPosition, yPosition, value);
        break;
    }
    default:
        break;
    }
    update();
}

// wenn die Maustaste geklickt worden ist, soll die Funktion ausgeführt werden
void GameWidget::mouseMoveEvent(QMouseEvent *event)
{
    double cellGeometry = 580.00 / getUniverseSize();
    int xPosition = event->x()/cellGeometry;
    int yPosition = event->y()/cellGeometry;

    switch (currentGame) {
    case GameOfLife:
        if (ca.getCell(xPosition, yPosition) == 0)
           ca.setCell(xPosition, yPosition, 1);
        break;
    case GamePredatorVictim:
        int value = 0;
        switch (currentMode) {
        case Predator:
            value = 1;
            break;
        case Victim:
            value = 2;
            break;
        case Food:
            value = 3;
            break;
        }
        if (predvic.getCell(xPosition, yPosition) != value)
            predvic.setCell(xPosition, yPosition, value);
        break;
    }
    update();
}

void GameWidget::paintGrid(QPaintEvent *, double cellWidth, double cellHeight) {
    // initiate painter
    QPainter painter(this);
    painter.setPen(Qt::darkGreen);
    // draw cell dividers
    for (double i = cellWidth; i <= width(); i += cellWidth)
        painter.drawLine(i, 0, i, height());
    for (double i = cellHeight; i <= height(); i += cellHeight)
        painter.drawLine(0, i, width(), i);

    // draw border from x = 0, y = 0 to x = width - 1, y = height - 1
    QRect borders(0, 0, width() - 1, height() - 1);
    painter.drawRect(borders);
}

int GameWidget::getUniverseSize() {
    switch (currentGame) {
    case GameOfLife:
        return ca.getNx();
        break;
    case GameSnake:
        return snake.getSize();
        break;
    case GamePredatorVictim:
        return predvic.getSize();
        break;
    }
    return 30;
}

int GameWidget::getCell(int x, int y) {
    switch (currentGame) {
    case GameOfLife:
        return ca.getCell(x, y);
        break;
    case GameSnake:
        return snake.getCell(x, y);
        break;
    case GamePredatorVictim:
        return predvic.getCell(x, y);
    }
    return 0;
}

// wird ausgefuert wenn update() ausgefuehrt wurde
void GameWidget::paintEvent(QPaintEvent *event)
{
    double cellWidth = (double) width() / getUniverseSize();
    double cellHeight = (double) height() / getUniverseSize();
    paintGrid(event, cellWidth, cellHeight);

    // initiate painter
    QPainter painter(this);
    // for each cell in world, if is alive
    int universeSize = getUniverseSize();
    for (int x = 0; x < universeSize; x++) {
        for (int y = 0; y < universeSize; y++) {
            // calculate left and top edges by calculating distance from top left edge
            qreal left = (qreal) (cellWidth * x);
            qreal top = (qreal) (cellHeight * y);
            // the cell should be cellWidth wide and cellHeight tall
            QRectF r(left, top, (qreal) cellWidth, (qreal) cellHeight);
            switch (currentGame) {
            case GameOfLife:
                if (getCell(x, y) > 0) painter.fillRect(r, Qt::red);
                break;
            case GameSnake:
                if (getCell(x, y) > 0) painter.fillRect(r, Qt::darkBlue);
                // paint Border
                if (getCell(x, y) == -1) painter.fillRect(r, Qt::darkGreen);
                break;
            case GamePredatorVictim:
                if (getCell(x, y) == 1) painter.fillRect(r, Qt::darkMagenta);
                if (getCell(x, y) == 2) painter.fillRect(r, Qt::yellow);
                if (getCell(x, y) == 3) painter.fillRect(r, Qt::green);
                break;
            default:
                break;
            }
        }
    }
    if (currentGame == GameSnake) {
            // Paint Food
            QPoint food = snake.getFood();
            qreal left  = (qreal) (cellWidth * food.x());
            qreal top   = (qreal) (cellHeight * food.y());
            QRectF r(left, top, cellWidth, cellHeight);
            painter.fillRect(r, Qt::red);
    }
}

void GameWidget::saveToFile() {
    switch (currentGame) {
        case GameOfLife: {
            QString fileName = QFileDialog::getSaveFileName(this,
                    tr("Save Current Universe"), "",
                    tr("Textfile (*.txt);;All Files (*)"));                 // Speicherdatei wird als *txt gespeichert

            QFile myFile(fileName);
            if (myFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
                    QTextStream stream(&myFile);
                    stream << getUniverseSize() << endl;                         // Spielfeldgröße wird gepeichert
                    for (int j = 0; j < getUniverseSize(); j++) {
                        for (int i = 0; i < getUniverseSize(); i++) {
                            stream << ca.getCell(i, j) << endl;             // komplettes Spielfeld wird mit 0 und 1 gespeichert
                        }
                    }
            }
            myFile.close();
            break;
        }
    case GameSnake: return; break;
    }
}

void GameWidget::loadFromFile() {
    switch (currentGame) {
        case GameOfLife: {
            QString fileName = QFileDialog::getOpenFileName(this,
                    tr("Load Saved Universe"), "",
                    tr("Textfile (*.txt);;All Files (*)"));                 // *txt wird geladen
            QFile myFile(fileName);
            if (myFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
                QTextStream in(&myFile);
                QString line = in.readLine();                               // nimmt die erste Zeile
                setUniverseSize(line.toInt());                              // Spielfeldgröße wird gelesen und geladen
                int i = 0;
                // jede Zeile wird durchgegangen und zu seiner Position im Array hinzugefügt
                while(!in.atEnd()) {
                    QString line = in.readLine();
                    //ca.getCurrentWorld()[i] = line.toInt();                 // Spielfeld wird gelesen und geladen
                    i++;
                }
            }
            myFile.close();
        }
        case GameSnake: return; break;
    }
}

void GameWidget::changeGame(int index) {
    stopGame();
    switch (index) {
    case 0:
        currentGame = GameOfLife;
        ca.setSize(50, 50);
        break;
    case 1:
        currentGame = GameSnake;
        snake.prepareFieldSnake();
        break;
    case 2:
        currentGame = GamePredatorVictim;
        predvic.prepareField();
        break;
    default:
        currentGame = GameOfLife;
        break;
    }
    update();
}

void GameWidget::changeMode(int index) {
    switch (index) {
    case 0:
        currentMode = Predator;
        break;
    case 1:
        currentMode = Victim;
        break;
    case 2:
        currentMode = Food;
        break;
    }
}

void GameWidget::changeLifeInterval(int interval)
{
    predvic.setLifeInterval(interval);
}

void GameWidget::keyPressEvent(QKeyEvent *event) {
    switch (currentGame) {
        case GameOfLife: return; break;
        case GameSnake:
            switch (event->key()) {
                case Qt::Key_Up:    snake.setDirection(snake.Up);   break;
                case Qt::Key_Left:  snake.setDirection(snake.Left); break;
                case Qt::Key_Down:  snake.setDirection(snake.Down); break;
                case Qt::Key_Right: snake.setDirection(snake.Right);break;

                case Qt::Key_W:     snake.setDirection(snake.Up);   break;
                case Qt::Key_A:     snake.setDirection(snake.Left); break;
                case Qt::Key_S:     snake.setDirection(snake.Down); break;
                case Qt::Key_D:     snake.setDirection(snake.Right);break;

                case Qt::Key_8:     snake.setDirection(snake.Up);   break;
                case Qt::Key_4:     snake.setDirection(snake.Left); break;
                case Qt::Key_2:     snake.setDirection(snake.Down); break;
                case Qt::Key_6:     snake.setDirection(snake.Right);break;
            }
            newGeneration();
            break;
        }
}

void GameWidget::checkGameOver() {
    if (snake.getEnd() == true) {
        clear();
    }
}
