// CISP400V9AD4.cpp
// static data member tracking the number of objects of a class.
#include <iostream>
#include "Employee.h" // Employee class definition
#include "Time.h"// include Time class definition
#include "Date.h"// include Time class definition
#include "DateTime.h"// include DateTime class definition
using namespace std;

int main()
{
	Employee *ers [10];
   // no objects exist; use class name and binary scope resolution 
   // operator to access static member function getCount
   cout << "Number of employees before instantiation of any objects is "
      << Employee::getCount() << endl; // use class name

   // the following scope creates and destroys 
   // Employee objects before main terminates
   {Date hd1(2,30,2013), hd2(4,31,2014), hd3(9,31,2012), bd1(2,29,1985), bd2(11,30,1988), bd3(6,14, 19830);
    Time st1(23, 10, 30), st2(11,11,59), st3(0, 70, 70), zt(0, 0, 0);
	DateTime DTst1(10,9, 2013, st1), DTst2(12,25,2013, st2), DTst3(2,28,2014, st2), DTet1(0,0,0,zt), DTet2(0,0,0,zt), DTet3(0,0,0,zt);
    Employee e1( "Susan", "Baker",hd1, bd1, DTst1, DTet1 );
    Employee e2( "Robert", "Jones", hd2, bd2, DTst2, DTet2 );
	Employee e3( "John", "Lin", hd3, bd3, DTst3, DTet3 );
    // three objects exist; call static member function getCount again 
    // using the class name and the binary scope resolution operator
      cout << "Number of employees after objects are instantiated is "
         << Employee::getCount();
	//assignment Employee objects to Employee pointer array
	ers[0]=&e1;
	ers[1]=&e2;
	ers[2]=&e3;
	//usinjg for loop to call print function
	for (int i=0; i<3; i++)
	ers[i]->print();
	//provid training time needed for each employee in hours, minutes and seconds formate
	e1.setendDateTime(155,34,20);
	e2.setendDateTime(333,22,59);
	e3.setendDateTime(564,0,0);
    //using for loop to call print function to display the object data
		for (int i=0; i<3; i++)
	ers[i]->print();

   } // end nested scope in main

   // no objects exist, so call static member function getCount again 
   // using the class name and the binary scope resolution operator
   cout << "\nNumber of employees after objects are deleted is "
      << Employee::getCount() << endl;

   system("PAUSE");
} // end main
