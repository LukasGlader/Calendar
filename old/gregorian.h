#pragma once
#include "date.h"
#include "kattistime.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <iterator>
#include <stdexcept>
namespace lab2{

class Gregorian :
	public Date
{
public:

	int currentMonth;
	int currentYear;
	int currentDay;

	Gregorian();
	Gregorian(const Date&);
	Gregorian(int jdn);
	Gregorian(int year, int month, int day);

	~Gregorian();

	
	const virtual int year() const;
	const virtual int month() const;
	const virtual int day() const;
	
	const virtual int week_day() const;

	const virtual int days_per_week() const;
	const virtual int days_this_month() const;

	const virtual int months_per_year() const;
	const virtual std::string week_day_name() const;
	const virtual std::string month_name() const;

	//prefix
	virtual Date& operator++();
	virtual Date& operator--();

	//postfix
	virtual Gregorian operator++(int n);
	virtual Gregorian operator--(int n);

	virtual void operator+=(int n);
	virtual void operator-=(int n);
	virtual Gregorian& operator=(const Date& d);
	void updateDateWithJDN(int jdn);

	virtual Date& add_year(int n = 1);
	virtual Date& add_month(int n = 1);

	virtual int mod_julian_day() const;

protected:

	virtual bool isLeapYear(int year) const;

	int days_this_month(int year, int month) const;
	int calculateDaysNextMonth();

	void jdnToGregorian(int jdn);
	int gregorianDateToJDN(int year, int month, int day);

	static const int daysInWeek = 7;
	static const int monthsInYear = 12;

	
	static const std::string dayNames[8];
	static const std::string monthNames[13];
	static const int daysInMonth[13];

	void checkValid(int, int, int);
};
}
