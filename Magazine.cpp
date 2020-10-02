/*
Magazine.cpp
Name : JaehyunAhn (Justin)
Student Number : 157826181
Email : jahn31@myseneca.ca
Date : 12/1/2019
Section : NEE
*/

#include "Magazine.h"

namespace sdds {

	Magazine::Magazine() {
		m_issues = 0;
		m_Volumes = 0;
	}

	Magazine::Magazine(const Magazine& magazine_) : PubRecord(magazine_) {
		m_Volumes = magazine_.m_Volumes;
		m_issues = magazine_.m_issues;
	}

	char Magazine::recID() const {
		return 'M';
	}

	void Magazine::checkIn() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}

	void Magazine::checkOut() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}

	istream& Magazine::read(istream& is) {
		char title[41];

		if (mediaType() == SDDS_CONSOLE) {
			cout << "Magazine Name: ";
			::read(title, 40, "Magazine name too long, Enter again: ");
			name(title);
			cout << "Volume: ";
			::read(m_Volumes, 1, 99, "Invalid Volume number, Enter again: ");
			cout << "Issue: ";
			::read(m_issues, 1, 99, "Invalid Issue number, Enter again: ");
			cout << "Shelf Number: ";
			readShelfNo();
		}

		else if (mediaType() == SDDS_FILE) {
			is.getline(title, 40, '\t');
			is >> m_Volumes;
			is.ignore(100, '\t');
			is >> m_issues;
			is.ignore(100, '\t');
			is >> Shelf_num;
			is.ignore(100, '\n');
			name(title);
		}
		return is;
	}

	ostream& Magazine::write(ostream& os) const {
		if (mediaType() == SDDS_CONSOLE) {
			os.setf(std::ios::left);
			os << setw(41) << name();
			os.unsetf(ios::left);
			os << "       " << setw(2) << setfill('0') << m_Volumes << '('
				<< setw(2) << m_issues << setfill(' ') << ")  " << shelfNo();
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() << name() << '\t' << m_Volumes << '\t' << m_issues
				<< '\t' << shelfNo() << endl;
		}
		return os;
	}

	int Magazine::vol() const {
		return m_Volumes;
	}

	int Magazine::issue() const {
		return m_issues;
	}
}