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
                                                //  3 | x | 5
                                                //  5 | 6 | 8
    int lifeInterval;

    int currentNeighbor[8];
    int numberNeighbor;

    int ws; // Worldsize
    int** currentLife;
    int** nextgenLife;
    int** currentStatus;
    int** nextgenStatus;
    int** moveDirection;
    QPoint getPointByInt(QPoint point, int direction);
};

#endif // PREDATORVICTIM_H
