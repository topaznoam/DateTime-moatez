#ifndef __DATE_H
#define __DATE_H

class Date {
	int day;
	int month;
	int year;

public:
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	Date(int day, int month, int year);
	Date();
	void printDate();
	bool operator==(Date other);
	bool operator>(Date other);
	bool operator<(Date other);




};
#endif