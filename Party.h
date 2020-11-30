#include <iostream>
#include "Inventory.cpp"
using namespace std;

class Party
{
    public:
    Party();
    Party(int, int, double, int, int, int, string, string, string, string, string);

    //getters
    string getLeaderName() const;
    string getMemberName(int) const;

    //setters
    void setMemberName(string, int);

    private:
    string partyNames[5];
    Inventory partyInv;
};