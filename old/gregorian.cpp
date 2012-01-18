#include "gregorian.h"

namespace lab2{

	//spot 0 empty to avoid having to do index arithmetic later
	const std::string Gregorian::dayNames[8] = 	
		{"INVALID_DAY", 
		"monday", 
		"tuesday",
		"wednesday",
		"thursday",
		"friday",
		"saturday",
		"sunday"};

	const std::string Gregorian::monthNames[13] =
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

	const int Gregorian::daysInMonth[13] =
	{0,31,28,31,30,31,30,31,31,30,31,30,31};


Gregorian::Gregorian(){
	
	// För att få nuvarande tid
    time_t mytime = time(NULL);
	//set_k_time(mytime);
    k_time(&mytime);

    // För att få ut datum lokalt 
    struct tm *t = gmtime(&mytime);
    currentYear  = t->tm_year + 1900;
    currentMonth = t->tm_mon + 1;      // månaderna och dagarna
    currentDay   = t->tm_mday;         // indexerade från ETT

	julianDayNumber = gregorianDateToJDN(currentYear, currentMonth, currentDay);

}

Gregorian::Gregorian(const Date& d) {
	if(d != *this) {
		julianDayNumber = d.julianDayNumber;
		jdnToGregorian(julianDayNumber);
	}
}

Gregorian::Gregorian(int jdn){

	julianDayNumber = jdn;
	jdnToGregorian(jdn);
}

Gregorian::Gregorian(int year, int month, int day)
{
	checkValid(year, month, day);
	currentYear  = year;
    currentMonth = month;      // månaderna och dagarna
    currentDay   = day;         // indexerade från ETT

	julianDayNumber = gregorianDateToJDN(year, month, day);
}

Gregorian::~Gregorian(void)
{
}

void Gregorian::checkValid(int year, int month, int day) {
	if(month < 1 || month > 12 || day < 1 || day > days_this_month(year,month)){
		throw std::out_of_range("illegal date given!");
	}
}


/**
 * Converts a conventional western Gregorian Date to a julian day number
 * Algorithm source: http://www.astro.uu.nl/~strous/AA/en/reken/juliaansedag.html
 **/
int Gregorian::gregorianDateToJDN(int y, int m, int d){
	return (1721425.5 - 1) + (365 * (y - 1)) +
	(int)((y - 1) / 4) + (-(int)((y - 1) / 100)) +
	(int)((y - 1) / 400) + (int)((((367 * m) - 362) / 12) +
	((m <= 2) ? 0 :	(isLeapYear(y) ? -1 : -2)) + d);
}

/**
 * Converts a Julian Day Number to a Gregorian date.
 **/
void Gregorian::jdnToGregorian(int jd){

	int dqc, dcent, dquad, leapadj;
	double wjd,depoch, quadricent, cent, quad,yindex, yearday;

	wjd = (int)(mod_julian_day() +2400000) + 0.5;
	depoch = wjd - 1721425.5;
	quadricent = floor(depoch / 146097);
	dqc = (((int)depoch) % 146097);
	cent = (int)(dqc / 36524);
	dcent = (dqc %36524);
	quad = (int)(dcent / 1461);
	dquad = (dcent % 1461);
	yindex = (int)(dquad / 365);
	currentYear = int((quadricent * 400) + (cent * 100) + (quad * 4) + yindex);
	if (!((cent == 4) || (yindex == 4))) {
		(currentYear)++;
	}
	yearday = wjd - gregorianDateToJDN(currentYear, 1, 1);
	leapadj = ((wjd < gregorianDateToJDN(currentYear, 3, 1)) ? 0
			:
	(isLeapYear(currentYear) ? 1 : 2));
	currentMonth = int(floor((((yearday + leapadj) * 12) + 373) / 367));
	currentDay = int((wjd - gregorianDateToJDN(currentYear, currentMonth, 1)) + 1);
}

const int Gregorian::week_day() const{ 
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

const int Gregorian::year() const{
	return currentYear;
}

const int Gregorian::month() const{
	return currentMonth;
}

const int Gregorian::day() const{
	return currentDay;
}

const int Gregorian::days_per_week() const{
	return daysInWeek;
}

const int Gregorian::days_this_month() const {
	return days_this_month(currentYear, currentMonth);
}	

int Gregorian::days_this_month(int year, int month) const {
	if(month == 0) month = 12;
	int result = 0;
		if(month == 2 && isLeapYear(year)){
			result = 29;
		}else{
			result = daysInMonth[month];
		}
	return result;
}

const int Gregorian::months_per_year() const{
	return monthsInYear;
}


/**
 * Method for determining whether or not the given year was a leap year.
 * Algorithm source: http://en.wikipedia.org/wiki/Leap_year
 **/
bool Gregorian::isLeapYear(int year) const {
	if(year % 400 == 0){
		return true;
	}else if(year % 100 == 0){
		return false;
	}else if(year % 4 == 0){
		return true;
	}else{
		return false;
	}
}

const std::string Gregorian::week_day_name() const{
	return dayNames[week_day()];
}

const std::string Gregorian::month_name() const{
	printf("\n$$$ month: %d $$$$\n", currentMonth);
	fflush(stdout);
	if(currentMonth > 12 || currentMonth < 1)
		throw std::out_of_range("illegal date given!");
	return monthNames[currentMonth];
}

//prefix
Date& Gregorian::operator++(){
	julianDayNumber++;
	jdnToGregorian(julianDayNumber);
	return *this;
}

Date& Gregorian::operator--(){
	julianDayNumber--;
	jdnToGregorian(julianDayNumber);
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

int Gregorian::mod_julian_day() const{
	return int(julianDayNumber - 2400000);
}

void Gregorian::operator+=(int n){
	julianDayNumber+= n;
	jdnToGregorian(julianDayNumber);
}

void Gregorian::operator-=(int n){
	julianDayNumber-= n;
	jdnToGregorian(julianDayNumber);
}

Date& Gregorian::add_year(int n){
	if(currentDay > days_this_month(currentYear+n, currentMonth))
	{
		julianDayNumber = gregorianDateToJDN(currentYear + n, currentMonth, days_this_month(currentYear + n,currentMonth));
	}else
	{
		julianDayNumber = gregorianDateToJDN(currentYear + n, currentMonth, currentDay);
	}
	jdnToGregorian(julianDayNumber);
	return *this;
}

Date& Gregorian::add_month(int n) {
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
		julianDayNumber = gregorianDateToJDN(tmpYear, tmpMonth, days_this_month(tmpYear,tmpMonth));
	}else
	{
		julianDayNumber = gregorianDateToJDN(tmpYear, tmpMonth, currentDay);
	}
	jdnToGregorian(julianDayNumber);
	return *this;
}

Gregorian& Gregorian::operator=(const Date& d) {
        julianDayNumber = d.julianDayNumber;
        updateDateWithJDN(julianDayNumber);
		return *this;
}

void Gregorian::updateDateWithJDN(int jdn) {
	jdnToGregorian(jdn);
	return;
}

int Gregorian::calculateDaysNextMonth() {
	
		int nextMonth = currentMonth+1;
		int nextYear = currentYear;

		if(nextMonth > 12){ //Rollover
			nextYear++;
			nextMonth = 1;
		}

		Gregorian nextDate = Gregorian(nextYear, nextMonth, 1);
		int daysNextMonth = nextDate.days_this_month();
		return daysNextMonth;
}
}
