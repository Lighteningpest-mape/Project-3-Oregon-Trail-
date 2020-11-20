//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Travel.h"
#include <fstream>
using namespace std;

Travel::Travel()
{
    milesTraveled = 0;
    totalMiles = 0;
    currentMilestone = 0;
}

Travel::Travel(Milestone inc_MS[], int inc_MilesTraveled, int inc_totalMiles, int inc_currentMilestone, int num_MS)
{
    for(int i = 0; i < num_MS; i++)
    {
        allMilestones[i] = inc_MS[i];
    }

    milesTraveled = inc_MilesTraveled;
    totalMiles = inc_totalMiles;
    currentMilestone = inc_currentMilestone;
}

int Travel::getMilesTraveled() const
{
    return milesTraveled;
}

int Travel::getTripLength() const
{
    return totalMiles;
}

void Travel::setMilesTraveled(int inc_MilesTraveled)
{
    milesTraveled = inc_MilesTraveled;
}

void Travel::setTotalLength(int inc_length)
{
    totalMiles = inc_length;
}

void Travel::getAllMilestones(string inc_file)
{
   //this function will read from an external file and put each milestone name + milage into the appropriate place in the array
}

int Travel::checkMilestoneDistance()
{
    //this function will check the distance to the next milestone and return the difference between the 2
}