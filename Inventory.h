#include <iostream>
using namespace std;

class Inventory
{
    public:
    Inventory();
    Inventory(int, int, double, int, int, int);

    //getters
    int getFood() const;
    int getBullets() const;
    double getCash() const;
    int getOxen() const;
    int getSpareParts() const;
    int getTravelSpeed() const;

    //setters
    void setFood(int);
    void setBullets(int);
    void setCash(double);
    void setOxen(int);
    void setSpareParts(int);
    void setTravelSpeed(int);

    private:
    int poundsFood;
    int numBullets;
    double cash;
    int oxen;
    int spareParts;
    int travelSpeed;
};
