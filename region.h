#ifndef REGION_H
#define REGION_H

#include "constants.h"

#include <string>
#include <iostream>
using namespace std;

class Region{
  public:
    //desc: creates a Region object that has a random value of area and name
    //pre: none
    //post: a uninitialized Region object is created
    Region(){}
    //desc: creates a Region object with a name
    //      and calls initializeAllergyData() to initialize its area.
    //pre: none
    //post: the Region object has name = nameIn and its area is initialized
    Region(string nameIn);

    //desc: gets the private member variable name
    //pre: none
    //post: name is returned.
    string getName() const;
    //desc: gets the char value at area[row][col]
    //pre: 0 < row < rows  &&  0 < col < cols
    //     where rows and cols are the global constants in constants.h
    //post: returns the char at area[row][col]
    char getAllergen(const int row, const int col) const;


  private:
    char area[rows][cols];
    string name;

    //desc: using random number generation, EVERY element in the private member area is given
    //      a char value of 'A', 'D', or 'P'
    //pre: none
    //post: every element in area is successfully given one of the above values.
    void initializeAllergyData();
};



#endif
