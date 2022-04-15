#include "region.h"

#include <string>
#include <iostream>
using namespace std;

Region::Region(string nameIn)
{
  name=nameIn;
  initializeAllergyData();
}



string Region::getName() const
{
  return name;
}

char Region::getAllergen(const int row, const int col) const
{
  return area[row][col];
}



void Region::initializeAllergyData()
{
  const int percentAnimalDander = 21;
  const int percentDust = 37;

  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      int randomInt=rand() % 100 + 1;    // 1 to 100
      if(randomInt<=percentAnimalDander)
      {
        area[i][j]='A';
      }
      else if( randomInt<=(percentAnimalDander+percentDust) )
      {
        area[i][j]='D';
      }
      else
      {
        area[i][j]='P';
      }
    }
  }
  return;
}
