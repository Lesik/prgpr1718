#ifndef PREDATORVICTIM_H
#define PREDATORVICTIM_H


class predatorvictim
{
public:
    predatorvictim();
    void prepareField();
    void worldEvolutionLifePredator();
    void setSize(int size);
    int getSize();
    void setLifeInterval(int interval);
    void setCell(int x, int y, int value);      // value:   1 = Predator
    int getCell(int x, int y);                  //          2 = Victim
private:                                        //          3 = Food
    enum Status { Dead, Predator, Victim, Food };
    void cellEvolutionDirection(QPoint point);
    void generateRandomWorld();
    void randomMove(QPoint point);
    void eatNeighbor(QPoint point, Status status);
    int neighbor(QPoint point, Status status);
    bool legalityCheck(QPoint point);           //  1 | 2 | 3
                                                //  4 | 5 | 6
                                                //  7 | 8 | 9
    int lifeInterval;

    int currentNeighbor[8];
    int numberNeighbor;

    int maxlife = 20;
    int ws; // Worldsize
    int** currentLife;
    int** nextgenLife;
    Status** currentStatus;
    Status** nextgenStatus;
    int** moveDirection;
    bool existsWolfAroundMe(QPoint point);
    QPoint getPointByInt(QPoint point, int direction);
    bool outOfBoundsCheck(QPoint point);
};

#endif // PREDATORVICTIM_H
