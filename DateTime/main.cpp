#include <iostream>
#include <cstring>
#include "Date.h"
#include "Trip.h"
#include "ManagementTrip.h"
#pragma warning(disable:4996)
using namespace std;

#include "Trip.h"
int TRIP_COUNTER = 1;

bool IsEmpty(int size);
void Print(Trip* arr, int size);
void EditTrip(Trip* arr, int size);
Trip* AddTrip(Trip* arr, int size);



void main() {
	int option;
	Trip* arr = new Trip[0];
	int size = 0;
	int * COUNTER = 0;
	ManagementTrip  mts;

	/*
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
	} while (option != 4);*/
	do {
		cout << "Please Select an option: \n1. Print Trips\n2. Delete Trip\n3. Add Trip\n4. Exit" << endl;
		cin >> option;

		switch (option) {
		case 1:
			mts >> nullptr;  // Prints all trips in `mts`
			break;

		case 2: {
			char destination[30];
			int day;
			int month;
			int year;
			cout << "enter destination" << endl;
			cin >> destination;
			cout << "enter date:" << endl;
			cout << "enter day" << endl;
			cin >> day;
			cout << "enter month" << endl;
			cin >> month;
			cout << "enter year" << endl;
			cin >> year;
			Date dateToDelete(day, month, year);
			Trip tempTrip(destination,dateToDelete);  // Temporary trip with the date to delete
			mts -= &tempTrip;  // Remove trips on the specified date
			break;
		}

		case 3: {
			char destination[30];
			int day;
			int month;
			int year;
			cout << "enter destination" << endl;
			cin >> destination;
			cout << "enter date:" << endl;
			cout << "enter day" << endl;
			cin >> day;
			cout << "enter month" << endl;
			cin >> month;
			cout << "enter year" << endl;
			cin >> year;
			Date tripDate(day, month, year);
			Trip* newTrip = new Trip(destination,tripDate);  // Create a new Trip
			mts += newTrip;  // Add the trip to `mts`
			break;
		}

		case 4:
			cout << "bye bye!" << endl;
			break;

		default:
			cout << "Invalid option" << endl;
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
			cout << "would you like to change the id? press 1 for yes or any other key for no" << endl;
			cin >> option;
			if (option == 1) {
				cout << "enter new id" << endl;
				int id;
				cin >> id;
				arr[i].setId(id);
			}
			cout << "would you like to change the destination? press 1 for yes or any other key for no" << endl;
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
	char destination[30];
	int day;
	int month;
	int year;
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
	newArr[size] = Trip( destination, date);
	delete[]arr;
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

bool Date::operator==(Date other) {
	return this->day == other.getDay() && this->month == other.getMonth() && this->year == other.getYear();
}bool Date::operator>(Date other) {
	if (this->year > other.getYear()) {
		return true;
	}
	else if (this->year == other.getYear()) {
		if (this->month > other.getMonth()) {
			return true;
		}
		else if (this->month == other.getMonth()) {
			return this->day > other.getDay();
		}
	}
	return false;
}
bool Date::operator<(Date other) {
	if (this->year < other.getYear()) {
		return true;
	}
	else if (this->year == other.getYear()) {
		if (this->month < other.getMonth()) {
			return true;
		}
		else if (this->month == other.getMonth()) {
			return this->day < other.getDay();
		}
	}
	return false;
}

//////////////////////////trip


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

Trip::Trip( char destination[30], Date date) {
	setId(TRIP_COUNTER);
	setDestination(destination);
	setDate(date);
	TRIP_COUNTER++;
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
	date.printDate();
}

///////////////ManageTrips
ManagementTrip::ManagementTrip() {
	this->index = 0;
	this->trips = new Trip * [0];
}
const ManagementTrip& ManagementTrip::operator=(const ManagementTrip& other) {
	if (this != &other) {
		for (int i = 0; i < this->index; ++i) {
			delete this->trips[i];
		}
		delete[] this->trips;
		this->index = other.index;
		this->trips = new Trip * [this->index];
		for (int i = 0; i < this->index; ++i) {
			this->trips[i] = new Trip(*other.trips[i]);
		}
	}
	return *this;
}





void ManagementTrip::operator+=(Trip* other) {
	int newSize = this->index + 1;
	Trip** newArr = new Trip * [newSize];

	for (int i = 0; i < this->index; ++i) {
		newArr[i] = this->trips[i];
	}
	newArr[this->index] = other;
	delete[] this->trips;
	this->trips = newArr;
	this->index = newSize;
}
void ManagementTrip::operator-=(Trip* other) {
	Date date = other->getDate();
	int newSize = 0;

	for (int i = 0; i < this->index; ++i) {
		if (!(trips[i]->getDate() == date)) {
			++newSize;
		}
	}

	Trip** newArr = new Trip * [newSize];
	int j = 0;

	for (int i = 0; i < this->index; ++i) {
		if (!(trips[i]->getDate() == date)) {
			newArr[j++] = trips[i];
		}
		else {
			delete trips[i];
		}
	}

	delete[] trips;
	trips = newArr;
	index = newSize;
}
void ManagementTrip::operator>>(Trip* other) {
	if (this->index == 0)
	{
		cout << "there are no trips " << endl;
		return;
	}
	for (int i = 0; i < this->index; ++i) {
		this->trips[i]->printTrip();
	}
	
}





 