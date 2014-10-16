// Fig. 9.19: Employee.h
// Employee class definition showing composition.
// Member functions defined in Employee.cpp.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h" // include Date class definition
#include "DateTime.h" // DateTime definition

class Employee
{
public:
    // Employee constructor, takes string objects of firstName and lastName
    // takes two Date objects of hireDate and birthDate
    // takes two DateTime objects of startDateTime and endDateTime
   Employee( const char* , const char*, 
      const Date &, const Date &, const DateTime&, const DateTime&);
   // getFirstName() returns a string of object's firstname
   std::string getFirstName() const;
   // getLastName() returns a string object of employee's last name
   std::string getLastName() const;
   // gethireDate() displays hireDate object status
   void gethireDate() const;
   // getBirthDate() displays birthDate object state
   void getbirthDate() const;
   // getstartDateTime() displays startDateTime object state
   void getstartDateTime() const;
   // getendDateTime() displays endDateTime object state
   void getendDateTime() const;
   // testZeroDateTime() takes a DateTime object and returns true if all data members are 0
   bool testZeroDateTime(const DateTime&) const;
   // setendDateTime() takes int(hour,minute,second) of time until end of traning.
   void setendDateTime(const int&, const int&, const int&);
   // print() displays employee's name, hire date, birth date, and training start/end
   void print() const;
   // getCount returns count of initialized employee objects
   static int getCount() ;
   ~Employee(); // provided to confirm destruction order
private:
   std::string firstName; // composition: member object
   std::string lastName; // composition: member object
   Date birthDate; // composition: member object
   Date hireDate; // composition: member object
   DateTime startDateTime;
   DateTime endDateTime;
   static int count;
}; // end class Employee

#endif

/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
