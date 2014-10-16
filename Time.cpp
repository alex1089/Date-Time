// Fig. 9.5: Time.cpp
// Member-function definitions for class Time.
#include <iostream>
#include <iomanip>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member 
Time::Time( const int& hour, const int& minute, const int& second ) 
{ 
   setTime( hour, minute, second ); // validate and set time
} // end Time constructor

// tick() increments state of object by 1 second, maintaining the validity of the other attributes
// returns true on 00:00:00 tick (new day)
bool Time::tick(){
    bool new_day=false;	    // variable to return if a new day started
    second++;	    // increment second by 1
    if (second>59){ // if second is incremented past range [0,59]
	second=0;   // reset second to one
	minute++;   // increment minute
	if (minute>59){	    // if minute is past its range [0,59]
	    minute=0;	    // set minute to 0
	    hour++;	    // increment hour by one
	    if (hour>23){   // if hour is incremented past its range [0,23]
		hour=0;
		new_day=true;
	    }
	}
    }
    return new_day;
}
// set new Time value using universal time, default to 23:59:58
void Time::setTime( const int& h=23, const int& m=59, const int& s=58 )
{
   setHour( h ); // set private field hour
   setMinute( m ); // set private field minute
   setSecond( s ); // set private field second
} // end function setTime

// set hour value
void Time::setHour( const int& h )
{
   if ( h >= 0 && h < 24 )
      hour = h;
   else
       hour = 0;    // set hour to 0 if out of range
} // end function setHour

// set minute value
void Time::setMinute( const int& m )
{
   if ( m >= 0 && m < 60 )
      minute = m; 
   else
       minute = 0;	// set minute to 0 if out of range
} // end function setMinute

// set second value
void Time::setSecond( const int& s )
{
   if ( s >= 0 && s < 60 )
      second = s;
   else
       second=0;    // set second to 0 if out of range
} // end function setSecond

// return hour value
unsigned int Time::getHour() const
{
   return hour;
} // end function getHour

// return minute value
unsigned int Time::getMinute() const
{
   return minute;
} // end function getMinute

// return second value
unsigned int Time::getSecond() const
{
   return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
   cout << setfill( '0' ) << setw( 2 ) << getHour() << ":"
      << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
   cout<<setfill(' ');	// reset fill to ' '
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
   cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
      << ":" << setfill( '0' ) << setw( 2 ) << getMinute()
      << ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
   cout<<setfill(' ');	// reset fill to ' '
} // end function printStandard

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
