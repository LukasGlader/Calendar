#include "test_code.h"
#include "julian.h"

using namespace lab2;

test_code::test_code(void)
{
}


test_code::~test_code(void)
{
}

/*
int main(){

	Gregorian a = Gregorian(2009, 2, 24);
	std::cout << "Created Gregorian date 2009-02-24 (Tuesday). Our implementation reports \n";
	std::cout << "Greg: " << a.year() << "-" << a.month() << "-" << a.currentDay  << ": " << a.week_day_name() << "(" << a.julianDayNumber << ")" << std::endl;
	std::cout << "Mod_Julian: " << a.mod_julian_day() << std::endl;
	a.add_month(15);
	std::cout << "Adding 15 months gives us the date 2010-05-24 (Monday)\n";
	std::cout << "Greg: " << a.year() << "-" << a.month() << "-" << a.currentDay  << ": " << a.week_day_name() << "(" << a.julianDayNumber << ")" << std::endl;
	std::cout << "\n";

	std::cout << "Created Gregorian date 2037-07-12 (Sunday). Our implementation reports \n";
	Gregorian c = Gregorian(2037, 7, 12);
	std::cout << "Greg: " << c.year() << "-" << c.month() << "-" << c.currentDay  << ": " << c.week_day_name() << "(" << c.julianDayNumber << ")" << std::endl;
	std::cout << "Mod_Julian: " << c.mod_julian_day() << std::endl;
	c.add_month(15);
	std::cout << "Adding 15 months gives us the date 2038-10-12 (Tuesday)\n";
	std::cout << "Greg: " << c.year() << "-" << c.month() << "-" << c.currentDay  << ": " << c.week_day_name() << "(" << c.julianDayNumber << ")" << std::endl;
	std::cout << "\n";

	std::cout << "Created Julian date from Greg 1970-01-15 (Thursday). \n" <<
		"This should yield Julian 1970-01-02. Our implementation reports \n";
	Julian b = Julian(1970, 1, 15);
	std::cout << "Julian: " << b.year() << "-" << b.month() << "-" << b.day() << ": " << b.week_day_name() << "(" << b.julianDayNumber << ")" << std::endl;
	std::cout << "Mod_Julian: " << b.mod_julian_day() << std::endl;
	b.add_month(15);
	std::cout << "Adding 15 months should yield Julian 1971-04-02 (Thursday)\n";
	std::cout << "Julian: " << b.year() << "-" << b.month() << "-" << b.currentDay  << ": " << b.week_day_name() << "(" << b.julianDayNumber << ")" << std::endl;
	std::cout << "\n";

	std::cout << "Created Julian date from Greg 1997-04-22 (Tuesday). \n" <<
		"This should yield Julian 1997-04-09\n";
	Julian d = Julian(1997, 4, 22);
	std::cout << "Julian: " << d.year() << "-" << d.month() << "-" << d.day() << ": " << d.week_day_name() << "(" << d.julianDayNumber << ")" << std::endl;
	std::cout << "Mod_Julian: " << d.mod_julian_day() << std::endl;
	d.add_month(15);
	std::cout << "Adding 15 months should yield Julian 1998-07-09 (Wednesday)\n";
	std::cout << "Julian: " << d.year() << "-" << d.month() << "-" << d.currentDay  << ": " << d.week_day_name() << "(" << d.julianDayNumber << ")" << std::endl;
	std::cout << "\n";


	//Gregorian c = Gregorian(2010, 10, 1);
	//Gregorian d = Gregorian(2010, 9, 31);

	//std::cout << "Greg: " << c.year() << "-" << c.month() << "-" << c.currentDay  << ": " << c.week_day_name() << "(" << c.julianDayNumber << ")" << std::endl;
	//std::cout << "Greg: " << d.year() << "-" << d.month() << "-" << d.currentDay  << ": " << d.week_day_name() << "(" << d.julianDayNumber << ")" << std::endl;
	std::string asdf;
	std::cin >> asdf;

	return 0;
}
*/