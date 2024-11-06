#include <iostream>
#include <cstring>
#include "Date.h"
#include "Trip.h"
#pragma warning(disable:4996)
using namespace std;

#include "Trip.h"
//Globals:
int counter = 0;


bool IsEmpty(int size);
void Print(Trip* arr, int size);
void EditTrip(Trip* arr, int size);
Trip* AddTrip(Trip* arr, int size);

void main() {
	int option;
	Trip* arr = new Trip[0];
	int size = 0;

	do {
		cout << "Please Select an option: \n1.Print Trips\n2.Edit Trip\n3.Add Trip\n4.Exit" << endl;
		cin >> option;

		switch (option) {
		case 1:
			Print(arr, size);
			break;
		case 2:
			EditTrip(arr, size);
			break;
		case 3:
			arr = AddTrip(arr, size);
			size++;
			break;
		case 4:
			cout << "bye bye!" << endl;
			break;
		default:
			cout << "invalid option" << endl;
			break;
		}
	} while (option != 4);
}

bool IsEmpty(int size)
{
	if (size == 0) {
		return true;
	}
	return false;
}

void Print(Trip* arr, int size)
{
	if (IsEmpty(size)) {
		cout << "there are no saved trips" << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			arr[i].printTrip();
			cout << endl;
		}
	}
}

void EditTrip(Trip* arr, int size)
{
	if (IsEmpty(size)) {
		cout << "there are no saved trips" << endl;
	}
	else {
		int id;
		bool isFound = false;
		cout << "enter trip id" << endl;
		cin >> id;
		int i;
		for (i = 0; i < size && !isFound; i++) {
			if (arr[i].getId() == id) {
				isFound = true;
				i--;
			}
		}
		if (!isFound) {
			cout << "trip not found" << endl;
		}
		else {
			int option;
			cout << "would you like to change the id? press 1 for yes or any other number for no" << endl;
			cin >> option;
			if (option == 1) {
				cout << "enter new id" << endl;
				int id;
				cin >> id;
				arr[i].setId(id);
			}
			cout << "would you like to change the destination? press 1 for yes or any other number for no" << endl;
			cin >> option;
			if (option == 1) {
				cout << "enter new destination" << endl;
				char destination[30];
				cin >> destination;
				arr[i].setDestination(destination);
			}
			cout << "would you like to change the date? press 1 for yes or any other number for no" << endl;
			cin >> option;
			if (option == 1) {
				int day, month, year;
				cout << "enter new day" << endl;
				cin >> day;
				cout << "enter new month" << endl;
				cin >> month;
				cout << "enter new year" << endl;
				cin >> year;

				Date newDate(day, month, year);
				arr[i].setDate(newDate);
			}
		}
	}
}

Trip* AddTrip(Trip* arr, int size)
{
	int id;
	char destination[30];
	int day;
	int month;
	int year;
	cout << "enter trip id" << endl;
	cin >> id;
	cout << "enter destination" << endl;
	cin >> destination;
	cout << "enter date:" << endl;
	cout << "enter day" << endl;
	cin >> day;
	cout << "enter month" << endl;
	cin >> month;
	cout << "enter year" << endl;
	cin >> year;
	Date date = Date(day, month, year);
	Trip* newArr = new Trip[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i] = Trip(arr[i]);
	}
	newArr[size] = Trip(id, destination, date);
	return newArr;
}

void Date::setDay(int day) {
	if (day >= 1 && day <= 30) {
		this->day = day;
	}
}

void Date::setMonth(int month) {
	if (month >= 1 && month <= 12) {
		this->month = month;
	}
}

void Date::setYear(int year) {
	this->year = year;
}

Date::Date(int day, int month, int year) {
	setDay(day);
	setMonth(month);
	setYear(year);
}

Date::Date() {
	Date(25, 9, 2024);
}

void Date::printDate() {
	cout << day << "/" << month << "/" << year << endl;
}

bool Date::operator==(Date d) {
	return this->day == d.getDay() && this->month == d.getMonth() && this->year == d.getYear();
}
bool Date::operator>(Date d) {
	if (this->year > d.getYear()) {
		return true;
	}
	else if (this->year == d.getYear()) {
		if (this->month > d.getMonth()) {
			return true;
		}
		else if (this->month == d.getMonth()) {
			return this->day > d.getDay();
		}
	}
	return false;
}

bool Date::operator<(Date d) {
	if (this->year < d.getYear()) {
		return true;
	}
	else if (this->year == d.getYear()) {
		if (this->month < d.getMonth()) {
			return true;
		}
		else if (this->month == d.getMonth()) {
			return this->day < d.getDay();
		}
	}
	return false;
}

void Trip::setId(int id) {
	if (id < 0) {
		id = 0;
	}
	this->id = id;
}

void Trip::setDestination(char destination[30]) {
	for (int i = 0; i <= strlen(destination); i++) {
		if ((destination[i] < 'a' && destination[i] > 'z') || (destination[i] < 'A' && destination[i] > 'Z')) {
			strcpy(destination, "Jerusalem");
		}
	}
	this->destination = new char[strlen(destination) + 1];
	strcpy(this->destination, destination);
}

void Trip::setDate(Date date) {
	this->date = Date(date.getDay(), date.getMonth(), date.getYear());
}

Trip::Trip(char destination[30], Date date) {
	setId(counter++);
	setDestination(destination);
	setDate(date);
}

Trip::Trip() {
	id = 999;
	destination = new char[strlen("Jerusalem") + 1];
	strcpy(destination, "Jerusalem");
	date = Date();
}


Trip::Trip(const Trip& other) {
	destination = NULL;
	*this = other;
}

const Trip& Trip::operator=(const Trip& other) {
	if (this != &other) {
		id = other.id;
		date.setDay(other.date.getDay());
		date.setMonth(other.date.getMonth());
		date.setYear(other.date.getYear());

		if (destination) {
			delete[] destination;
		}

		
		destination = new char[strlen(other.destination) + 1];
		strcpy(destination, other.destination);
	}
	return *this;
}


Trip:: ~Trip() {
	delete[]destination;
}

void Trip::printTrip() {
	cout << "trip id: " << id << endl;
	cout << "trip destination: " << destination << endl;
	cout << "trip date: ";
	date.printDate() ;
}