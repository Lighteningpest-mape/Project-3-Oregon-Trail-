//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Game.h"

Game::Game(int startDay, int startMonth, int endDay, int endMonth, string inc_partyNames[], int inc_trip)
{
    tripLength.setTotalLength(inc_trip);
    tripTime.setDate(startDay, startDay);
    tripTime.setEndDate(endDay, endMonth);
    
    for(int i = 0; i < 5; i++)
    {
        partyNames.setMemberName(inc_partyNames[i], i);
    }
}

void Game::shopAction(double inc_multiplier)
{

}

void Game::travelAction()
{
    if(partyInventory.getOxen() != 0)
    {
        int travelMiles = 70 + (rand() % 70);
        tripLength.setMilesTraveled(tripLength.getMilesTraveled() + travelMiles);
        partyInventory.setFood(partyInventory.getFood() - (14 * partyNames.getNumPartyMembers() * 3));
        tripTime.timeAdvance(14);
    }
    else
    {
        int travelMiles = 35 + (rand() % 35);
        tripLength.setMilesTraveled(tripLength.getMilesTraveled() + travelMiles);
        partyInventory.setFood(partyInventory.getFood() - (14 * partyNames.getNumPartyMembers() * 3));
        tripTime.timeAdvance(14);
    }
}

void Game::huntingAction()
{
    int randNum = (rand() % 100);
    int userChoice = 0;

    if(randNum < 50)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A RABBIT! DO YOU WANT TO HUNT: \n";
        cout << "(1) YES, (2) NO \nEnter Choice: ";
        cin >> userChoice;
        if(userChoice == 1)
        {
            if(partyInventory.getBullets() < 10)
            {
                cout << "Sorry, but the hunt was unsucessful.\n";
            }
            else
            {
                
            }
            
        }
        
    }

    if(randNum < 25)
    {

    }

    if(randNum < 15)
    {

    }

    if(randNum < 7)
    {

    }

    if(randNum < 5)
    {

    }
    tripTime.timeAdvance(1);
}

void Game::banditEvent()
{

}

void Game::randEvent(int randNum)
{
    switch(randNum)
    {
        //good events
        case 1:

        case 2:
        case 3:

        //bad events
        //ox dies
        case 4:
        if(partyInventory.getOxen() != 0)
        {
            cout << "One of your oxen has died!" << endl;
            partyInventory.setOxen(partyInventory.getOxen() - 1);
            if(partyInventory.getOxen() == 0)
            {
                cout << "With no oxen, you are forced to travel on foot." << endl;
            }
        }

        //wagon breaks down
        case 5:
        //someone gets sick
        case 6: 
        //someone gets bit by a snake
        case 7:

        //nothing happens
        default:
            cout << "The night passed uneventfully.\n";
            break;
    }
}

void Game::restEvent()
{
    int restDays = 1 + (rand() % 3);
    partyInventory.setFood(partyInventory.getFood() - (restDays * partyNames.getNumPartyMembers() * 3));
    tripTime.timeAdvance(restDays);
}

void Game::turnMenu()
{
    int userChoice;
    cout << "1. Rest; 2. Continue; 3. Hunt; 4. Quit\n";
    cout << "Enter Choice: ";
    cin >> userChoice;

    if(userChoice == 1)
    {

    }
}

Party Game::getPartyNames()
{
    return partyNames;
}