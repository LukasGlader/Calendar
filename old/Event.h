#pragma once

#include <string>
#include "date.h"

namespace lab2 {
	using namespace std;

class Event
{

public:
	Event(string, Date* date);

	~Event(void);

	ostream& operator<<(ostream&);

	string getEventName();
	Date& getDate();
private:
	string name;
	Date* date;
};

}
