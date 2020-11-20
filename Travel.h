//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include <iostream>
#include "Milestone.cpp"
using namespace std;

class Travel
{
    public:
    Travel();
    Travel(Milestone [], int, int, int, int);

    //getter
    int getMilesTraveled() const;
    int getTripLength() const;

    //setter
    void setMilesTraveled(int);
    void setTotalLength(int);

    //other functions
    void getAllMilestones(string);
    int checkMilestoneDistance();

    private:
    Milestone allMilestones[];
    int milesTraveled;
    int totalMiles;
    int currentMilestone;
};