// Fig. 9.20: Employee.cpp
// Employee class member-function definitions.
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>  // for strlen()
#include "Employee.h" // Employee class definition
#include "Date.h" // Date class definition
#include "DateTime.h" // DateTime class header
using namespace std;

int Employee::count=0;	// initialize static object counter

// Employee constructor, takes string objects of firstName and lastName
// takes two Date objects of hireDate and birthDate
// takes two DateTime objects of startDateTime and endDateTime
Employee::Employee( const char* fname, const char* lname, 
  const Date & hdate, const Date &bdate, const DateTime& startdate, const DateTime& enddate):
	firstName(fname),
	lastName(lname),
	birthDate(bdate),
	hireDate(hdate),
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
    endDateTime.print();
}
// testZeroDateTime() takes a DateTime object and returns true if all data members are 0
bool Employee::testZeroDateTime(const DateTime& dtObject) const{
    if (
	    dtObject.getHour()==0 &&
	    dtObject.getMinute()==0 &&
	    dtObject.getSecond()==0
       )
	return true;
    else
	return false;
}
// setendDateTime() takes int(hour,minute,second) of time until end of traning.
void Employee::setendDateTime(const int& h, const int& m, const int& s){
    int hour=h,minute=m,second=s,day=0;    // variables for processing time entered
    
    cout<<"\n  ***"<<getLastName()<<" "<<getFirstName()<<" needs "<<h
	<<" hours "<<m<<" minutes "<<s<<" seconds to finish training.\n";
    
    // set month, day, year of endDateTime to startDateTime
    endDateTime.setMonth(startDateTime.getMonth());
    endDateTime.setDay(startDateTime.getDay());
    endDateTime.setYear(startDateTime.getYear());

    minute=minute+second/60;
    second=second%60;		// if seconds>60, convert to minutes and add to minutes

    hour=hour+minute/60;
    minute=minute%60;		// if minutes>60, convert to hours and add to hours

    day=hour/8;		// 8 works= hours in 1 day, add number of days to days var
    hour=hour%8;
    cout<<"hhhhhh"<<hour<<"dddd"<<day;
    // endDateTime seconds = seconds of training + startDateTime seconds
    if (second>(60-startDateTime.getSecond())){    // if startTime.seconds+endTimeSeconds>60
	minute++;				    // increment minute by 1
	second=second-(60-startDateTime.getSecond());		// seconds left over after incrementing minute
    } else {
	second=second+startDateTime.getSecond();	// seconds=seconds start+seconds training
    }
    endDateTime.setSecond(second);  // set endTime second to left over seconds

    // endDateTime minutes = training minutes + startDateTime minutes
    if (minute>(60-startDateTime.getMinute())){	    // if startTime+training minutes >60 add hou
	hour++;
	minute=minute-(60-startDateTime.getMinute());    // minutes = left over minutes after hour
    } else {
	minute=minute+startDateTime.getMinute();	    // else, minutes= startTime+trainingTime
    }
    endDateTime.setMinute(minute);

    // endDateTime hours = training hours+startDateTime
    if (hour>(24-startDateTime.getHour())){	    // if hours training+startTime >60
	day++;		// add one day
	hour=hour-(24-startDateTime.getHour());   //  hours= left over hours after incrementing day
    }else {	    // else hours=startTime.hours+trainingTime.Hours
	hour=hour+startDateTime.getHour();
    }
    endDateTime.setHour(hour);

    for (int i=0;i<day;i++)		// endDateTime=startDateTime+iDays
	endDateTime.increaseADay();
    
    
}
// print() displays employee's name, hire date, birth date, and training start/end
void Employee::print() const
{
    int align_bdate,align_hdate=20;	    // width of padding necessary to align birthdate and hiredate column
    // align_width = padding necessary for birthdate to always stay 30 chars away from "Employee:"
    align_bdate=20-strlen(getLastName().c_str());
    if (birthDate.getMonth()>9)
	align_hdate--;	// if month in birthDate is a 2 digit number, padding-1
    if (birthDate.getDay()>9)
	align_hdate--;	// if day in birthDate is a 2 digit number, padding-1
    
    cout<<"\n\nEmployee: "<<getFirstName()<<" "<<setw(align_bdate)<<left<<getLastName();
    cout<<right<<"birthdate: "; getbirthDate();
    cout<<setw(align_hdate)<<"hire date: "; gethireDate();
    cout<<endl;
    
    cout<<"Training starts at "; getstartDateTime();
    cout<<endl;
    
    if (testZeroDateTime(endDateTime)){		// test if endDateTime is set to 0
	cout<<"No specified end training date and time.\n";
    } else {
	cout<<"Training ends at "; getendDateTime();
	cout<<endl;
    }

} // end function print
// getCount returns count of initialized employee objects
int Employee::getCount() 
{
    return count;
}
Employee::~Employee()
{ 
    count--;	// decrement count of Employee object on destruction
} // end ~Employee destructor

