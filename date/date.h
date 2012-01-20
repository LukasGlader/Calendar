#include <string>
#include <iostream>
namespace lab2{

class Date
{
public:
	Date(void);
	~Date(void);

	virtual int mod_julian_day() const = 0;
	virtual double julian_day() const = 0;

	const virtual int year() const = 0;
	const virtual int month() const = 0;
	const virtual int day() const = 0;
	const virtual int week_day() const = 0;

	const virtual int days_per_week() const = 0;
	const virtual int days_this_month() const = 0;

	const virtual int months_per_year() const = 0;
	const virtual std::string week_day_name() const = 0;
	const virtual std::string month_name() const = 0;

	//prefix
	virtual Date& operator++() = 0;
	virtual Date& operator--() = 0;

	virtual void operator+=(int n) = 0;
	virtual void operator-=(int n) = 0;

	virtual Date& add_year(int n) = 0;
	virtual Date& add_year() = 0;
	virtual Date& add_month(int n) = 0;
	virtual Date& add_month() = 0;

	const virtual bool operator==(const Date& d) const;
	const virtual bool operator!=(const Date& d) const;
	const virtual bool operator<(const Date& d) const;
	const virtual bool operator<=(const Date& d) const;
	const virtual bool operator>(const Date& d) const;
	const virtual bool operator>=(const Date& d) const;
	const virtual int operator-(const Date& d) const;

protected:
	//state
	double julian_day_number;
};
std::ostream& operator<<(std::ostream & os, const Date& d);

}
