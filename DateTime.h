// DataTime class header file
// By Aleksey Leshchuk
// CISP400
// for AD4, in use with Employee, Time, and Date class

#ifndef DATETIME_H
#define DATETIME_H

#include "Time.h"
#include "Date.h"

class DateTime{
    public:
	// default constructor, takes int of Month, Day, Year, and a Time object
	DateTime(const int& =0, const int& =0, const int& =0, const Time& =Time(0,0,0));
	// print function, prints Month, Day, Year and Time information
	void print() const;
	// increaseADay function increase the date by a day
	void increaseADay();
	// increaseAMonth increases month by one 
	void increaseAMonth();
	// increases the year by one
	void increaseAYear();
	// increases the Time object by a second, while maintaining validity of other attributes
	void tick();
	// getMonth returns int month
	int getMonth() const;
	// getYear returns int year
	int getYear() const;
	// getDay returns int day
	int getDay() const;
	// setMonth validates and sets month
	void setMonth(const int&);
	// setYear validates year is between 1920-2020, else sets to 2011
	void setYear(const int&);
	// setDay validates day using checkDay() and sets
	void setDay(const int&);
	// getHour returns hour value from Time object
	int getHour() const;
	// getMinute returns minute value from Time object
	int getMinute() const;
	// getSecond returns second value from Time object
	int getSecond() const;
	// setHour sets hour in Time object. Validated in Time object
	void setHour(const int&);
	// setMinute sets minute in Time object, Validated in Time object
	void setSecond(const int&);
	// DateTime destructor
	~DateTime();
    private:
	int month;
	int day;
	int year;
	const static int monthsPerYear;
	Time time;
	// validates day input
	bool checkDay(const int& ) const;
};

#endif
