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
    Travel(Milestone[32], int, int, int, int);

    //getter
    int getMilesTraveled() const;
    int getTripLength() const;
    Milestone getMilestone(int);

    //setter
    void setMilesTraveled(int);
    void setTotalLength(int);

    //other functions
    bool getAllMilestones(string);
    int checkMilestoneDistance();
    int checkNearestMilestone();

    private:
    Milestone allMilestones[];
    int milesTraveled;
    int totalMiles;
    int currentMilestone;
};