#ifndef MAPMAKER_H
#define MAPMAKER_H

#include "region.h"

#include <string>
#include <iostream>
using namespace std;

class Mapmaker{
  public:
    //desc: creates a Mapmaker object and prompts the user for their name and sets that input
    //      as the private member variable name. It then initializes their map array using initializeMap()
    //pre: none
    //post: the Mapmaker object has name = whatever the user enters and its map is initialized
    Mapmaker();
    //desc: creates a Mapmaker object and sets the parameter
    //      as the private member variable name. It then initializes their map array using initializeMap()
    //pre: none
    //post: the Mapmaker object has name = nameIn and its map is initialized
    Mapmaker(string nameIn);

    //desc: gets the private member variable name
    //pre: none
    //post: name is returned.
    string getName() const;
    //desc: gets the char value at map[row][col]
    //pre: 0 < row < rows  &&  0 < col < cols
    //     where rows and cols are the global constants in constants.h
    //post: returns the char at map[row][col]
    char getMapSpot(const int row, const int col) const;
    //desc: gets the private member variable locationsExplored
    //pre: none
    //post: locationsExplored is returned
    int getLocationsExplored() const;
    //desc: gets the private member variable rockPaperScisGamesWon
    //pre: none
    //post: rockPaperScisGamesWon is returned
    int getRockPapScisGamesWon() const;

    //desc: checks EVERY element of the private member variable map
    //      and returns true if there are any unexplored 'U' elements of map
    //pre: none
    //post: true is returned if there is at least one element of map containing 'U', false otherwise
    bool checkMap();
    //desc: generates a random position of an element of garden's area array. Then, if that same position
    //      is unexplored on this mapmaker's map array, their map is updated with the allergen at that spot.
    //      It does not change any values if that position has been visited before.
    //pre: garden's area variable must be initialized with chars of 'A', 'D', or 'P'
    //post: mapmaker's map is updated if its a new position, and the two variables locationsExplored
    //      and unchartedLocationsLeft are changed. unchartedLocationsLeft is also displayed to the user.
    void explore(Region garden);

    //desc: this friend function of Mapmaker generates two random values that correlate to rock, paper, and scissors.
    //      The winner of rock paper scissors has their member variable rockPaperScisGamesWon upped by 1. If it is a
    //      tie, neither of their values are changed
    //pre: none
    //post: the winner of the game is displayed and the winner's rockPaperScisGamesWon variable is increased
    friend void rockPaperScissors(Mapmaker & mapmaker1, Mapmaker & mapmaker2);
  private:
    string name;
    char map[rows][cols];
    int unchartedLocationsLeft=rows*cols;
    int locationsExplored=0;
    int rockPaperScisGamesWon=0;

    //desc: fills EVERY element of the private member variable map with the value of 'U'
    //pre: none
    //post: every element of map is now 'U'
    void initializeMap();
};

//desc: Displays the mm's name, their map array, their locationsExplored, and rockPaperScisGamesWon on separate lines.
//pre: none
//post: An organized summary of one Mapmaker object is displayed
void endSummary(Mapmaker & mm);
#endif
