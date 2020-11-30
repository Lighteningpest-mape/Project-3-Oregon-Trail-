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
    const int tripLength = 2040;
    int userInput;
    int randNum;

    cout << "Welcome to The Oregon Trail! To begin, please enter the name of your party leader: ";
    cin >> temp_partyNames[0];
    
    for(int i = 1; i < 5; i++)
    {
        cout << "Now, enter the name of traveling companion " << i << ": ";
        cin >> temp_partyNames[i];
    }

    cout << "\nWould you like to choose a starting date? (Default is 03/28/1847) \n(1.) Yes; (2.) No: ";
    cin >> userInput;
    if(userInput == 1)
    {
        bool dateCheck;

        while(!dateCheck)
        {
            cout << "Enter your starting month (must be between March and May): ";
            cin >> userInput;

            if(startMonth >= 3 && startMonth <= 5)
            {
                startMonth = userInput;
                dateCheck = true;
            }
            else
            {
                 cout << "Invalid input. Please Re-enter.\n";
            }
        }

        dateCheck = false;

        while(!dateCheck)
        {
            cout << "Enter your starting day: ";
            cin >> userInput;
            if(startMonth == 3 || startMonth == 5)
            {
                if(userInput > 31)
                {
                    cout << "Invalid input. Please Re-enter.\n";
                }
                else
                {
                    startDay = userInput;
                    dateCheck = true;
                }
            }
            else if(startMonth == 4)
            {
                if(userInput > 30)
                {
                    cout << "Invalid input. Please Re-enter.\n";
                }
                else
                {
                    startDay = userInput;
                    dateCheck = true;
                }
                
            }
        }
        userInput = 1;
    }

    else if(userInput == 2)
    {
        cout << "The default date has been selected.\n";
    }
    else
    {
        cout << "Why would you put an invalid input here -_-. The default date will be selected.\n";
    }
    

    Game playerGame(startDay, startMonth, endDay, endMonth, temp_partyNames, tripLength);

    randNum = 10;

    while(playerGame.getPartyNames().getNumPartyMembers() != 0)
    {
        playerGame.randEvent(randNum);
        if(playerGame.getTripLength().checkMilestoneDistance() < 70 && playerGame.getTripLength().checkNearestMilestone() == || playerGame.getTripLength().checkNearestMilestone() ==  || playerGame.getTripLength().checkNearestMilestone() == )
        {
            cout << "Would you like to visit the outpost?\n(1.) Yes; (2.) No: ";
            cin >> userInput;
            if(userInput == 1)
            {
                
            }

        }
        playerGame.turnMenu();

        randNum = 1 + (rand() % 10);
    }

}