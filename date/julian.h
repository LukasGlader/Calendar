#pragma once
#include "gregorian.h"
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

class Julian :
	public lab2::Gregorian
{

public:
	Julian();
	Julian(const Date&);
	Julian(int jdn);
	Julian(int year, int month, int day);
	~Julian();

	const int day() const;
	const int month() const;
	const int year() const;

	virtual Date& add_year(int n);
	//virtual Date& add_month(int n);
	virtual Date& add_month();
	virtual Date& sub_month();
protected:

	virtual bool is_leap_year(int year) const;

	//int calculateDaysNextMonth();

	//void jdnToG_Regorian(int jdn);
	double julian_date_to_JDN(int year, int month, int day) const;
	day_month_year JDN_to_julian(double jd) const;
};
}
