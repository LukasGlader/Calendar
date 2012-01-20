#include "julian.h"

namespace lab2{

Julian::Julian()
{

	time_t t;
	k_time(&t);	//time(t);
	julian_day_number = (t/86400)+ 2440587.5;
}

Julian::Julian(const Date& d)
{
	julian_day_number = d.julian_day();
}

Julian::Julian(int jdn)
{
	julian_day_number = jdn;
}

Julian::Julian(int year, int month, int day)
{
	is_valid(day, month, year);
	julian_day_number = gregorian_date_to_JDN(year, month, day);
}

	Julian::~Julian()
{
}

double Julian::julian_date_to_JDN(int y, int m, int d) const
{
	return 0;
}

	day_month_year Julian::JDN_to_julian(double jd) const
{

	day_month_year result;
	int y, m, d;
	double j;

	j = jd - 1721119 + 0.5 ;
	y = (int)((4 * j - 1) / 146097 );
	j = 4 * j - 1 - 146097 * y ;
	d = (int)(j / 4) ;
	j = (4 * d + 3) / 1461 ;
	d = 4 * d + 3 - 1461 * j ;
	d = (d + 4) / 4 ;
	m = (5 * d - 3) / 153 ;
	d = 5 * d - 3 - 153 * m ;
	d = (d + 5) / 5 ;
	y = 100 * y + j ;
	if(m < 10)
	{
		m = m + 3;
	}else
	{
		m = m - 9 ; y = y + 1;
	}

	result.day = d;
	result.month = m;
	result.year = y;
	return result;
}

	const int Julian::year() const
{
	day_month_year date = JDN_to_julian(julian_day_number);
	return date.year;
}

	const int Julian::month() const
{
	day_month_year date = JDN_to_julian(julian_day_number);
	return date.month;
}

	const int Julian::day() const
{
	day_month_year date = JDN_to_julian(julian_day_number);
	return date.day;
}

	Date& Julian::add_year(int n)
{
	if(is_leap_day())
	{
		if(is_leap_year(year() + n))
		{
			julian_day_number = julian_date_to_JDN(
				year() + n, month(), day());
		}else //jumping from leap day to non leap day.
		{
			julian_day_number = julian_date_to_JDN(
				year() + n, 2, 28);
		}
	}else
	{
		julian_day_number = julian_date_to_JDN(
			year() + n, month(), day());
	}
	return (*this);
}

	Date& Julian::sub_month()
{

	int next_year = year();
	int next_month = month();
	if(month() == 1)
	{
		next_month = 12;
		next_year--;
	}else
	{
		next_month--;
	}

	if(days_in_month(next_year, next_month) >= day())
	{
		julian_day_number = julian_date_to_JDN(next_year, next_month, day());
	}else
	{
		julian_day_number -= 30;
	}
	return (*this);
}


	Date& Julian::add_month()
{
	int next_year = year();
	int next_month = month();
	if(month() == 12)
	{
		next_month = 1;
		next_year++;
	}else
	{
		next_month++;
	}

	if(days_in_month(next_year, next_month) >= day())
	{
		julian_day_number = julian_date_to_JDN(next_year, next_month, day());
	}else
	{
		julian_day_number += 30;
	}
	return (*this);
}

	bool Julian::is_leap_year(int year) const
{
	return (year % 4 == 0);
}

}

