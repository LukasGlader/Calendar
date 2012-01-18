#include "date.h"
namespace lab2{

Date::Date(void)
{

}


Date::~Date(void)
{
}

std::ostream& operator<<(std::ostream & os, const Date& d){
	os << d.year() << "-";
	int month = d.month();
	if(month < 10)
		os << "0";

	os << month << "-";
	
	int day = d.day();
	if(day < 10)
		os << "0";
	os << day;

	return os;
}

const int  Date::operator-(const Date& d) const{
	return (mod_julian_day() - d.mod_julian_day());
}

const bool Date::operator==(const Date& d) const{
	return (mod_julian_day() == d.mod_julian_day());
}
const bool Date::operator!=(const Date& d) const{
	return (mod_julian_day() != d.mod_julian_day());
}
const bool Date::operator<(const Date& d) const{
	return (mod_julian_day() < d.mod_julian_day());
}
const bool Date::operator<=(const Date& d) const{
	return (mod_julian_day() <= d.mod_julian_day());
}
const bool Date::operator>(const Date& d) const{
	return (mod_julian_day() > d.mod_julian_day());
}
const bool Date::operator>=(const Date& d) const{
	return (mod_julian_day() >= d.mod_julian_day());
}

}