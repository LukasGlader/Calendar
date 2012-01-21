#include "julian.h"
#define IGREG (15+31L*(10+12L*1582))


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
	julian_day_number = julian_date_to_JDN(year, month, day);
}

	Julian::~Julian()
{
}

double Julian::julian_date_to_JDN(int year, int month, int day) const
{
	//std::cout << "Julian->JDN date: " << year <<"-"<<month<<"-"<<day<<" ->";

	if(year < 1 ){
		year++;
	}
	if( month <= 2 ){
		year--;
		month += 12;
	}
	double jdn = ((floor(365.25*(year+4716)) +
			floor(30.6001*(month+1))+day)-1524.5);
	//std::cout << (int)jdn << "\n";
	return jdn;
}

	day_month_year Julian::JDN_to_julian(double julian) const
{
	//std::cout << "\tJDN->Julian JDN: " << (int)julian << " -> ";
	day_month_year result;
	int day, month, year;

	int b = JDN_to_mod_julian_day(julian) + 2401525;
	int c = (int)((b - 122.1) / 365.25);
	int da = (int)(365.25 * c);
	int e = (int)((b - da) / 30.6001);
	month =(int)( (e < 14) ? (e - 1) : (e - 13) );
	year = (int)( (month > 2 ) ? (c - 4716) : (c - 4715));
	day = (int)(b-da-floor(30.6001*e));

	//std::cout << year <<"-"<<month<<"-"<<day<<"\n";
	result.day = day;
	result.month = month;
	result.year = year;
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

const int Julian::week_day()const{
	// Julian
	int m = month();
	int y = year();
	if (m < 3){
		m += 12;
		y -=1;
	}
	int k = y % 100;
	int j = y /100;
	int h = ((day() + (int)(((m+1)*26)/10) + k + (int)(k/4) + 5 + (6*j))) % 7;
	h -= 1;
	if(h == 0){
		h = 7;
	}
	if(h == -1){
		h = 6;
	}
	return h;
}

}

