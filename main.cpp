//Programmer: Logan Markley
//Student ID: 12579435
//MST Username: lcmkbc
//Instructor Name: San Yeung
//Section: 109
//Date: 4/11/22
//File: main.cpp
//Purpose: make an mapmaker program in C++ (HW 7)

#include "mapmaker.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
  srand(278);

  cout<<"Achoo! Allergy season has arrived in the Kingdom of LOG."<<endl;
  Region garden("The Hip Hop Garden");
  cout<<"King Logbob has tasked the mapmakers to explore and learn about the allergens in the region of "<<garden.getName()<<"."<<endl<<endl;
  Mapmaker m1;
  Mapmaker m2("Pamelia Angelina");
  cout<<"Welcome! Mapmaker "<<m1.getName()<<"."<<endl<<endl;
  cout<<"Let's also welcome your competitors: "<<m2.getName()<<"."<<endl;
  cout<<"Lets begin our adventure!!!"<<endl;

  int competitionRound=1;
  bool continueCompetition=true;
  do
  {
    cout<<endl<<"ROUND "<<competitionRound<<endl;
    cout<<"\t"<<m1.getName()<<":"<<endl;
    m1.explore(garden);
    if( m1.checkMap() ) //if mapmaker 1's map is INCOMPLETE
    {
      rockPaperScissors(m1, m2);

      cout<<"\t"<<m2.getName()<<":"<<endl;
      m2.explore(garden);
      if( m2.checkMap() ) //if mapmaker 2's map is INCOMPLETE
      {
        rockPaperScissors(m1, m2);
      }
      else
      {
        continueCompetition=false;
      }
    }
    else
    {
      continueCompetition=false;
    }
    competitionRound++;
  }while(competitionRound<=150 && continueCompetition);

  cout<<endl<<"COMPETITION SUMMARY:"<<endl;
  endSummary(m1);
  endSummary(m2);
  return 0;
}
