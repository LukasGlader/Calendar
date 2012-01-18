#include "Event.h"
#include "date.h"


namespace lab2 {
Event::Event(string name, Date* date)
{
	this->name = name;
	this->date = date;
}


string Event::getEventName() {
	return name;
}

Date& Event::getDate() {
	return *date;
}

ostream& Event::operator<<(ostream& o) {
	o << date << " : " << name << std::endl;
	return o;
}

Event::~Event(void)
{
}

}
