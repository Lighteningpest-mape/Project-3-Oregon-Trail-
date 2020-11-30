//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Calender.h"
using namespace std;

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
    int days = 31;
    switch(initMonth)
    {
        case 1 : days = 31; break;
        case 2 : days = 28; break;
        case 3 : days = 31; break;
        case 4 : days = 30; break;
        case 5 : days = 31; break;
        case 6 : days = 30; break;
        case 7 : days = 31; break;
        case 8 : days = 31; break;
        case 9 : days = 30; break;
        case 10 : days = 31; break;
        case 11 : days = 30; break;
        case 12 : days = 31; break;

    }
    return days;
}