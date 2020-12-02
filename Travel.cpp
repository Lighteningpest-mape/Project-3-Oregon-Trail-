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
    allMilestones;
}

Travel::Travel(Milestone inc_MS[32], int inc_MilesTraveled, int inc_totalMiles, int inc_currentMilestone, int num_MS)
{
    for(int i = 0; i < num_MS; i++)
    {
        allMilestones[i].setCurrentMilestone(inc_MS[i].getCurrentMilestone());
    }

    milesTraveled = inc_MilesTraveled;
    totalMiles = inc_totalMiles;
    currentMilestone = inc_currentMilestone;
}

//getters
int Travel::getMilesTraveled() const
{
    return milesTraveled;
}

int Travel::getTripLength() const
{
    return totalMiles;
}

Milestone Travel::getMilestone(int index)
{
    return allMilestones[index];
}

//setters
void Travel::setMilesTraveled(int inc_MilesTraveled)
{
    milesTraveled = inc_MilesTraveled;
}

void Travel::setTotalLength(int inc_length)
{
    totalMiles = inc_length;
}

//this function reads from an external file and puts each milestone name + milage into the appropriate place in the array
bool Travel::getAllMilestones(string inc_file)
{
    ifstream inFile;
    string currentLine;
    bool fileLoad = false;
    int i = 0;
    inFile.open(inc_file);

    if(inFile.is_open())
    {
        while(getline(inFile, currentLine))
        {
            if(i % 2 == 0)
            {
                allMilestones[i].setCurrentMilestone(currentLine);
            }
            else
            {
                allMilestones[i-1].setMilestoneMiles(stoi(currentLine));
            }

            i++;
        }
        fileLoad = true;
    }
    
    return fileLoad;
}

//this function will check the distance to the next milestone and return the difference between the 2
int Travel::checkMilestoneDistance()
{
    return milesTraveled - allMilestones[checkNearestMilestone()].getMilestoneMiles();
}

//returns the position (in the array) of the closest milestone ahead of the player
int Travel::checkNearestMilestone()
{
    int i = 0;
    while(milesTraveled - allMilestones[i].getMilestoneMiles() > 0)
    {
        i++;
    }

    return i;
}