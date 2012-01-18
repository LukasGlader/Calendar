#include "test_code_new.h"
#include "julian.h"

using namespace lab2;

test_code::test_code(void)
{
}


test_code::~test_code(void)
{
}

int main(){

	Gregorian g = Gregorian(2009, 2, 24);
	Julian j = Julian(2009, 2, 24);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 1 - Date: 2009-2-24: Tuesday\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g.year() << "-" << g.month() << "-" << g.currentDay  << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "54886" << std::endl;
	std::cout << "\n";

	std::cout << "Julian - Date: " << j.year() << "-" << j.month() << "-" << j.currentDay  << ": " << j.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "54899" << std::endl;
	std::cout << "\n\n";

	g = Gregorian(1970, 1, 17);
	j = Julian(1970, 1, 17);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 2 - Date: 1970-1-17: Saturday\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g.year() << "-" << g.month() << "-" << g.currentDay  << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "40603" << std::endl;
	std::cout << "\n";

	std::cout << "Julian - Date: " << j.year() << "-" << j.month() << "-" << j.currentDay  << ": " << j.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "40616" << std::endl;
	std::cout << "\n\n";

	g = Gregorian();
	j = Julian();
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 3 - Date: Today! all dates should be the same!\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g.year() << "-" << g.month() << "-" << g.currentDay  << ": " << g.week_day_name() << std::endl;
	std::cout << "          JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "\n";

	std::cout << "Julian - Date: " << j.year() << "-" << j.month() << "-" << j.currentDay  << ": " << j.week_day_name() << std::endl;
	std::cout << "          JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "\n\n";
	
	g = Gregorian(1900, 2, 29);
	j = Julian(1900, 2, 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 4 - Date: 1900-2-29: Thursday\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g.year() << "-" << g.month() << "-" << g.currentDay  << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "15079" << std::endl;
	std::cout << "\n";


	std::string asdf;
	std::cin >> asdf;
	return 0;
}
