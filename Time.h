// Fig. 9.4: Time.h
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp.

// prevent multiple inclusions of header 
#ifndef TIME_H
#define TIME_H

// Time class definition
class Time 
{
public:
    // default initializes to 23:59:58
   explicit Time( const int& = 23, const int& = 59, const int& = 58 ); // default constructor

   // set functions
   void setTime( const int&, const int&, const int& ); // set hour, minute, second
   void setHour( const int& ); // set hour (after validation)
   void setMinute( const int& ); // set minute (after validation)
   void setSecond( const int& ); // set second (after validation)

    // returns true on 00:00:00 tick (new day)
    bool tick();
   // get functions
   unsigned int getHour() const; // return hour
   unsigned int getMinute() const; // return minute
   unsigned int getSecond() const; // return second

   void printUniversal() const; // output time in universal-time format
   void printStandard() const; // output time in standard-time format
private:
   unsigned int hour; // 0 - 23 (24-hour clock format)
   unsigned int minute; // 0 - 59
   unsigned int second; // 0 - 59
}; // end class Time

#endif

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
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
