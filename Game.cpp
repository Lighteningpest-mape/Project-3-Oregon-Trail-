//CSCI 1300 Fall 2020
//Author: Lyra Sturdivant & Marcus Pestcoe
//Recitation: 515 & 322
//Project 3

#include "Game.h"

Game::Game(int startDay, int startMonth, int endDay, int endMonth, string inc_partyNames[], int inc_trip)
{
    tripLength.setTotalLength(inc_trip);
    tripTime.setDate(startDay, startDay);
    tripTime.setEndDate(endDay, endMonth);
    
    for(int i = 0; i < 5; i++)
    {
        partyNames.setMemberName(inc_partyNames[i], i);
    }
}

void Game::shopAction(double inc_multiplier)
{
    int bill = 0;
    int temp_bill;
    int userChoice;
    bool advance = false;
    if(inc_multiplier = 0.0)
    {
        cout << "YOU HAVE SAVED $1600 TO SPEND FOR THIS TRIP, AND YOU HAVE A WAGON.";
        cout << "YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:\n";
        cout << "-- OXEN. YOU CAN SPEND $100 - $200 ON YOUR TEAM. THE MORE YOU SPEND, THE FASTER YOU'LL GO.\n";
        cout << "-- FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK.\n";
        cout << "-- AMMUNITION. YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS ANDBANDITS, AND FOR HUNTING FOOD.\n";
        cout << "-- MISC. SUPPLIES. THIS INCLUDES MEDICINE, SPARE WAGON PARTS, ETC.b\n";

        while(!advance)
        {
            cout << "Oxen- You must purchase between 3-5 yokes of oxen (each yoke = 2 oxen). Each yoke costs $40.\n";
            cout << "Please enter the number of yokes of oxen you wish to purchase: ";
            cin >> userChoice;
            if(userChoice > 5 || userChoice < 3)
            {
                cout << "You must purchase between 3 and 5 yokes of oxen.\n";
            }
            else
            {
                bill += userChoice * 40;
                cout << "Current bill: " << bill << endl;
                partyInventory.setOxen(userChoice * 2);
                advance = true;
            }
            
        }

        advance = false;
        
        while(!advance)
        {
            cout << "Food- You should purchase at least 200 pounds of food per person. Food costs 50c per pound.\n";
            cout << "Please enter how many pounds of food you would like to purchase: ";
            cin >> userChoice;
            if(userChoice * .5 + bill > partyInventory.getCash())
            {
                cout << "Sorry, but you do not have enough money to complete this transaction.";
            }
            else
            {
                bill += userChoice * .5;
                cout << "Current bill: " << bill << endl;
                partyInventory.setFood(userChoice);
                advance = true;
            }
        }

        advance = false;

        while(!advance)
        {
            cout << "Bullets- You will need bullets to hunt and defend yourself. Each box of 20 costs $2.\n";
            cout << "Please enter how many boxes of bullets you would like to purchase: ";
            cin >> userChoice;
            if(userChoice * 2 + bill > partyInventory.getCash())
            {
                cout << "Sorry, but you do not have enough money to complete this transaction.";
            }
            else
            {
                bill += userChoice * 2;
                cout << "Current bill: " << bill << endl;
                partyInventory.setBullets(userChoice * 20);
                advance = true;
            }
        }

        advance = false;

        while(!advance)
        {
            cout << "Wagon Parts- If the wagon breaks down, these will be used to fix it. Each wagon part costs $20.";
            cout << "Please enter how many wagon parts you would like to purchase: ";
            cin >> userChoice;
            partyInventory.setSpareParts(userChoice);

            cout << "Medical aid kits- If someone gets sick, these can help their chances of survival. Each kit costs $25.";
            cout << "Please enter how many medkits you would like to purchase: ";
            cin >> userChoice;

            if(userChoice * 25 + partyInventory.getSpareParts() * 20 + bill > partyInventory.getCash())
            {
             cout << "Sorry, but you do not have enough money to complete this transaction.";
             partyInventory.setSpareParts(0);
            }
            else
            {
                bill += userChoice * 25 + partyInventory.getSpareParts() * 20;
                cout << "Current bill: " << bill << endl;
                partyInventory.setMedKits(userChoice);
                advance = true;   
            }
        }

        partyInventory.setCash(partyInventory.getCash() - bill);
    }
    else
    {
        while(!advance)
        {
            cout << "Oxen- Each yoke costs $ "<< 40 * inc_multiplier << ".\n";
            cout << "Please enter the number of yokes of oxen you wish to purchase: ";
            cin >> userChoice;
            if(userChoice * (40 * inc_multiplier) + bill > partyInventory.getCash())
            {
                cout << "Sorry, but you do not have enough money to complete this transaction.";
            }
            else
            {
                bill += userChoice * 40;
                cout << "Current bill: " << bill << endl;
                partyInventory.setOxen(userChoice * 2);
                advance = true;
            }
            
        }

        advance = false;
        
        while(!advance)
        {
            cout << "Food costs " << 50 * inc_multiplier << "c per pound.\n";
            cout << "Please enter how many pounds of food you would like to purchase: ";
            cin >> userChoice;
            if(userChoice * (.5 * inc_multiplier) + bill > partyInventory.getCash())
            {
                cout << "Sorry, but you do not have enough money to complete this transaction.";
            }
            else
            {
                bill += userChoice * .5 * inc_multiplier;
                cout << "Current bill: " << bill << endl;
                partyInventory.setFood(userChoice);
                advance = true;
            }
        }

        advance = false;

        while(!advance)
        {
            cout << "Bullets- You will need bullets to hunt and defend yourself. Each box of 20 costs $" << 2 * inc_multiplier << ".\n";
            cout << "Please enter how many boxes of bullets you would like to purchase: ";
            cin >> userChoice;
            if(userChoice * (2 * inc_multiplier) + bill > partyInventory.getCash())
            {
                cout << "Sorry, but you do not have enough money to complete this transaction.";
            }
            else
            {
                bill += userChoice * 2 * inc_multiplier;
                cout << "Current bill: " << bill << endl;
                partyInventory.setBullets(userChoice * 20);
                advance = true;
            }
        }

        advance = false;

        while(!advance)
        {
            cout << "Wagon Parts- If the wagon breaks down, these will be used to fix it. Each wagon part costs $" << inc_multiplier * 20 << "." << endl;
            cout << "Please enter how many wagon parts you would like to purchase: ";
            cin >> userChoice;
            temp_bill = userChoice;

            cout << "Medical aid kits- If someone gets sick, these can help their chances of survival. Each kit costs $" << inc_multiplier * 25 << "." << endl;
            cout << "Please enter how many medkits you would like to purchase: ";
            cin >> userChoice;

            if(userChoice * 25 * inc_multiplier + temp_bill * 20 * inc_multiplier + bill > partyInventory.getCash())
            {
             cout << "Sorry, but you do not have enough money to complete this transaction.";
             partyInventory.setSpareParts(0);
            }
            else
            {
                bill += userChoice * 25 * inc_multiplier + partyInventory.getSpareParts() * 20 * inc_multiplier;
                cout << "Current bill: " << bill << endl;
                partyInventory.setMedKits(userChoice);
                advance = true;   
            }
        }
        partyInventory.setCash(partyInventory.getCash() - bill);
    }
    
}

//makes the party travel
void Game::travelAction()
{
    if(partyInventory.getOxen() > 3)
    {
        int travelMiles = 100 + (rand() % 40);
        tripLength.setMilesTraveled(tripLength.getMilesTraveled() + travelMiles);
        partyInventory.setFood(partyInventory.getFood() - (14 * partyNames.getNumPartyMembers() * 3));
        tripTime.timeAdvance(14);
    }
    else if(partyInventory.getOxen() == 1 || partyInventory.getOxen() == 2)
    {
        int travelMiles = 70 + (rand() % 70);
        tripLength.setMilesTraveled(tripLength.getMilesTraveled() + travelMiles);
        partyInventory.setFood(partyInventory.getFood() - (14 * partyNames.getNumPartyMembers() * 3));
        tripTime.timeAdvance(14);
    }
    else
    {
        int travelMiles = 35 + (rand() % 35);
        tripLength.setMilesTraveled(tripLength.getMilesTraveled() + travelMiles);
        partyInventory.setFood(partyInventory.getFood() - (14 * partyNames.getNumPartyMembers() * 3));
        tripTime.timeAdvance(14);
    }
}

//makes the party hunt
void Game::huntingAction()
{
    int randNum = (rand() % 100);
    int userChoice = 0;

    //rabbit hunt
    if(randNum < 50)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A RABBIT! DO YOU WANT TO HUNT: \n";
        cout << "(1) YES, (2) NO \nEnter Choice: ";
        cin >> userChoice;
        if(userChoice == 1)
        {
            if(partyInventory.getBullets() < 10)
            {
                cout << "Sorry, but the hunt was unsucessful.\n";
            }
            else
            {
                if(puzzleSolve())
                {
                    cout << "The hunt was successful! You have recieved 5 pounds of food.\n";
                    partyInventory.setFood(partyInventory.getFood() + 5);
                    partyInventory.setBullets(partyInventory.getBullets() - 10);
                }
                else
                {
                    cout << "Sorry, but the hunt was unsucessful.\n";
                }    
            } 
        }
    }

    //fox hunt
    if(randNum < 25)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A FOX! DO YOU WANT TO HUNT: \n";
        cout << "(1) YES, (2) NO \nEnter Choice: ";
        cin >> userChoice;
        if(userChoice == 1)
        {
            if(partyInventory.getBullets() < 10)
            {
                cout << "Sorry, but the hunt was unsucessful.\n";
            }
            else
            {
                if(puzzleSolve())
                {
                    cout << "The hunt was successful! You have recieved 10 pounds of food.\n";
                    partyInventory.setFood(partyInventory.getFood() + 10);
                    partyInventory.setBullets(partyInventory.getBullets() - 8);
                }
                else
                {
                    cout << "Sorry, but the hunt was unsucessful.\n";
                }        
            }
        }   
    }

    //deer hunt
    if(randNum < 15)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A DEER! DO YOU WANT TO HUNT: \n";
        cout << "(1) YES, (2) NO \nEnter Choice: ";
        cin >> userChoice;
        if(userChoice == 1)
        {
            if(partyInventory.getBullets() < 10)
            {
                cout << "Sorry, but the hunt was unsucessful.\n";
            }
            else
            {
                if(puzzleSolve())
                {
                    cout << "The hunt was successful! You have recieved 60 pounds of food.\n";
                    partyInventory.setFood(partyInventory.getFood() + 60);
                    partyInventory.setBullets(partyInventory.getBullets() - 5);
                }
                else
                {
                    cout << "Sorry, but the hunt was unsucessful.\n";
                }        
            }
        }

    }

    //bear hunt
    if(randNum < 7)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A BEAR! DO YOU WANT TO HUNT: \n";
        cout << "(1) YES, (2) NO \nEnter Choice: ";
        cin >> userChoice;
        if(userChoice == 1)
        {
            if(partyInventory.getBullets() < 10)
            {
                cout << "Sorry, but the hunt was unsucessful.\n";
            }
            else
            {
                if(puzzleSolve())
                {
                    cout << "The hunt was successful! You have recieved 200 pounds of food.\n";
                    partyInventory.setFood(partyInventory.getFood() + 200);
                    partyInventory.setBullets(partyInventory.getBullets() - 10);
                }
                else
                {
                    cout << "Sorry, but the hunt was unsucessful.\n";
                }        
            }
        }
    }

    //moose hunt
    if(randNum < 5)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A MOOSE! DO YOU WANT TO HUNT: \n";
        cout << "(1) YES, (2) NO \nEnter Choice: ";
        cin >> userChoice;
        if(userChoice == 1)
        {
            if(partyInventory.getBullets() < 12)
            {
                cout << "Sorry, but the hunt was unsucessful.\n";
            }
            else
            {
                if(puzzleSolve())
                {
                    cout << "The hunt was successful! You have recieved 500 pounds of food.\n";
                    partyInventory.setFood(partyInventory.getFood() + 500);
                    partyInventory.setBullets(partyInventory.getBullets() - 12);
                }
                else
                {
                    cout << "Sorry, but the hunt was unsucessful.\n";
                }     
            }
        }
    }

    cout << "How well do you want to eat?\n(1.)Poorly; (2.)Moderately; (3.)Well: ";
    cin >> userChoice;

    switch(userChoice)
    {
        //poor meal
        case 1:
            partyInventory.setFood(partyInventory.getFood() - (partyNames.getNumPartyMembers() * 2));
            break;

        //moderate meal
        case 2:
            partyInventory.setFood(partyInventory.getFood() - (partyNames.getNumPartyMembers() * 3));
            break;

        //good meal
        case 3:
            partyInventory.setFood(partyInventory.getFood() - (partyNames.getNumPartyMembers() * 5));
            break;

        default:
            cout << "Invalid option. Moderate meal selected.";
            partyInventory.setFood(partyInventory.getFood() - (partyNames.getNumPartyMembers() * 3));
            break;
    }

    if(partyInventory.getFood() > 1000)
    {
        cout << "\nThe wagon can only hold 1000 pounds. Excess food will be left behind.";
        partyInventory.setFood(1000);
    }

    tripTime.timeAdvance(1);
}

//party is attacked by bandits
void Game::banditEvent()
{

}

void Game::randEvent(int randNum)
{
    int memberSelector = rand() % 5;
    int deathChance = rand() % 10;
    string temp_nameStore [5];
    int i = 0;
    int userChoice;

    switch(randNum)
    {
        //good events
        //find wagon part
        case 1:
            cout << "You find a spare wagon part lying on the side of the road.";
            partyInventory.setSpareParts(partyInventory.getSpareParts() + 1);
            break;

        //bad events
        //ox dies
        case 2:
            if(partyInventory.getOxen() > 0)
            {
                cout << "One of your oxen has died! You have " << partyInventory.getOxen() - 1 << " oxen left." << endl;
                partyInventory.setOxen(partyInventory.getOxen() - 1);
                if(partyInventory.getOxen() == 0)
                {
                    cout << "With no oxen, you are forced to travel on foot." << endl;
                }
            }
            break;

        //wagon breaks down
        case 3:
            cout << "The wagon has broken down." << endl;
            if(partyInventory.getSpareParts() > 0)
            {
                cout << "You fix the wagon and move on." << endl;
                partyInventory.setSpareParts(partyInventory.getSpareParts() - 1);
            }
            else
            {
                cout << "With no spare parts, your journey is over. :(";
                partyNames.setNumPartyMembers(0);
            }
            break;

        //someone gets sick
        case 4: 
            cout << "OH NO! " << partyNames.getMemberName(memberSelector) << " is sick!" << endl;
            if(partyInventory.getMedKits() > 0)
            {
                cout << "A medkit has been used." << endl;
                if(deathChance >= 5)
                {
                    cout << partyNames.getMemberName(memberSelector) << "has recovered." << endl;
                }
                else
                {
                    cout << partyNames.getMemberName(memberSelector) << "has died." << endl;;
                    if(partyNames.getMemberName(memberSelector) == partyNames.getLeaderName())
                    {
                        cout << "GAME OVER.";
                        partyNames.setNumPartyMembers(0);
                    }
                    else
                    {
                        while(partyNames.getMemberName(i) != partyNames.getMemberName(memberSelector))
                        {
                            temp_nameStore[i] = partyNames.getMemberName(i);
                            i++;
                        }
                        i++;
                        while(i < 5)
                        {
                            temp_nameStore[i] = partyNames.getMemberName(i);
                            i++;
                        }

                        partyNames.removeMember();

                        for(int j = 0; j < partyNames.numPartyMembers(); j++)
                        {
                            partyNames.setMemberName(temp_nameStore[j]);
                        }
                    }
                    
                }
                
            }
            else
            {
                cout << "Would you like to rest or press on? (1.) Rest; (2.) Press on!" << endl;
                cin >> userChoice;

                if(userChoice == 1)
                {
                    restEvent();
                    restEvent();
                    restEvent();
                    if(deathChance < 3)
                    {
                        cout << partyNames.getMemberName(memberSelector) << "has recovered." << endl;
                    }
                    else
                    {
                        cout << partyNames.getMemberName(memberSelector) << "has died." << endl;;
                        if(partyNames.getMemberName(memberSelector) == partyNames.getLeaderName())
                        {
                            cout << "GAME OVER.";
                            partyNames.setNumPartyMembers(0);
                        }
                        else
                        {
                            while(partyNames.getMemberName(i) != partyNames.getMemberName(memberSelector))
                            {
                                temp_nameStore[i] = partyNames.getMemberName(i);
                                i++;
                            }
                            i++;
                            while(i < 5)
                            {
                                temp_nameStore[i] = partyNames.getMemberName(i);
                                i++;
                            }

                            partyNames.removeMember();

                            for(int j = 0; j < partyNames.numPartyMembers(); j++)
                            {
                                partyNames.setMemberName(temp_nameStore[j]);
                            }
                        }
                        
                    }
                }
                else
                {
                    if(deathChance < 7)
                    {
                        cout << partyNames.getMemberName(memberSelector) << "has recovered." << endl;
                    }
                    else
                    {
                        cout << partyNames.getMemberName(memberSelector) << "has died." << endl;;
                        if(partyNames.getMemberName(memberSelector) == partyNames.getLeaderName())
                        {
                            cout << "GAME OVER.";
                            partyNames.setNumPartyMembers(0);
                        }
                        else
                        {
                            while(partyNames.getMemberName(i) != partyNames.getMemberName(memberSelector))
                            {
                                temp_nameStore[i] = partyNames.getMemberName(i);
                                i++;
                            }
                            i++;
                            while(i < 5)
                            {
                                temp_nameStore[i] = partyNames.getMemberName(i);
                                i++;
                            }

                            partyNames.removeMember();

                            for(int j = 0; j < partyNames.numPartyMembers(); j++)
                            {
                                partyNames.setMemberName(temp_nameStore[j]);
                            }
                        }
                        
                    }
                }
                
            }    
            

        //nothing happens
        default:
            cout << "The night passed uneventfully.\n";
            break;
    }
}

void Game::restEvent()
{
    int restDays = 1 + (rand() % 3);
    partyInventory.setFood(partyInventory.getFood() - (restDays * partyNames.getNumPartyMembers() * 3));
    tripTime.timeAdvance(restDays);
}

bool Game::turnMenu()
{
    int userChoice;
    cout << "1. Rest; 2. Continue; 3. Hunt; 4. Quit\n";
    cout << "Enter Choice: ";
    cin >> userChoice;

    switch(userChoice)
    {
        case 1:
            restEvent();
        case 2:
            travelAction();
        case 3:
            huntingAction();
            break;
        case 4:
            cout << "Bye!";
            return true;
            break;
        default:
            cout << "Invalid choice selected. You will rest.";
            restEvent();
            break;
    }
    return false;
}

bool Game::puzzleSolve()
{
    int randNum = 1 + (rand() % 10);

    cout << ""

}

Party Game::getPartyNames()
{
    return partyNames;
}

Travel Game::getTripLength()
{
    return tripLength;
}

Inventory Game::getPartyInventory()
{
    return partyInventory;
}

Calender Game::getTripTime()
{
    return tripTime;
}