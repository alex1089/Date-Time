// Fig. 9.20: Employee.cpp
// Employee class member-function definitions.
#include <iostream>
#include "Employee.h" // Employee class definition
#include "Date.h" // Date class definition
#include "DateTime.h" // DateTime class header
using namespace std;

int DateTime::count=0;	// initialize static object counter
// print Employee object
// Employee constructor, takes string objects of firstName and lastName
// takes two Date objects of hireDate and birthDate
// takes two DateTime objects of startDateTime and endDateTime
Employee::Employee( const string & fname, const string & lname, 
  const Date & hdate, const Date &bdate, const DateTime& startdate, const DateTime& enddate):
	firstName(fname),
	lastName(lname,
	hireDate(hdate),
	birthDate(bdate),
	startDateTime(startdate),
	endDateTime(enddate){
    count++;	// increment count for every Employee object initialized
}
	
// getFirstName() returns a string of object's firstname
string Employee::getFirstName() const {
    return firstName;
}
// getLastName() returns a string object of employee's last name
string Employee::getLastName() const{
    return lastName;
}
// gethireDate() displays hireDate object status
void Employee::gethireDate() const{
    hireDate.print();
}
// getBirthDate() displays birthDate object state
void Employee::getbirthDate() const{
    birthDate.print();
}
// getstartDateTime() displays startDateTime object state
void Employee::getstartDateTime() const{
    startDateTime.print();
}
// getendDateTime() displays endDateTime object state
void Employee::getendDateTime() const{
    getendDateTime.print();
}
// testZeroDateTime() takes a DateTime object and returns true if all data members are 0
bool Employee::testZeroDateTime(const DateTime& dtObject) const{
    if (dtObject.getMonth()==0 &&
	    dtObject.getYear()==0 &&
	    dtObject.getDay()==0 &&
	    dtObject.getHour()==0 &&
	    dtObject.getMinute()==0 &&
	    dtObject.getSecond()==0)
	return true;
    else
	return false;
}
// setendDateTime() takes int(hour,minute,second) of time until end of traning.
void Employee::setendDateTime(const int& h, const int& m, const int& s){
    int hour=h,minutes=m,second=s,day=0;    // variables for processing time entered
    // set month, day, year of endDateTime to startDateTime
    endDateTime.setMonth(startDateTime.getMonth());
    endDateTime.setDay(startDateTime.getDay());
    endDateTime.setYear(startDateTime.getYear());

    minutes=minutes+second/60;
    second=second%60;		// if seconds>60, convert to minutes and add to minutes

    hours=hours+minutes/60;
    minutes=minutes%60;		// if minutes>60, convert to hours and add to hours

    days=hours/24;		// 24 hours in 1 day, add number of days to days var
    hours=hours%24;

    // endDateTime seconds = seconds of training + startDateTime seconds
    if (seconds>(60-startDateTime.getSecond())){    // if startTime.seconds+endTimeSeconds>60
	minutes++;				    // increment minute by 1
	seconds=seconds-(60-startDateTime.getSecond());		// seconds left over after incrementing minute
    } else {
	seconds=seconds+startDateTime.getSeconds();	// seconds=seconds start+seconds training
    }
    endDateTime.setSecond(seconds);  // set endTime second to left over seconds

    // endDateTime minutes = training minutes + startDateTime minutes
    if (minutes>(60-startDateTime.getMinutes)){	    // if startTime+training minutes >60 add hou
	hours++;
	minutes=minutes-(60-startDateTime.getMinutes());    // minutes = left over minutes after hour
    } else {
	minutes=minutes+startDateTime.getMinutes();	    // else, minutes= startTime+trainingTime
    }
    endDateTime.setMinute(minutes);

    // endDateTime hours = training hours+startDateTime
    if (hours>(24-startDateTime.getHour())){	    // if hours training+startTime >60
	days++		// add one day
	hours=hours-(24-startDateTime.getHour());   //  hours= left over hours after incrementing day
    }else {	    // else hours=startTime.hours+trainingTime.Hours
	hours=hours+startDateTime.getHour();
    }
    endDateTime.setHour(hours);

    for (int i=0;i<days;i++)		// endDateTime=startDateTime+iDays
	endDateTime.increaseADay();
    
    
}
// print() displays employee's name, hire date, birth date, and training start/end
void Employee::print() const
{
    cout<<"Employee: "<<getFirstName()<<" "<<getLastName()<<;
    cout<<setw(28)<<right<<"birthdate: "<<getbirthDate();
    cout<<setw(30)<<"hire date: "<<gethireDate()<<endl;
    
    cout<<"Training starts at "<<getstartDateTime()<<endl;
    if (testZeroDateTime(endDateTime)){		// test if endDateTime is set to 0
	cout<<"No specified end training date and time.\n";
    } else {
	cout<<"Training ends at "<<getendDateTime()<<endl;
    }

} // end function print
// getCount returns count of initialized employee objects
static int Employee::getCount() const
{
    return count;
}
Employee::~Employee()
{ 
    count--;	// decrement count of Employee object on destruction
} // end ~Employee destructor

