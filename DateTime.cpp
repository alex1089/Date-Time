// Aleksey Leshchuk
// DateTime class definition

#include "DateTime.h"
#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

// default constructor, takes int of Month, Day, Year, and a Time object
DateTime::DateTime(const int& m=0, const int& d=0, const int& y=0, const Time& t=Time(0,0,0)){
    setYear(y);
    setMonth(m);
    setDay(d);
    } 
// print function, prints Month, Day, Year and Time information
void DateTime::print() const{
    cout<<month<<"/"<<day<<"/"<<year<<" "<<time.printStandard();
}
// increaseADay function increase the date by a day
void DateTime::increaseADay(){
    if (checkDay(day+1)){   // if next day is valid, set day to day+1
	day+=1;
    } else {		    // else set day to 1 and increment month
	day=1;
	increaseAMonth();
    }
}

// increases month
void DateTime::increaseAMonth(){
    if (month==12){
	month=1;
	increaseAYear();
    } else {
	month+=1;
    }
}

// increases the year by one
void DateTime::increaseAYear(){
    year+=1;
}
	
// increases the Time object by a second, while maintaining validity of other attributes
void DateTime::tick(){
    if (time.tick())  // call tick method of Time class, returns true if new day started
	increaseADay();
}
// getMonth returns int month
int DateTime::getMonth() const{
    return month;
}
// getYear returns int year
int DateTime::getYear() const{
    return year;
}
// getDay returns int day
int DateTime::getDay() const{
    return day;
}
// setMonth validates and sets month
void DateTime::setMonth(const int& m){
    if (m<=monthsPerYear && m!=0){
	month=m;
    } else {
	cout<<"Invalid month ("<<m<<") set to 1.\n";
	month=1;
    }
}
// setYear validates year is between 1920-2020, else sets to 2011
void DateTime::setYear(const int& y){
    if (y>=1920 && y<=2020){
	year=y;
    } else {
	cout<<"Invalid year ("<<y<<") set to 2011.\n";
	year=2011;
    }
}
// setDay validates day using checkDay() and sets
void DateTime::setDay(const int& d){
    if (checkDay(d)){  // if day is valid
	day=d;
    } else{
	cout<<"day ("<<d<<") set to 1.\n";
	day=1;
    }
}
// getHour returns hour value from Time object
int DateTime::getHour() const{
    return time.getHour();
}
// getMinute returns minute value from Time object
int DateTime::getMinute() const{
    return time.getMinute();
}
// getSecond returns second value from Time object
int DateTime::getSecond() const{
    return time.getSecond();
}
// setHour sets hour in Time object. Validated in Time object
void DateTime::setHour(const int& h){
    time.setHour(h);
}
// setMinute sets minute in Time object, Validated in Time object
void DateTime::setSecond(const int& s){
    time.setSecond(s);
}
// validates day input
bool DateTime::checkDay(const int& d) const{
    bool flag=true;
    int dayLimit[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (d>dayLimit[month]){ // if past last day of the month
	flag=false;
    } 
    if (month==2 &&  d==dayLimit[month]+1 &&((year%4==0 && year%100) || (year%400==0 && year%100==0)))
	// leap year if divisible by 4, and not a centurial year unless divisible by 400 and 100
	flag=true;
    return flag;
}
// DateTime destructor
DateTime::~DateTime(){}
