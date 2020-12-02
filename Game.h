//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Travel.cpp"
#include "Milestone.cpp"
#include "Calendar.cpp"
#include "Party.cpp"
#include "Inventory.cpp"
#include <iostream>
using namespace std;

class Game
{
    public:
    Game(int, int, int, int, string[], int);
    Game();

    //game needs start date, end date, party names, trip length, and initialized inventory of 0

    Travel getTripLength();
    Party getPartyNames();
    Inventory getPartyInventory();
    Calender getTripTime();

    //int here is for price going up as later shops are encountered
    void shopAction(double);
    void travelAction();
    void huntingAction();
    void banditEvent();
    void randEvent(int);
    void restEvent();
    bool turnMenu();
    bool puzzleSolve();

    private:
    Travel tripLength;
    Party partyNames;
    Inventory partyInventory;
    Calender tripTime;
};