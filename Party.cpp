//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Party.h";
using namespace std;

Party::Party()
{
    //The best Oregon trail party contains the best TMNT character and the four turtles
    partyNames[0] = "Leo";
    partyNames[1] = "Ralph";
    partyNames[2] = "Donnie";
    partyNames[3] = "Mikey";
    partyNames[4] = "April";
    numPartyMembers = 5;

}
Party::Party(string oneName, string twoName, string threeName, string fourName, string fiveName)
{
    partyNames[0] = oneName;
    partyNames[1] = twoName;
    partyNames[2] = threeName;
    partyNames[3] = fourName;
    partyNames[4] = fiveName;
    numPartyMembers = 5;
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

int Party::getNumPartyMembers() const
{
    return numPartyMembers;
}

void Party::setNumPartyMembers(int inc_numPartyMembers)
{
    numPartyMembers = inc_numPartyMembers;
}

void Party::removeMember(int removeNumber)
{
    numPartyMembers--;
    //Loops replacing the removed member with the members after in the array
    for(int i = removeNumber; i < partyNames.length(); i++)
    {
        if(i + 1 < partyNames.length())
        {
            partyNames[i] = partyNames[i + 1];
        }
    }
    //Clears the last name to represent the loss
    partyNames[4] = "";
}
