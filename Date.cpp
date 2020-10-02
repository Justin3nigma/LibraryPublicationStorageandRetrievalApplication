/*
Date.cpp
Name : JaehyunAhn (Justin)
Student Number : 157826181
Email : jahn31@myseneca.ca
Date : 11/19/2019
Section : NEE
*/

// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2019/11/11		       Preliminary release
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include "Date.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	bool Date::validate() {
		errCode(NO_ERROR);
		if (m_year < MIN_YEAR || m_year > m_CUR_YEAR) {
			errCode(YEAR_ERROR);
		}
		else if (m_mon < 1 || m_mon > 12) {
			errCode(MON_ERROR);
		}
		else if (m_day < 1 || m_day > mdays()) {
			errCode(DAY_ERROR);
		}
		return !bad();
	}

	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
		mon--;
		return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
	}

	int Date::curYear()const {
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		return lt.tm_year + 1900;
	}

	void Date::setToToday() {
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		m_day = lt.tm_mday;
		m_mon = lt.tm_mon + 1;
		m_year = lt.tm_year + 1900;
		errCode(NO_ERROR);
	}
	int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
		int ty = m_year;
		int tm = m_mon;
		if (tm < 3) {
			ty--;
			tm += 12;
		}
		return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
	}
	Date::Date() :m_CUR_YEAR(curYear()) {
		setToToday();
	}
	Date::Date(int year, int mon, int day) : m_CUR_YEAR(curYear()) {
		m_year = year;
		m_mon = mon;
		m_day = day;
		validate();
	}
	const char* Date::dateStatus()const {
		return DATE_ERROR[errCode()];
	}
	int Date::currentYear()const {
		return m_CUR_YEAR;
	}
	void Date::errCode(int readErrorCode) {
		m_ErrorCode = readErrorCode;
	}
	int Date::errCode()const {
		return m_ErrorCode;
	}
	bool Date::bad()const {
		return m_ErrorCode != 0;
	}

	bool Date::error() {
		return bad();
	}

	istream& Date::read(istream& is) {
		errCode(NO_ERROR); // - Clear the error code by setting it NO_ERROR

		/*-Read the year, the monthand the day member variables using istreamand
		ignore a single character after the yearand the month values to bypass the Slashes*/
		is >> m_year;
		is.ignore(1); // Ignoring a single character
		is >> m_mon;
		is.ignore(1);
		is >> m_day;

		if (is.fail()) {//- Check and see if istream has failed. If it did fail, set the error code to CIN_FAILED and clear the istream.
			errCode(CIN_FAILED);
			is.clear();
			is.ignore(1000, '\n');
		}

		else {
			validate();//if not, validate the values entered.
		}

		return is;
	}

	ostream& Date::write(ostream& os)const {
		if (bad())
			//If the Date object is in a “bad” state or (it is invalid) print the “dateStatus()”
			os << dateStatus();
		else {
			//otherwise the function should write the date in the following format using the ostream object:
			os << m_year << "/";
			os.fill('0');//padding the left digit with zero
			os.width(2);//print month in twospace
			os << m_mon;
			os << "/";
			os.fill('0');
			os.width(2);
			os << m_day;
			os.fill(' ');
		}
		return os;
	}

	bool Date::operator==(const Date date)const {
		bool ok = true;
		if (daysSince0001_1_1() == date.daysSince0001_1_1()) {
			return ok;
		}
		else {
			ok = false;
		}
		return ok;
	}

	bool Date::operator!=(const Date date)const {
		if (daysSince0001_1_1() != date.daysSince0001_1_1()) {
			return true;
		}
		else
			return false;

	}

	bool Date::operator>=(const Date date)const {
		if (daysSince0001_1_1() >= date.daysSince0001_1_1()) {
			return true;
		}
		else
			return false;
	}

	bool Date::operator<=(const Date date)const {
		if (daysSince0001_1_1() <= date.daysSince0001_1_1()) {
			return true;
		}
		else
			return false;

	}
	bool Date::operator<(const Date date)const {
		if (daysSince0001_1_1() < date.daysSince0001_1_1()) {
			return true;
		}
		else
			return false;

	}
	bool Date::operator>(const Date date)const {
		if (daysSince0001_1_1() > date.daysSince0001_1_1()) {
			return true;
		}
		else
			return false;
	}

	int Date::operator-(const Date date)const {
		int day = daysSince0001_1_1() - date.daysSince0001_1_1();
		return day;
	}

	Date::operator bool()const {
		return !bad();
	}

	ostream& operator<<(ostream& os, const Date& date) {
		date.write(os);
		return os;
	}

	istream& operator>>(istream& is, Date& date) {
		date.read(is);
		return is;
	}

}

