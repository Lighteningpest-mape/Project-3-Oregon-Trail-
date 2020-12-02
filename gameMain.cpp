//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Game.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct oregonScore
{
    int gameScore;
    string saveTitle;
};

bool saveScore(int score)
{
    //Creates a string to store the score title
    string title;

    //Asks the user for the title
    cout << "Enter a title for this score:: ";
    cin >> title;
    
    //Creates a vector, ifstream to start handling file I/O
    vector<oregonScore> scoreList(0);
    ifstream inFile;
    inFile.open("oregonSaveScores.txt"); //Opens the default save file
    

    //Loops through the file adding the scores to scoreList
    string curLine; //current line variable
    oregonScore curScore; //The oregonScore that will be pushed back onto scoreList
    while(getline(inFile, curLine))
    {
        if(curLine.length() != 0)
        {
            curScore.gameScore = stoi(curLine.substr(0, curLine.find(' '))); //The number that is before the space
            curScore.saveTitle = curLine.substr(curLine.find(' ') + 1, string::npos); //The title which is after
            scoreList.push_back(curScore);
        }
    }

    //Re-adds the scores to oregonSaveScores with the new score sorted in
    ofstream outFile;
    bool scoreAdded = false; //Checks to see if the score was already added
    outFile.open("oregonSaveScores.txt");
    for(int i = 0; i < scoreList.size(); i++)
    {
        if(score >= scoreList[i].gameScore && !scoreAdded)
        {
            //If the new score is larger than the current one, slot it in before.
            outFile << score << " " << title << endl;
            outFile << scoreList[i].gameScore << " " << scoreList[i].saveTitle << endl;
            scoreAdded = true;
        }
        else
        {
            //Else just keep the order the same
            outFile << scoreList[i].gameScore << " " << scoreList[i].saveTitle << endl;
        }
    }

    //If the scoreList(the save file) was empty, the loop wont run
    //Also, if the score is the smallest, it wouldn't be added
    //This is to cover both cases
    if(!scoreAdded)
    {
        //If the score isn't added, add the score ya know?
        outFile << score << " " << title << endl;
        scoreAdded = true;
    }

    //Returns if the score was successfully added
    return scoreAdded;
}

void printScores()
{
    //This function will print the top ten scores in the save file
    //Creates an ifstream object to open the save file
    ifstream inFile;
    inFile.open("oregonSaveScores.txt");

    //Reads and prints the top 10 scores if the file is openable
    string curLine; //The string holding the current line
    if(inFile.is_open())
    {
        for(int i = 0; i < 10; i++)
        {
            getline(inFile, curLine);
            if(curLine.length() != 0)//Only tries to print the line if it exists
            {
                cout << (curLine.substr(0, curLine.find(' '))); //The number that is before the space
                cout << " points by ";
                cout << curLine.substr(curLine.find(' ') + 1, string::npos) << endl; //The title which is after
            }
        }
    }
    else
    {
        cout << "The file couldn't be opened." << endl;
    }
}

int main()
{
    string temp_partyNames [5];
    int startMonth = 3;
    int startDay = 28;
    const int endDay = 30;
    const int endMonth = 11;
    const int tripLength = 2040;
    bool gameEnd = false;
    int userInput;
    int randNum = 10;
    int score;
    double multiplier = 1.25;

    //collects party member names from user
    cout << "Welcome to The Oregon Trail! To begin, please enter the name of your party leader: ";
    cin >> temp_partyNames[0];
    for(int i = 1; i < 5; i++)
    {
        cout << "Now, enter the name of traveling companion " << i << ": ";
        cin >> temp_partyNames[i];
    }

    //gets custom date from user, if desired
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

    //performs "game startup" by creating game object 
    Game playerGame(startDay, startMonth, endDay, endMonth, temp_partyNames, tripLength);
    playerGame.getPartyInventory().setCash(1600);

    playerGame.shopAction(0.0);

    while(playerGame.getPartyNames().getNumPartyMembers() != 0 || gameEnd)
    {
        //checks if player is close to outpost
        if(playerGame.getTripLength().checkMilestoneDistance() < 70 && playerGame.getTripLength().checkNearestMilestone() == 2 || playerGame.getTripLength().checkNearestMilestone() == 4 || playerGame.getTripLength().checkNearestMilestone() == 7 || playerGame.getTripLength().checkNearestMilestone() == 10 || playerGame.getTripLength().checkNearestMilestone() == 12 || playerGame.getTripLength().checkNearestMilestone() == 14)
        {
            cout << "Would you like to visit the outpost?\n(1.) Yes; (2.) No: ";
            cin >> userInput;
            if(userInput == 1)
            {
                playerGame.shopAction(multiplier);
            }
            multiplier += .25;
        }

        //allows for player turn and checks for random event
        cout << "Food: " << playerGame.getPartyInventory().getFood() << " Bullets: " << playerGame.getPartyInventory().getBullets();
        cout << " Medkits: " << playerGame.getPartyInventory().getMedKits() << " Oxen: " << playerGame.getPartyInventory().getOxen();
        cout << "\nNearest Milestone: " << playerGame.getTripLength().getMilestone(playerGame.getTripLength().checkNearestMilestone()).getCurrentMilestone();
        cout << " Distance to Milestone: " << playerGame.getTripLength().checkMilestoneDistance() << endl;
        playerGame.turnMenu();
        playerGame.randEvent(randNum);
        randNum = 1 + (rand() % 10);
    }

    //score calculation
    score = playerGame.getPartyNames().getNumPartyMembers() * 1000 + playerGame.getTripLength().getMilesTraveled() * 100 + playerGame.getPartyInventory().getCash();

    if(!saveScore(score))
    {
        cout << "\nSorry, but your score was not saved successfully.\n";
    }
    else
    {
        cout << "Your score was saved successfully.\n";
    }
    
    cout << "Would you like to see the high scores? (1.) Yes (2.) No\n";
    cin >> userInput;
    if(userInput == 1)
    {
        printScores();
    }
    return 0;
}