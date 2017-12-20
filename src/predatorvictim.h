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
    void cellEvolutionDirection(int x, int y);
    void generateRandomWolrd();
    void randomMove(int x, int y);
    void eatNeighbor(int x, int y, int value);
    int neighbor(int x, int y, int value);
    bool legalityCheck(int x, int y);           //  1 | 2 | 3
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
};

#endif // PREDATORVICTIM_H
