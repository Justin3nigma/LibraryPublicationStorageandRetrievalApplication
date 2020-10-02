/*
Utils.cpp
Name : JaehyunAhn (Justin)
Student Number : 157826181
Email : jahn31@myseneca.ca
Date : 12/1/2019
Section : NEE
*/

#include "Utils.h"

using namespace std;

void read(char *str, int len, const char * message) {
    bool ok;
    do {
        ok = true;
        cin.getline(str, len + 1, '\n');
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
        }
    } while (!ok && cout << message);
}

void read(int& num, int min, int max, const char* message) {
	bool ok;
	char newline;
	do {
		cin >> num;
		newline = cin.get();
		if (cin.fail() || newline != '\n') {
			ok = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			ok = num <= max && num >= min;
		}
	} while (!ok && cout << message);
}