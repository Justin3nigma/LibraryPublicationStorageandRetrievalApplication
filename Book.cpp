/*
Book.cpp
Name : JaehyunAhn (Justin)
Student Number : 157826181
Email : jahn31@myseneca.ca
Date : 12/1/2019
Section : NEE
*/

#include "Book.h"

namespace sdds {

	Book::Book() {
		ISBN = 0;
		Mem_ID = 0;
	}

	Book::Book(const Book& book) : PubRecord(book) {
		ISBN = book.ISBN;
		Mem_ID = 0;
		R_date = book.R_date;
	}

	char Book::recID() const {
		return 'B';
	}

	int Book::memberID() const {
		return Mem_ID;
	}

	long int Book::isbn() const {
		return ISBN;
	}

	Date Book::returnDate() const {
		return R_date;
	}

	void Book::checkIn() {
		Mem_ID = 0;
		cout << name() << " checked in!" << '\n';
	}

	void Book::checkOut() {
		bool ok;
		cout << "Entere Member id: ";
		do {
			cin >> Mem_ID;
			ok = !(Mem_ID >= 100000 || Mem_ID <= 9999);
		} while (!ok && cout << "Invalid Member ID, Enter again: ");
		cout << "Enter return date: ";
		do {
			cin >> R_date;
		} while (R_date.error());

		Date today;

		while (R_date - today < 0) {
			cout << "Please enter a future date." << '\n';
			do {
				cin >> R_date;
			} while (R_date.error());
		}

		while (R_date - today > 30) {
			cout << "The return date must be earlier than 30 days away from today." << '\n';
			do {
				cin >> R_date;
			} while (R_date.error());
		}
	}

	istream& Book::read(istream& is) {
		char title_[41];
		Date date_;
		if (mediaType() == SDDS_CONSOLE) {
			Mem_ID = 0;
			cout << "Book Name: ";
			::read(title_, 40, "Book name too long, Enter again: ");
			name(title_);
			cout << "ISBN: ";
			cin >> ISBN;
			cout << "Shelf Number: ";
			readShelfNo();
		}
		if (mediaType() == SDDS_FILE) {
			is.getline(title_, 40, '\t') >> ISBN;
			is.ignore(100, '\t') >> Shelf_num;
			is.ignore(100, '\t') >> Mem_ID;
			if (memberID() != 0) {
				is.ignore(100, '\t');
				is >> date_;
				is.ignore(100, '\n');
			}
			R_date = date_;
			name(title_);
		}
		return is;
	}

	ostream& Book::write(ostream& os)const {
		if (mediaType() == SDDS_CONSOLE) {
			os.setf(std::ios::left);
			os << setw(41) << name();
			os.unsetf(ios::left);
			os << ISBN << "  " << shelfNo();
			if (Mem_ID)
				os << " " << Mem_ID << "   " << R_date;
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() << name() << '\t' << ISBN << '\t' << shelfNo() << '\t' << Mem_ID;
			if (Mem_ID)
				os << '\t' << R_date;
			os << endl;
		}
		return os;
	}

	Book& Book::operator=(const Book& given_book) {
		name(given_book.PR_name);
		mediaType(given_book.mediaType());
		Shelf_num = given_book.shelfNo();
		ISBN = given_book.ISBN;
		Mem_ID = 0;
		R_date = given_book.R_date;
		return *this;
	}
}