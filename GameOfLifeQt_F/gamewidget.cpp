/*
    Fatih (), Javi (), Lesik (), Kelvin Tsang (5428328)

    Milestone 1

*/
#include "gamewidget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QRectF>
#include <QPainter>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
using namespace std;

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this))
{
    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
}

// Setter
void GameWidget::setTimerIntervall(int t) {timer->setInterval(t);}
void GameWidget::setUniverseSize(int size) {
    universeSize = size;
    ca.setSize(size, size);
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

void GameWidget::mousePressEvent(QMouseEvent *event) {
    double cellGeometry = 580.00/universeSize;
    int xPosition = event->x()/cellGeometry;
    int yPosition = event->y()/cellGeometry;
    if (ca.getCell(xPosition, yPosition) == 0) {
        ca.setCell(xPosition, yPosition, 1);
    }
    else ca.setCell(xPosition, yPosition, 0);
    update();
}

void GameWidget::mouseMoveEvent(QMouseEvent *event) {
    double cellGeometry = 580.00/universeSize;
    int xPosition = event->x()/cellGeometry;
    int yPosition = event->y()/cellGeometry;
    if (ca.getCell(xPosition, yPosition) == 0) {
        ca.setCell(xPosition, yPosition, 1);
    }
    update();
}

void GameWidget::paintEvent(QPaintEvent *)
{
    paintGrid();
    paintUniverse();
}

void GameWidget::paintGrid()
{
    QPainter painter(this);
    QRect rec(0, 0, 580.00, 580.00);
    double cellGeometry = 580.00 / universeSize;
    for(double i = 0; i <= 580.00; i += cellGeometry) {
        painter.drawLine(i, 0, i, 580.00);
        painter.drawLine(0, i, 580.00, i);
    }
    painter.drawRect(rec);
}

void GameWidget::paintUniverse() {
    QPainter painter(this);
    double cellGeometry = 580.00 / universeSize;
    for(int j = 0; j < universeSize; j++) {
        for(int i = 0; i < universeSize; i++) {
            if(ca.getCell(i, j) == 1) {
                QRectF rec(i * cellGeometry, j * cellGeometry, cellGeometry, cellGeometry);
                painter.fillRect(rec, Qt::black);                   // Zelle wird schwarz gefüllt
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
        QString line = in.readLine();
        setUniverseSize(line.toInt());                              // Spielfeldgröße wird gelesen und geladen
        int i = 0;
        while(!in.atEnd()) {
            QString line = in.readLine();
            ca.getCurrentWorld()[i] = line.toInt();                 // Spielfeld wird gelesen und geladen
            i++;
        }
    }

    myFile.close();
}
