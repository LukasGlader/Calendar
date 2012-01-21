#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "date.h"
#include "gregorian.h"
#include "event.h"

namespace lab2 {
	using namespace std;

template <class T> class Calendar
{

protected:

	template<class U> friend std::ostream& operator<<(std::ostream&,const Calendar<U>&);
	

public:

	T* currentDate;
	vector<Event*>* events;

Calendar(void) {
	currentDate = new T();
	events = new vector<Event*>();
}

template <class S>
Calendar(const Calendar<S> & other) {

	if(static_cast<void*>(this) == &other) {
		return;
	}

	currentDate = new T(); 
	*currentDate -= currentDate->mod_julian_day();
	*currentDate += other.currentDate->mod_julian_day();
	
	typename vector<Event* >::iterator it;
	it = other.events->begin();
	events->clear();
	for(;it!=other.events->end();it++) {
		T* tmpDate = new T((*it)->getDate());
		
		Event eventCopy((*it)->getEventName(), tmpDate);
		events->push_back(&eventCopy);
	}
}

~Calendar(void) {
}
bool set_date(int year, int month, int day) {
	Date* current = currentDate;

	try {
	currentDate = new T(year, month, day);
	delete(current);
		}catch (...) {
	return false;
	}
	return true;
}


bool add_event(string eventName) {
	return add_event(eventName, new T());
}
bool add_event(string eventName, int day) {
	return add_event(eventName, T().month(), day);
}
bool add_event(string eventName, int month, int day) {
	return add_event(eventName, T().year(), month, day);
}
bool add_event(string eventName, int year, int month, int day) {
		T* d;
try {
		d = new T(year, month, day);
	}catch(...) {
		return false;
	}
	return add_event(eventName, d);
}


bool remove_event(string name) {
	T* d = new T();
	return remove_event(name, d);
}
bool remove_event(string name, int day) {
	return remove_event(name, T().month(), day);
}
bool remove_event(string name, int month, int day) {
	return remove_event(name, T().year(), month, day);
}
bool remove_event(string name, int year, int month, int day) {
	T* d;
	try{
	d = new T(year, month, day);
	}catch (...) {
		return false;
	}
	return true;
}


//Assignment operator.
Calendar<T>& operator=(const Calendar& other) {

	delete(currentDate); //Clean
	this->currentDate = other.currentDate; //Assign

	delete[] events; //Clean
	this->events = other.events; //Assign

	//TODO: copy more values
	return *this;
}
	
//Private, does the heavy lifting once the public ones have checked for valid input and standardized
//their parameters (made a date).
bool add_event(string eventName, Date* d) {
	if(indexOf(eventName, *d) > 0) //Exists.
		return false;
	events->push_back(new Event(eventName, d));
	return true;
}

//Private, actually does the removing after doing an exists-check.
bool remove_event(string eventName, Date* d) {
	int i = indexOf(eventName, *d);
	if(i < 0) //Doesn't exist
		return false;
	events->erase(events->begin() + i);
	return true;
}


//Returns the index of the given event name+date combo, or negative number if not found.
int indexOf(string name, Date& d) {
	for(int i = 0; i < events->size(); ++i) {
		Event* e = (*events)[i];

		if(e->getEventName() == name && e->getDate() == d)
			return i;
	}
	return -1;
}

};


template <class U>
ostream& operator<<(ostream& o, const Calendar<U>& cal){

	sort(cal.events->begin(), cal.events->end());
	U* start = new U();

	vector<Event*>::iterator it;
	//First, skip ahead to today
	for(it = cal.events->begin(); it != cal.events->end(); ++it){
		Date* current = &(*it)->getDate();
		if(current->julian_day() == start->julian_day()) //Todays date, this is where we start.
			break; //++it will take care of getting us to start+1, so we're done here
	}
		
	for(; it != cal.events->end(); ++it) {
		o << *it;
	}
	delete(start);
	return o;
}

}
