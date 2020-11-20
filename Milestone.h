//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include <iostream>
#include <fstream>
using namespace std;

class Milestone
{
    public:
    Milestone();
    Milestone(string, int);

    //getters
    string getCurrentMilestone() const;
    int getMilestoneMiles() const;

    //setters
    void setCurrentMilestone(string);
    void setMilestoneMiles(int);

    private:
    string currentMilestone;
    int milestoneMiles;
};