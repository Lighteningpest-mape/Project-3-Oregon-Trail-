#include <iostream>
using namespace std;

class Calender
{
    public:
    Calender();
    Calender(int, int, int, int);

    //getters
    string getDate() const;
    string getEndDate() const;

    //setters
    void setDate(int, int);
    void setEndDate(int, int);

    //other functions
    int monthCheck();

    private:
    int initDay;
    int initMonth;
    int endDay;
    int endMonth;
};