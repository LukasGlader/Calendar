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
#include <iostream>
namespace lab2
{

    struct day_month_year
    {
        int day;
        int month;
        int year;
    };
class Gregorian :
	public Date
{

public:
	Gregorian();
	Gregorian(const Date&);
	Gregorian(int jdn);
	Gregorian(int year, int month, int day);
	~Gregorian();

	virtual int mod_julian_day() const;
	virtual double julian_day() const;

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

	virtual Date& add_year(int n);
	virtual Date& add_year();
	virtual Date& add_month(int n);
	virtual Date& add_month();
	virtual Date& sub_month();
protected:

	virtual bool is_leap_year(int year) const;
	bool is_leap_day() const;

	int days_in_month(int year, int month) const;
	//int calculateDaysNextMonth();

	//void jdnToG_Regorian(int jdn);
	double gregorian_date_to_JDN(int year, int month, int day) const;
	double JDN_to_mod_julian_day(double jdn) const;

	static const std::string day_names[8];
	static const std::string month_names[13];
	static const int days_in_month_array[13];

	static const int days_in_week = 7;
	static const int months_in_year = 12;

	void is_valid(int d, int m, int y) const;
	day_month_year JDN_to_gregorian(double jd) const;
};
}
