#include "gregorian.h"

namespace lab2{

	//spot 0 empty to avoid having to do index arithmetic later
	const std::string Gregorian::day_names[8] =
		{"INVALID_DAY",
		"monday",
		"tuesday",
		"wednesday",
		"thursday",
		"friday",
		"saturday",
		"sunday"};

	const std::string Gregorian::month_names[13] =
		{"INVALID_MONTH",
		"january",
		"february",
		"march",
		"april",
		"may",
		"june",
		"july",
		"august",
		"september",
		"october",
		"november",
		"december"};

	const int Gregorian::days_in_month_array[13] =
	{0,31,28,31,30,31,30,31,31,30,31,30,31};

Gregorian::Gregorian()
{

	time_t t;
	k_time(&t);	//time(t);
	julian_day_number = (t/86400)+ 2440587.5;
}

Gregorian::Gregorian(const Date& d)
{
	julian_day_number = d.julian_day();
}

Gregorian::Gregorian(int jdn)
{
	julian_day_number = jdn;
}

Gregorian::Gregorian(int year, int month, int day)
{
	is_valid(day, month, year);
	julian_day_number = gregorian_date_to_JDN(year, month, day);
}

	Gregorian::~Gregorian()
{
}

	int Gregorian::mod_julian_day() const
{
	return (int)JDN_to_mod_julian_day(julian_day_number);
}

	double Gregorian::JDN_to_mod_julian_day(double jdn) const
{
	return (jdn - 2400000.5);
}

	double Gregorian::julian_day() const
{
	return julian_day_number;
}

double Gregorian::gregorian_date_to_JDN(int y, int m, int d) const
{
	return (1721425.5 - 1) +
	(365 * (y - 1)) +
	(int)((y - 1) / 4) +
	(-(int)((y - 1) / 100)) +
	(int)((y - 1) / 400) +
	(int)((((367 * m) - 362) / 12) +
			((m <= 2) ? 0 :
			(is_leap_year(y) ? -1 : -2)
			) +
			d);
}


	day_month_year Gregorian::JDN_to_gregorian(double jd) const
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

	const int Gregorian::year() const
{
	day_month_year date = JDN_to_gregorian(julian_day_number);
	return date.year;
}

	const int Gregorian::month() const
{
	day_month_year date = JDN_to_gregorian(julian_day_number);
	return date.month;
}

	const int Gregorian::day() const
{
	day_month_year date = JDN_to_gregorian(julian_day_number);
	return date.day;
}

	const int Gregorian::week_day() const
{
	int m = month();
	int y = year();
	if (m < 3){
		m += 12;
		y -=1;
	}
	int k = y % 100;
	int j = y /100;
	int h = ((day() + (int)(((m+1)*26)/10) + k + (int)(k/4) + (int)(j/4) + (5*j))) % 7;
	h -= 1;
	if(h == 0){
		h = 7;
	}
	if(h == -1){
		h = 6;
	}
	return h;
}

	const int Gregorian::days_per_week() const
{
	return 7;
}

	const int Gregorian::days_this_month() const
{
	return days_in_month(year(), month());
}

	const int Gregorian::months_per_year() const
{
	return 12;
}

int Gregorian::days_in_month(int year, int month) const
{
	if(month == 0) month = 12;
	int result = 0;
	if(month == 2 && is_leap_year(year)){
		result = 29;
	}else{
		result = days_in_month_array[month];
	}
	return result;
}

	const std::string Gregorian::week_day_name() const
{
	return day_names[week_day()];
}

	const std::string Gregorian::month_name() const
{
	return month_names[month()];
}

//prefix
Date& Gregorian::operator++()
{
	julian_day_number++;
	return *this;
}

Date& Gregorian::operator--()
{
	julian_day_number--;
	return *this;
}

//postfix
Gregorian Gregorian::operator++(int n)
{
	Gregorian old(year(), month(), day());
	++(*this);

	return old;
}

Gregorian Gregorian::operator--(int n)
{
	Gregorian old(year(), month(), day());
	--(*this);

	return old;
}

void Gregorian::operator+=(int n)
{
	julian_day_number+= n;
}

void Gregorian::operator-=(int n)
{
	julian_day_number-= n;
}

Gregorian& Gregorian::operator=(const Date& d)
{
	int jdn = d.julian_day();
	julian_day_number = jdn;
	return *this;
}

	Date& Gregorian::add_year(int n)
{
	if(is_leap_day())
	{
		if(is_leap_year(year() + n))
		{
			julian_day_number = gregorian_date_to_JDN(
				year() + n, month(), day());
		}else //jumping from leap day to non leap day.
		{
			julian_day_number = gregorian_date_to_JDN(
				year() + n, 2, 28);
		}
	}else
	{
		julian_day_number = gregorian_date_to_JDN(
			year() + n, month(), day());
	}
	return (*this);
}

	Date& Gregorian::add_year()
{
	add_year(1);
	return (*this);
}

	bool Gregorian::is_leap_day() const
{
	return (month() == 2 && day() == 29);
}

	Date& Gregorian::sub_month()
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
		julian_day_number = gregorian_date_to_JDN(next_year, next_month, day());
	}else
	{
		julian_day_number -= 30;
	}
	return (*this);
}

	Date& Gregorian::add_month(int n)
{
	if(n > 0)
	{
		for(int i = 0; n > i; i++)
			add_month();
	}else
	{
		for(int i = 0; std::abs(n) > i; i++)
			sub_month();
	}
	return (*this);
}

	Date& Gregorian::add_month()
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
		julian_day_number = gregorian_date_to_JDN(next_year, next_month, day());
	}else
	{
		julian_day_number += 30;
	}
	return (*this);
}

	bool Gregorian::is_leap_year(int year) const
{
	if(year % 4 == 0)
		if(year % 100 == 0)
			if(year % 400 == 0)
				return true;
			else
				return false;
		else
			return true;
	else
		return false;
}

void Gregorian::is_valid(int d, int m, int y) const
{
	if(m < 1 || m > 12 || d < 1 || d > days_in_month(y,m)){
		throw std::out_of_range("illegal date");
	}
}
}

