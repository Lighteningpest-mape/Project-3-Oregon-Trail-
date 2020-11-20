#include <iostream>
#include "Milestone.cpp"
using namespace std;

class Travel
{
    public:
    Travel();
    Travel(Milestone, int, int, int);

    //getter
    int getMilesTraveled() const;
    int getTotalLength() const;

    //setter
    void setMilesTraveled(int);
    void setTotalLength(int);

    //other functions
    void getAllMilestones(string);
    int checkMilestoneDistance();

    private:
    Milestone allMilestones[];
    int milesTraveled;
    int totalMiles;
    int currentMilestone;
};