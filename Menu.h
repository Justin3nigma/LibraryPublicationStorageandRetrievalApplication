/*
Menu.h
Name : JaehyunAhn (Justin)
Student Number : 157826181
Email : jahn31@myseneca.ca
Date : 11/19/2019
Section : NEE
*/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>
using namespace std;
namespace sdds {

	const unsigned int MAX_MENU_ITEMS = 20;
	const unsigned int MAX_TITLE_LEN = 30;

	class MenuItem {
		char* midesc;

		MenuItem();
		MenuItem(const char*);
		MenuItem(const MenuItem&) = delete;
		~MenuItem();

		void operator=(const MenuItem&) = delete;

		operator bool()const;
		operator const char* ();

		std::ostream& display(std::ostream& os = cout);

		friend class Menu;
	};

	class Menu {
		MenuItem title;
		MenuItem* m_items[MAX_MENU_ITEMS];
		int no_m_items;

	public:
		Menu();
		Menu(const char* m_title);
		~Menu();
		Menu(const Menu&) = delete;

		void operator=(const Menu&) = delete;

		std::ostream& Display_Title(std::ostream& os = cout)const;
		std::ostream& Display(std::ostream& os = cout)const;
		Menu& operator<<(const char* menu_item_des);

		unsigned int getSelection();
		int operator~();

		operator int()const;
		operator unsigned int()const;

		operator bool()const;

		const char* operator[](int index)const;
	};

	std::ostream& operator<<(std::ostream& os, Menu& menu);
}
#endif