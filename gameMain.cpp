//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string temp_partyNames [5];
    int startMonth = 3;
    int startDay = 28;
    const int endDay = 30;
    const int endMonth = 11;

    cout << "Welcome to The Oregon Trail! To begin, please enter the name of your party leader: ";
    cin >> temp_partyNames[0];
    
    for(int i = 1; i < 5; i++)
    {
        cout << "Now, enter the name of traveling companion " << i << ": ";
        cin >> temp_partyNames[i];
    }
    

}