#include <iostream>
#include "Inventory.cpp"
using namespace std;

class Party
{
    public:
    Party();
    Party(string, string, string, string, string);

    //getters
    string getLeaderName() const;
    string getMemberName(int) const;
    int getNumPartyMembers() const;

    //setters
    void setMemberName(string, int);
    void setNumPartyMembers(int);

    //other
    void removeMember();

    private:
    string partyNames[5];
    int numPartyMembers;
};