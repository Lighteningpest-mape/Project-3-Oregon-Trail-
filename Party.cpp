//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Party.h";
using namespace std;

Party::Party()
{
    //The best Oregon trail party contains the best TMNT character and the four turtles
    partyInv = Inventory();
    partyNames[0] = "Leo";
    partyNames[1] = "Ralph";
    partyNames[2] = "Donnie";
    partyNames[3] = "Mikey";
    partyNames[4] = "April";
}
Party::Party(int food, int bullets, double money, int ox, int parts, int speed, string oneName, string twoName, string threeName, string fourName, string fiveName)
{
    partyInv = Inventory(food, bullets, money, ox, parts, speed);
    partyNames[0] = oneName;
    partyNames[1] = twoName;
    partyNames[2] = threeName;
    partyNames[3] = fourName;
    partyNames[4] = fiveName;
}

//getters
string Party::getLeaderName() const
{
    //The leader is the first member of the party
    return partyNames[0];
}
string Party::getMemberName(int partyPos) const
{
    return partyNames[partyPos];
}

//setters
void Party::setMemberName(string newName, int partyPos)
{
    //Primarily for trans members
    //Joke ^^
    partyNames[partyPos] = newName;
}