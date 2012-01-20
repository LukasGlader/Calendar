#include "julian.h"

namespace lab2{

Julian::Julian():Gregorian()
{
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
	if(y < 1 ){
		y++;
	}
	if( m <= 2 ){
		y--;
		m += 12;
	}
	return ((floor((365.25)*(y+4716)) +
			floor(30.6001*(m+1))+d)-1524.5);

}

	day_month_year Julian::JDN_to_julian(double jd) const
{
	day_month_year result;

	int b = mod_julian_day() + 2401525;
	int c = (int)((b - 122.1) / 365.25);
	int da = (int)(365.25 * c);
	int e = (int)((b - da) / 30.6001);
	int m =(int)( (e < 14) ? (e - 1) : (e - 13) );
	int y = (int)( (m > 2 ) ? (c - 4716) : (c - 4715));
	int d = (int)(b-da-floor(30.6001*e));

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

