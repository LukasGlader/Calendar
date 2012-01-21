#include "test_code.h"
#include "julian.h"
//#include "Julian.h"

using namespace lab2;

test_code::test_code(void)
{
}


test_code::~test_code(void)
{
}

int main(){

	time_t time = 0;
	set_k_time(time);
	Julian j = Julian(1923, 1, 1);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 1 - Date: 1923-01-01: \n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << j.year() << "-" << j.month() << "-" << j.day()  << ": " << j.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "23433" << std::endl;
	std::cout << "\n";

	j = Julian(2014, 5, 22);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 1 - Date: 2014-05-22: \n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << j.year() << "-" << j.month() << "-" << j.day()  << ": " << j.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << (int)j.julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "56812" << std::endl;
	std::cout << "\n";
/*
	std::cout << "Julian - Date: " << j.year() << "-" << j.month() << "-" << j.day()  << ": " << j.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "54899" << std::endl;
	std::cout << "\n\n";
	g = Julian(1970, 1, 17);
//	j = Julian(1970, 1, 17);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 2 - Date: 1970-1-17: Saturday\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g.year() << "-" << g.month() << "-" << g.day()  << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "40603" << std::endl;
	std::cout << "\n";
	//std::cout << "Julian - Date: " << j.year() << "-" << j.month() << "-" << j.day()  << ": " << j.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "40616" << std::endl;
	std::cout << "\n\n";
	g = Julian();
//	j = Julian();
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 3 - Date: Today! all dates should be the same!\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g.year() << "-" << g.month() << "-" << g.day()  << ": " << g.week_day_name() << std::endl;
	std::cout << "          JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "\n";
	std::cout << "Julian - Date: " << j.year() << "-" << j.month() << "-" << j.day()  << ": " << j.week_day_name() << std::endl;
	std::cout << "          JDN: " << j.mod_julian_day() << std::endl;
	std::cout << "\n\n";

	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "--------------------------------------------------------------------------------\n";
	g = Julian(1923, 3, 1);
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

	g = Julian(1858, 1, 1);
//	j = Julian(1900, 2, 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 5 - Date: 1858-01-01\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "-1" << std::endl;
	std::cout << "\n";

	g = Julian(2033, 8, 20);
//	j = Julian(1900, 2, 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 6 - Date: 2033-08-20\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "-1" << std::endl;
	std::cout << "\n";

	set_k_time(717119999);
	g = Julian();
//	j = Julian(1900, 2, 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 7 - Date: 1992-09-21\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "Expected  JDN: " << "-1" << std::endl;
	std::cout << "\n";

	set_k_time(717120000);// + 86400/4);
	g = Julian();
//	j = Julian(1900, 2, 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 8 - Date: 1992-09-22\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "\n";


	g = Julian(1992,9,22);
//	j = Julian(1900, 2, 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 9 - Date: 1992-09-22\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "\n";

	set_k_time(212158799);// + 86400/4);
	g = Julian();
//	j = Julian(1900, 2, 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 10 - Date: 1976-09-21\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "\n";

	set_k_time(0);// + 86400/4);
	g = Julian();
//	j = Julian(1900, 2, 29);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 11 - Date: 1970-01-01\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "\n";

	set_k_time(2008152549);// + 86400/4);
	g = Julian();
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 12 - Date: 2033-08-20\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "\n";

	g = Julian(2093,1,1);
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "Test 13 - Date: 2093-01-01\n";
	std::cout << "\n";

	std::cout << "Gregor - Date: " << g << ": " << g.week_day_name() << std::endl;
	std::cout << "Actual    JDN: " << g.mod_julian_day() << std::endl;
	std::cout << "\n";
	*/
	return 0;
}
