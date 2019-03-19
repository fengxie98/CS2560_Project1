// DateClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
	int month, day, year;
	int days[12]; //days 1-12 for each month in the calendar

public:
	Date() { //def constr

	}

	Date(int months, int days, int years) {
		month = months;
		day = days;
		year = years;
		setDaysEachMonth();
	}

	void setDaysEachMonth() {
		days[0] = 31;
		days[1] = 28;
		days[2] = 31;
		days[3] = 30;
		days[4] = 31;
		days[5] = 30;
		days[6] = 31;
		days[7] = 31;
		days[8] = 30;
		days[9] = 31;
		days[10] = 30;
		days[11] = 31;
	}

	void printResult() {
		int yearSub;
		yearSub = year - 2000;
		cout << month << "/" << day << "/";
		if (yearSub < 10)
			cout << "0" << yearSub << endl;
		else
			cout << yearSub << endl;
	}

	//f(x) prints month in letters
	string printmonth(int month) {
		string monthName[] = { "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };
		return monthName[month - 1];
	}

	//getMonth
	int getMonth() {
		return month;
	}

	//getDay
	int getDay() {
		return day;
	}

	//getYear
	int getYear() {
		return year;
	}

	//setMonth
	Date setMonth(int m) {
		month = m;
	}

	Date setDay(int d) {
		day = d;
	}

	Date setYear(int y) {
		year = y;
	}

	//prefix increment operator
	Date operator++() {
		Date temp(month, day, year);
		if (day == days[month - 1]) {
			day = 1;
			month++;
			month %= 12;
			if (month == 1)
				year++;
		}
		else
			day++;
		return temp;
	}

	//Postfix increment operator
	Date operator++(int) {
		Date temp(month, day, year);
		if (day == days[month - 1]) {
			day = 1;
			month++;
			month %= 12;
			if (month == 1)
				year++;
		}
		else
			day++;
		return temp;
	}

	//prefix decrement operator
	Date operator--() {
		Date temp(month, day, year);
		day--;
		if (day == 0) {
			month--;
			if (month == 0) {
				month = 12;
				year--;
			}
			day = days[month - 1];
		}
		return temp;
	}

	//postfix decrement operator
	Date operator--(int) {
		Date temp(month, day, year);
		day--;
		if (day == 0) {
			month--;
			if (month == 0) {
				month = 12;
				year--;
			}
			day = days[month - 1];
		}
		return temp;
	}
	//subtraction operator
	int operator - (const Date &obj) {
		return obj.day - day;
	}

	friend ostream &operator<<(ostream &strm, Date &obj) {
		strm << obj.printmonth(obj.month) << " " << obj.day << ", " << obj.year << endl;
		return strm;
	}

	friend istream &operator>>(istream &strm, Date &obj) {
		int valid = 0;
		do {
			cout << "Enter Month: ";
			strm >> obj.month;
			cout << "Enter Day : ";
			strm >> obj.day;
			cout << "Enter Year : ";
			strm >> obj.year;

			if (obj.day <= 0)
				valid = 0;

			switch (obj.month) {
			case 1:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11: if (obj.day > 30) valid = 0;
					 else valid = 1;
			case 12: if (obj.day > 31) valid = 0; else valid = 1;
			case 2: if (obj.day > 29) valid = 0;
				if (obj.day < 29) valid = 1;
			}
			if (valid == 0) {
				cout << endl << "The date " << obj.month << "/" << obj.day << "/" << obj.year << " not be accepted. Enter a valid date." << endl << endl;
			}
		} while (valid != 1);
		return strm;
	}
};



int main()
{
	std::cout << "Hello World!\n";

	int sub;

	Date obj;
	Date objl;

	cout << "This is the Extraction operator: " << endl;

	cout << endl << "Enter a date... " << endl << endl;
	cin >> obj;
	cout << endl << endl << "Enter another date... " << endl << endl;
	cout << "";
	cin >> objl;

	cout << endl << endl << "After prefix increment: ";
	++obj;
	obj.printResult();

	cout << endl << endl << "After prefix increment: ";
	++obj;
	obj.printResult();

	cout << "After postfix increment: ";
	obj++;
	obj.printResult();
	cout << "After prefix decrement: ";
	obj--;
	obj.printResult();

	sub = obj - objl;
	cout << endl << endl << "Subtraction operator: " << obj << "is subtracted from " << objl << "result is: " << sub << endl;

	cout << endl << "This is the stream insertion ";
	cout << obj;

	system("pause)");
	return 0;
}