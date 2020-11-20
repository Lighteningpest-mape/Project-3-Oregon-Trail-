//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Milestone.h"

//default constructor
Milestone::Milestone()
{
    currentMilestone = "";
    milestoneMiles = 0;
}

//paramaterized constructor
Milestone::Milestone(string inc_mName, int inc_mMiles)
{
    currentMilestone = inc_mName;
    milestoneMiles = inc_mMiles;
}

//returns current milestone name
string Milestone::getCurrentMilestone() const
{
    return currentMilestone;
}

//returns distance (from spawn) to current milestone
int Milestone::getMilestoneMiles() const
{
    return milestoneMiles;
}

//sets current milestone name
void Milestone::setCurrentMilestone(string inc_MS)
{
    currentMilestone = inc_MS;
}

//sets current milestone location from "spawn"
void Milestone::setMilestoneMiles(int inc_MSmiles)
{
    milestoneMiles = inc_MSmiles;
}