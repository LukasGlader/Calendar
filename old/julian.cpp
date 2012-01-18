#include "julian.h"

namespace lab2 {

Julian::Julian(int year, int month, int day) {
	checkValid(year, month, day);
    julianDayNumber = julianDateToJDN(year, month, day);
	jdnToJulianDate(julianDayNumber);
}

Julian::Julian(Date*& other) {
	jdnToJulianDate(other->mod_julian_day() + 2400000);
}

Julian::Julian(Date* other) {
	jdnToJulianDate(other->mod_julian_day() + 2400000);
}

Julian::Julian(const Date& other) {
	jdnToJulianDate(other.mod_julian_day() + 2400000);
}

Julian::Julian(int jdn) {
	jdnToJulianDate(jdn);
}

Julian::Julian():Gregorian() {
    jdnToJulianDate(julianDayNumber);
}

Julian::~Julian(void) {
}

const int Julian::days_this_month() const {
	return days_this_month(currentYear, currentMonth);
 }

int Julian::days_this_month(int year, int month) const{
	if(month == 0) month = 12;
	int result = 0;
		if(month == 2 && isLeapYear(year)){
			result = 29;
		}else{
			result = daysInMonth[month];
		}
	return result;
}

    //prefix
    Julian& Julian::operator++() {
        julianDayNumber++;
        jdnToJulianDate(julianDayNumber);
        return *this;
    }

    Julian& Julian::operator--() {
        julianDayNumber--;
        jdnToJulianDate(julianDayNumber);
        return *this;
    }

	const int Julian::week_day()const{
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


/**
* Converts a julian date to a Julian Day Number
**/
int Julian::julianDateToJDN(int year, int month, int day) {

	if(year < 1 ){
		year++;
	}
	if( month <= 2 ){
		year--;
		month += 12;
	}
	return ((floor((365.25)*(year+4716)) +
			floor(30.6001*(month+1))+day)-1524.5);
    }


bool Julian::isLeapYear(int year) const {
	if(year % 4 == 0){
		return true;
	}else{
		return false;
	}
}


/**
* Converts a Julian Day Number to a Julian Date
**/
void Julian::jdnToJulianDate(int jdn) {

	int b = mod_julian_day() + 2401525;
	int c = (int)((b - 122.1) / static_cast<double>(365.25));
	int da = (int)(static_cast<double>(365.25) * c);
	int e = (int)((b - da) / 30.6001);
	currentMonth = (int)( (e < 14) ? (e - 1) : (e - 13) );
	currentYear = (int)( (currentMonth > 2 ) ? (c - 4716) : (c - 4715));
	currentDay = (int)(b-da-floor(30.6001*e));
}

    void Julian::operator+=(int n) {
        julianDayNumber += n;
        jdnToJulianDate(julianDayNumber);
    }

    void Julian::operator-=(int n) {
        julianDayNumber -= n;
        jdnToJulianDate(julianDayNumber);
    }

	Julian& Julian::operator=(const Date& d)
	{
        julianDayNumber = d.julianDayNumber;
        updateDateWithJDN(julianDayNumber);
		return *this;
	}
	void Julian::updateDateWithJDN(int jdn) {
		jdnToJulianDate(jdn);
		return;
	}

    Date& Julian::add_year(int n) {

	if(currentDay > days_this_month(currentYear+n, currentMonth))
	{
		julianDayNumber = julianDateToJDN(currentYear + n, currentMonth, days_this_month(currentYear + n,currentMonth));
	}else
	{
		julianDayNumber = julianDateToJDN(currentYear + n, currentMonth, currentDay);
	}
	jdnToJulianDate(julianDayNumber);
	return *this;
    }

	Date& Julian::add_month(int n) {
		int tmpYear = currentYear;
		int tmpMonth = currentMonth + n;
		tmpYear += tmpMonth/12;
		tmpMonth = tmpMonth % 12;
		if(tmpMonth <= 0)
		{
			tmpMonth = 12 + tmpMonth;
			--tmpYear;
		}
		if(currentDay > days_this_month(tmpYear,tmpMonth))
		{
			julianDayNumber = julianDateToJDN(tmpYear, tmpMonth, days_this_month(tmpYear,tmpMonth));
		}else
		{
			julianDayNumber = julianDateToJDN(tmpYear, tmpMonth, currentDay);
		}
		jdnToJulianDate(julianDayNumber);
		return *this;
	}
}
