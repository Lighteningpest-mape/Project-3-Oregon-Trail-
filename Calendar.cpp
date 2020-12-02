//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Calender.h"
using namespace(std);

//I know its misspelled
Calender::Calender()
{
    initDay = 1;
    initMonth = 1;
    endDay = 31;
    endMonth = 12;
}

Calender::Calender(int startDay, int startMonth, int finalDay, int finalMonth)
{
    initDay = startDay;
    initMonth = startMonth;
    endDay = finalDay;
    endMonth = finalMonth;
}

    //getters
string Calender::getDate() const
{
    return to_string(initDay) + "/" + to_string(initMonth);
}
string Calender::getEndDate() const
{
    return to_string(endDay) + "/" + to_string(endMonth);
}

    //setters
void Calender::setDate(int newDay, int newMonth)
{
    initDay = newDay;
    initMonth = newMonth;
}
void Calender::setEndDate(int newEndDay, int newEndMonth)
{
    endDay = newEndDay;
    endMonth = newEndMonth;
}

//other functions
int Calender::monthCheck()
{
    //Switch statement to return the numbers of days in the month, no leap year
    int days = 30;

    return days;
}

void Calender::timeAdvance(int numDaysAdvanced)
{
    if(numDaysAdvanced + initDay > monthCheck())
    {
        initMonth++;
        initDay = numDaysAdvanced - initDay;
    }
    else
    {
        initDay = numDaysAdvanced + initDay;
    }
    
}