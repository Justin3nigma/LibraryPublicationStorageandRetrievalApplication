/*
Menu.cpp
Name : JaehyunAhn (Justin)
Student Number : 157826181
Email : jahn31@myseneca.ca
Date : 11/19/2019
Section : NEE
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <cstring>

#include "Menu.h"
#include "Utils.h"


using namespace std;
namespace sdds {

	MenuItem::MenuItem() {
		midesc = nullptr;
	}

	MenuItem::MenuItem(const char* mi_desc) {
		midesc = new char[strlen(mi_desc) + 1];
		strcpy(midesc, mi_desc);
	}

	MenuItem::~MenuItem() {
		delete[] midesc;
	}

	MenuItem::operator bool()const {
		return midesc != nullptr;
	}

	MenuItem::operator const char* () {
		return midesc;
	}

	std::ostream& MenuItem::display(std::ostream& os) {
		os << midesc;
		return os;
	}

	Menu::Menu() {
		m_items[0] = nullptr;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
			m_items[i] = nullptr;
		}
		no_m_items = 0;
	}

	Menu::Menu(const char* m_title) {
		title.midesc = new char[strlen(m_title) + 1];
		strcpy(title.midesc, m_title);

		m_items[0] = nullptr;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
			m_items[i] = nullptr;
		}
		no_m_items = 0;
	}

	Menu::~Menu() {
		delete[] title;

		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			delete m_items[i];
			m_items[i] = nullptr;
		}
	}

	ostream& Menu::Display_Title(ostream& os)const {
		if (title.midesc != nullptr) {
			os << title;
		}
		return os;
	}

	ostream& Menu::Display(ostream& os)const {
		int i = 0;
		if (title.midesc != nullptr) {
			Display_Title(os) << ':' << endl;
		}

		while (m_items[i] != nullptr) {
			os << " " << i + 1 << "- " << (const char*)*m_items[i] << endl;
			i++;
		}
		os << " 0- Exit" << endl << "> ";
		return os;
	}

	Menu& Menu::operator<<(const char* mi_des) {
		if (no_m_items < int(MAX_MENU_ITEMS)) {
			m_items[no_m_items] = new MenuItem(mi_des);
			++no_m_items;
		}
		return *this;
	}

	unsigned int Menu::getSelection() {
		int selection = 0;
		bool ok = false;

		Display();
		do {
			cin >> selection;
			if (cin.fail() || selection < 0 || selection > no_m_items) {
				cin.clear();
				cin.ignore(1000, '\n');
				ok = true;
				cout << "Invalid Selection, try again: ";
			}
			else {
				ok = false;
				cin.ignore(1000, '\n');
			}

		} while (ok);

		return selection;
	}

	int Menu::operator~() {
		return getSelection();
	}

	Menu::operator int()const {
		return no_m_items;
	}

	Menu::operator unsigned int()const {
		return (unsigned int)no_m_items;
	}

	Menu::operator bool()const {
		return no_m_items > 0;
	}

	ostream& operator<<(ostream& os, Menu& menu) {
		menu.Display_Title(os);
		return os;
	}

	const char* Menu::operator[](int index)const {

		if (index >= 0 && m_items[index] != nullptr)
			return (const char*)*m_items[(index + 1) % no_m_items == 0 ? no_m_items - 1 : (index + 1) % no_m_items - 1];
		else
			return nullptr;
	}

}