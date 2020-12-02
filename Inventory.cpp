//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Inventory.h"
using namespace std;

Inventory::Inventory()
{
    /*
    int poundsFood;
    int numBullets;
    double cash;
    int oxen;
    int spareParts;
    int travelSpeed;
    */
   poundsFood = 0;
   numBullets = 0;
   cash = 0.0;
   oxen = 0;
   spareParts = 0;
   numMedKits = 0;
}
Inventory::Inventory(int food, int bullets, double money, int ox, int parts, int speed, int inc_numMedKits)
{
    poundsFood = food;
    numBullets = bullets;
    cash = money;
    oxen = ox;
    spareParts = parts;
    numMedKits = inc_numMedKits;
}

//getters
int Inventory::getFood() const
{
    return poundsFood;
}
int Inventory::getBullets() const
{
    return numBullets;
}
double Inventory::getCash() const
{
    return cash;
}
int Inventory::getOxen() const
{
    return oxen;
}
int Inventory::getSpareParts() const
{
    return spareParts;
}
int Inventory::getMedKits() const
{
    return numMedKits;
}


//setters
void Inventory::setFood(int food)
{
    poundsFood = food;
}
void Inventory::setBullets(int bullets)
{
    numBullets = bullets;
}
void Inventory::setCash(double money)
{
    cash = money;
}
void Inventory::setOxen(int ox)
{
    oxen = ox;
}
void Inventory::setSpareParts(int parts)
{
    spareParts = parts;
}
void Inventory::setMedKits(int meds)
{
    numMedKits = meds;
}