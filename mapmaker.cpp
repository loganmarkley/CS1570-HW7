#include "mapmaker.h"

#include <string>
#include <iostream>
using namespace std;

Mapmaker::Mapmaker()
{
  string nameIn;
  cout<<"Please enter the name of the first mapmaker: ";
  getline(cin, nameIn);
  name=nameIn;
  initializeMap();
}

Mapmaker::Mapmaker(string nameIn)
{
  name=nameIn;
  initializeMap();
}



string Mapmaker::getName() const
{
  return name;
}

char Mapmaker::getMapSpot(const int row, const int col) const
{
  return map[row][col];
}

int Mapmaker::getLocationsExplored() const
{
  return locationsExplored;
}

int Mapmaker::getRockPapScisGamesWon() const
{
  return rockPaperScisGamesWon;
}



void Mapmaker::initializeMap()
{
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      map[i][j]='U';
    }
  }
  return;
}

bool Mapmaker::checkMap()
{
  bool uLeft = false;
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      if( map[i][j]=='U' )
      {
        uLeft = true;
      }
    }
  }
  return uLeft;
}

void Mapmaker::explore(Region garden)
{
  int randomIntRow=rand() % rows;
  int randomIntCol=rand() % cols;
  cout<<"\t\tExploring location ["<<randomIntRow<<"]["<<randomIntCol<<"] ..."<<endl;
  if(map[randomIntRow][randomIntCol]=='U')
  {
    char allergen = garden.getAllergen(randomIntRow, randomIntCol);
    switch(allergen){
      case 'A':
        cout<<"\t\tAnimals shed serious dander!"<<endl;
        map[randomIntRow][randomIntCol]='A';
        break;
      case 'D':
        cout<<"\t\tDust will never leave!"<<endl;
        map[randomIntRow][randomIntCol]='D';
        break;
      case 'P':
        cout<<"\t\tPollen travels a long trajectory!"<<endl;
        map[randomIntRow][randomIntCol]='P';
        break;
    }
    locationsExplored++;
    unchartedLocationsLeft--;
  }
  else
  {
    cout<<"\t\tAchoo! This area is already explored!"<<endl;
  }
  cout<<"\t\tNumber of uncharted locations remaining: "<<unchartedLocationsLeft<<endl;
  return;
}



void rockPaperScissors(Mapmaker & mapmaker1, Mapmaker & mapmaker2)
{
  //0 is rock, 1 is paper, 2 is scissors
  int m1RandomInt = rand() % 3 ;
  int m2RandomInt = rand() % 3 ;
  if(m1RandomInt==m2RandomInt) //a tie
  {
    cout<<"\t\tRock Paper Scissors! It's a tie!"<<endl;
  }
  else if( (m1RandomInt==0 && m2RandomInt==1) || (m1RandomInt==1 && m2RandomInt==2) || (m1RandomInt==2 && m2RandomInt==0) ) //if mapmaker2 wins
  {
    cout<<"\t\tRock Paper Scissors! "<<mapmaker2.name<<" won!"<<endl;
    mapmaker2.rockPaperScisGamesWon++;
  }
  else //if mapmaker1 wins
  {
    cout<<"\t\tRock Paper Scissors! "<<mapmaker1.name<<" won!"<<endl;
    mapmaker1.rockPaperScisGamesWon++;
  }
  return;
}

void endSummary(Mapmaker & mm)
{
  cout<<"\t"<<mm.getName()<<":"<<endl;
  cout<<"\t\tMap:"<<endl;

  for(int i=0; i<rows; i++)
  {
    cout<<"\t\t\t";
    for(int j=0; j<cols; j++)
    {
      cout<<" "<<mm.getMapSpot(i, j);
    }
    cout<<endl;
  }
  cout<<"\t\tNumber of locations explored: "<<mm.getLocationsExplored()<<endl;
  cout<<"\t\tNumber of Rock Paper Scissors won: "<<mm.getRockPapScisGamesWon()<<endl;
  return;
}
