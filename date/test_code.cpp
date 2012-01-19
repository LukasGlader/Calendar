#include "test_code.h"
//#include "julian.h"
#include "gregorian.h"

using namespace lab2;

test_code::test_code(void)
{
}


test_code::~test_code(void)
{
}

int main(){

	Gregorian g = Gregorian(2009, 2, 24);
	//Julian j = Julian(2009, 2, 24);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 1 - Date: 2009-2-24: Tuesday\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g.year() << "-" << g.month() << "-" << g.day()  << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "54886" << std::endl;
	std::cout << "\n";
/*
	std::cout << "Julian - Date: " << j.year() << "-" << j.month() << "-" << j.day()  << ": " << j.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "54899" << std::endl;
	std::cout << "\n\n";
*/
	g = Gregorian(1970, 1, 17);
//	j = Julian(1970, 1, 17);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 2 - Date: 1970-1-17: Saturday\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g.year() << "-" << g.month() << "-" << g.day()  << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "40603" << std::endl;
	std::cout << "\n";
/*
	//std::cout << "Julian - Date: " << j.year() << "-" << j.month() << "-" << j.day()  << ": " << j.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "40616" << std::endl;
	std::cout << "\n\n";
*/
	g = Gregorian();
//	j = Julian();
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 3 - Date: Today! all dates should be the same!\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g.year() << "-" << g.month() << "-" << g.day()  << ": " << g.week_day_name() << std::endl;
	std::cout << "          JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "\n";
/*
	std::cout << "Julian - Date: " << j.year() << "-" << j.month() << "-" << j.day()  << ": " << j.week_day_name() << std::endl;
	std::cout << "          JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "\n\n";
	*/
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "--------------------------------------------------------------------------------\n";
	g = Gregorian(1923, 3, 1);
	//g.add_year(111);
	//g.add_month(-120);
	//g.add_month(-119);
	g.add_year(-10);
//	j = Julian(1900, , 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 4 - Date: 1923-3-1: Thursday\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "23479" << std::endl;
	std::cout << "\n";

	g = Gregorian(1992, 9, 22);
//	j = Julian(1900, 2, 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 5 - Date: 1992-09-22\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "-1" << std::endl;
	std::cout << "\n";


	return 0;
}
