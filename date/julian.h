#pragma once
#include <math.h>

namespace lab2{

class Julian :
	public Date
{
public:

	Julian(void);
	Julian(int jdn); //JDN Constructor
	Julian(Date*);
	Julian(Date*&);
	Julian(const Date&);
	Julian(int year, int month, int day);
	~Julian(void);

	const virtual int year() const;
	const virtual int month() const;
	const virtual int day() const;
	const virtual int week_day() const;

	const int days_per_week() const;
	const int days_this_month() const;
	const virtual int months_per_year() const;

	int days_this_month(int year, int month) const;

	//Weird functions should be removed!
	//void jdnToJulianDate(int jdn);
	//int julianDateToJDN(int year, int month, int day);
	//void updateDateWithJDN(int jdn);
	
	//prefix
	virtual Julian& operator++();
	virtual Julian& operator--();

	Julian& operator=(const Date& d);

	virtual void operator+=(int n);
	virtual void operator-=(int n);

	virtual Date& add_year(int n = 1);
	virtual Date& add_month(int n = 1);

protected:

	//state
	virtual bool is_leap_year(int year) const;

};
}
