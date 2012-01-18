#pragma once

#include <math.h>
#include "gregorian.h"
#include <math.h>

namespace lab2{

class Julian :
	public Gregorian
{
public:

	Julian(void);
	Julian(int); //JDN Constructor
	Julian(Date*);
	Julian(Date*&);
	Julian(const Date&);
	Julian(int year, int month, int day);
	~Julian(void);

	const virtual int week_day() const;

	const virtual int days_this_month() const;
	int days_this_month(int year, int month) const;

	void jdnToJulianDate(int jdn);
	int julianDateToJDN(int year, int month, int day);
	
	//prefix
	virtual Julian& operator++();
	virtual Julian& operator--();

	Julian& operator=(const Date& d);
	void updateDateWithJDN(int jdn);

	virtual void operator+=(int n);
	virtual void operator-=(int n);

	virtual Date& add_year(int n = 1);
	virtual Date& add_month(int n = 1);

private:

protected:

	virtual bool isLeapYear(int year) const;

};
}
