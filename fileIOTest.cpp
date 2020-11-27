#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct oregonScore
{
    int gameScore;
    string saveTitle;
};

bool saveScore(int score)
{
    //Creates a string to store the score title
    string title;

    //Asks the user for the title
    cout << "Enter a title for this score:: ";
    cin >> title;
    
    //Creates a vector, ifstream to start handling file I/O
    vector<oregonScore> scoreList(0);
    ifstream inFile;
    inFile.open("oregonSaveScores.txt"); //Opens the default save file
    

    //Loops through the file adding the scores to scoreList
    string curLine; //current line variable
    oregonScore curScore; //The oregonScore that will be pushed back onto scoreList
    while(getline(inFile, curLine))
    {
        if(curLine.length() != 0)
        {
            curScore.gameScore = stoi(curLine.substr(0, curLine.find(' '))); //The number that is before the space
            curScore.saveTitle = curLine.substr(curLine.find(' ') + 1, string::npos); //The title which is after
            scoreList.push_back(curScore);
        }
    }

    //Re-adds the scores to oregonSaveScores with the new score sorted in
    ofstream outFile;
    bool scoreAdded = false; //Checks to see if the score was already added
    outFile.open("oregonSaveScores.txt");
    for(int i = 0; i < scoreList.size(); i++)
    {
        if(score >= scoreList[i].gameScore && !scoreAdded)
        {
            //If the new score is larger than the current one, slot it in before.
            outFile << score << " " << title << endl;
            outFile << scoreList[i].gameScore << " " << scoreList[i].saveTitle << endl;
            scoreAdded = true;
        }
        else
        {
            //Else just keep the order the same
            outFile << scoreList[i].gameScore << " " << scoreList[i].saveTitle << endl;
        }
    }

    //If the scoreList(the save file) was empty, the loop wont run
    //Also, if the score is the smallest, it wouldn't be added
    //This is to cover both cases
    if(!scoreAdded)
    {
        //If the score isn't added, add the score ya know?
        outFile << score << " " << title << endl;
        scoreAdded = true;
    }

    //Returns if the score was successfully added
    return scoreAdded;
}

void printScores()
{
    //This function will print the top ten scores in the save file
    //Creates an ifstream object to open the save file
    ifstream inFile;
    inFile.open("oregonSaveScores.txt");

    //Reads and prints the top 10 scores if the file is openable
    string curLine; //The string holding the current line
    if(inFile.is_open())
    {
        for(int i = 0; i < 10; i++)
        {
            getline(inFile, curLine);
            if(curLine.length() != 0)//Only tries to print the line if it exists
            {
                cout << (curLine.substr(0, curLine.find(' '))); //The number that is before the space
                cout << " points by ";
                cout << curLine.substr(curLine.find(' ') + 1, string::npos) << endl; //The title which is after
            }
        }
    }
    else
    {
        cout << "The file couldn't be opened." << endl;
    }
}

int main()
{
    srand(time(NULL));
    int score = (double(rand()) / (double)((RAND_MAX)) * 100.0);
    saveScore(score);
    printScores();
}