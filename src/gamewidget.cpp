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

#include "gamewidget.h"
using namespace std;

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this))
{
    // der Timer wird mit dem Slot newGeneration verbunden
    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
}

// Setter
void GameWidget::setTimerIntervall(int t) {timer->setInterval(t);}
void GameWidget::setUniverseSize(int size) {
    universeSize = size;
    ca.setSize(size, size);
    // update damit die neue Groeße die mit der Spinbox veraendert wurde
    // angezeigt wird
    update();
}

// Start, Stop und Clear Funktion
void GameWidget::startGame() {timer->start();}
void GameWidget::stopGame() {timer->stop();}
void GameWidget::clear() {setUniverseSize(universeSize);}

void GameWidget::newGeneration() {
    ca.evolve();        // evolve() von CAbase
    update();
}

// wenn die Maustaste geklickt worden ist, soll die Funktion ausgeführt werden
void GameWidget::mousePressEvent(QMouseEvent *event) {
    // 580 ist die Groeße die wir im mainwindow.ui festgelegt haben
    double cellGeometry = 580.00/universeSize;
    // hier wird die Position des Mauszeigers abgefragt
    int xPosition = event->x()/cellGeometry;
    int yPosition = event->y()/cellGeometry;
    // je nach dem ob die lebendig war oder nicht wird sie invertiert
    if (ca.getCell(xPosition, yPosition) == 0) {
        ca.setCell(xPosition, yPosition, 1);
    }
    else ca.setCell(xPosition, yPosition, 0);
    update();
}

// wenn die Maustaste geklickt worden ist, soll die Funktion ausgeführt werden
void GameWidget::mouseMoveEvent(QMouseEvent *event) {
    double cellGeometry = 580.00/universeSize;
    int xPosition = event->x()/cellGeometry;
    int yPosition = event->y()/cellGeometry;
    if (ca.getCell(xPosition, yPosition) == 0) {
        ca.setCell(xPosition, yPosition, 1);
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

// wird ausgefuert wenn update() ausgefuehrt wurde
void GameWidget::paintEvent(QPaintEvent *event)
{
    double cellWidth = (double) width() / ca.getNx();
    double cellHeight = (double) height() / ca.getNy();
    paintGrid(event, cellWidth, cellHeight);

    // initiate painter
    QPainter painter(this);
    // for each cell in world, if is alive
    for (int x = 0; x < ca.getNx(); x++) {
        for (int y = 0; y < ca.getNy(); y++) {
            if (ca.getCell(x, y)==1) {
                // calculate left and top edges by calculating distance from top left edge
                qreal left = (qreal) (cellWidth * x);
                qreal top = (qreal) (cellHeight * y);
                // the cell should be cellWidth wide and cellHeight tall
                QRectF r(left, top, (qreal) cellWidth, (qreal) cellHeight);
                painter.fillRect(r, Qt::darkBlue);
            }
        }
    }
}

void GameWidget::saveToFile() {
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Current Universe"), "",
            tr("Textfile (*.txt);;All Files (*)"));                 // Speicherdatei wird als *txt gespeichert

    QFile myFile(fileName);
    if (myFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream stream(&myFile);
            stream << universeSize << endl;                         // Spielfeldgröße wird gepeichert
            for (int j = 0; j < universeSize; j++) {
                for (int i = 0; i < universeSize; i++) {
                    stream << ca.getCell(i, j) << endl;             // komplettes Spielfeld wird mit 0 und 1 gespeichert
                }
            }
    }
    myFile.close();
}

void GameWidget::loadFromFile() {
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

void GameWidget::changeGame(int index) {
    ca.changeGame(index);
    update();
}

void GameWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Up:    snake.setDirection(snake.Up); break;
        case Qt::Key_Left:  snake.setDirection(snake.Left); break;
        case Qt::Key_Down:  snake.setDirection(snake.Down); break;
        case Qt::Key_Right: snake.setDirection(snake.Right); break;

        case Qt::Key_W:     snake.setDirection(snake.Up); break;
        case Qt::Key_A:     snake.setDirection(snake.Left); break;
        case Qt::Key_S:     snake.setDirection(snake.Down); break;
        case Qt::Key_D:     snake.setDirection(snake.Right); break;

        case Qt::Key_8:     snake.setDirection(snake.Up); break;
        case Qt::Key_4:     snake.setDirection(snake.Left); break;
        case Qt::Key_2:     snake.setDirection(snake.Down); break;
        case Qt::Key_6:     snake.setDirection(snake.Right); break;
    }
    newGeneration();
}
