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
	// För att få nuvarande tid
    time_t mytime = time(NULL);
	set_k_time(mytime);
    k_time(&mytime);

    // För att få ut datum lokalt 
    struct tm *t = gmtime(&mytime);
    int current_year  = t->tm_year + 1900;
    int current_month = t->tm_mon + 1;      // månaderna och dagarna
    int current_day   = t->tm_mday;         // indexerade från ETT

	julian_day_number = gregorian_date_to_JDN(current_year, current_month, current_day);

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
	return int(julian_day_number - 2400000);
}

	int Gregorian::julian_day() const
{
	return julian_day_number;
}

	int Gregorian::gregorian_date_to_JDN(int y, int m, int d) const
{
	std::cout << "\n$$$$ year:" << y << " month:" << m << " day:" << d;
	int jdn = (1721425.5 - 1) + (365 * (y - 1)) +
	(int)((y - 1) / 4) + (-(int)((y - 1) / 100)) +
	(int)((y - 1) / 400) + (int)((((367 * m) - 362) / 12) +
	((m <= 2) ? 0 :	(is_leap_year(y) ? -1 : -2)) + d);
	std::cout << " $$$$ jdn:" << jdn << "\n";
	return jdn;
}

	day_month_year Gregorian::JDN_to_gregorian(int jd) const
{
	day_month_year result;
	int dqc, dcent, dquad, leapadj;
	int day, month, year;
	float wjd,depoch, quadricent, cent, quad,yindex, yearday;

	wjd = jd + 0.5;
	depoch = wjd - 1721425.5;
	quadricent = floor(depoch / 146097);
	dqc = (((int)depoch) % 146097);
	cent = (int)(dqc / 36524);
	dcent = (dqc %36524);
	quad = (int)(dcent / 1461);
	dquad = (dcent % 1461);
	yindex = (int)(dquad / 365);
	year = int((quadricent * 400) + (cent * 100) + (quad * 4) + yindex);
	if (!((cent == 4) || (yindex == 4))) {
		(year)++;
	}
	yearday = wjd - gregorian_date_to_JDN(year, 1, 1);
	leapadj = ((wjd < gregorian_date_to_JDN(year, 3, 1)) ? 0
			:
	(is_leap_year(year) ? 1 : 2));
	month = int(floor((((yearday + leapadj) * 12) + 373) / 367));
	day   = int((wjd - gregorian_date_to_JDN(year, month, 1)) + 1);

	result.day = day;
	result.month = month;
	result.year = year;
	return result;
}
/*
	day_month_year Gregorian::JDN_to_gregorian(int jd) const
{
	day_month_year result;
	float jdn, day, month, year;
	float calc1, calc2, calc3;
	jdn = jd - 1721119;
    calc1 = 4 * jdn - 1;
    year = (int)(calc1 / 146097);
    jdn = (int)(calc1 - 146097 * year);
    day = (int)(jdn / 4);
    calc2 = 4 * day + 3;
    jdn = (int)(calc2 / 1461);
    day = calc2 - 1461 * jdn;
    day = (int)((day + 4) / 4);
    calc3 = 5 * day - 3;
    month = (int)(calc3 / 153);
    day = calc3 - 153 * month;
    day = (int)((day + 5) / 5);
    year = 100 * year + jdn;

    if (month < 10) {
        month = month + 3;
    }
    else {
        month = month - 9;
        year = year + 1;
    }
	result.day = day;
	result.month = month;
	result.year = year;
	return result;
}
*/
/*
	day_month_year Gregorian::JDN_to_gregorian(int jd) const
{
	day_month_year result;
	int l, n, i, d, j, m, y;
	l = jd + 68569 + 1;
    n = (int)(( 4 * l ) / 146097);
    l = l - (int)(( 146097 * n + 3 ) / 4);
    i = (int)(( 4000 * ( l + 1 ) ) / 1461001);
    l = l - (int)(( 1461 * i ) / 4) + 31;
    j = (int)(( 80 * l ) / 2447);
    d = l - (int)(( 2447 * j ) / 80);
    l = (int)(j / 11);
    m = j + 2 - ( 12 * l );
    y = 100 * ( n - 49 ) + i + l;
	result.day = d;
	result.month = m;
	result.year = y;
	return result;
}
*/

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
	int jdn = d.mod_julian_day() + 2400000;
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

		//std::cout << "\n$$$$ year:" << next_year << " month:" << next_month << " day:" << day() <<"\n";
	if(days_in_month(next_year, next_month) >= day())
	{
		julian_day_number = gregorian_date_to_JDN(next_year, next_month, day());
	}else
	{
		//std::cout << "\nFAIL\n";
		julian_day_number += 30;
	}
	return (*this);
}

	bool Gregorian::is_leap_year(int year) const
{
	if(julian_day_number % 4 == 0)
		if(julian_day_number % 100 == 0)
			if(julian_day_number % 400 == 0)
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

