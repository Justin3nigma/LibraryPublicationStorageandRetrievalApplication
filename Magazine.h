/*
Magazine.h
Name : JaehyunAhn (Justin)
Student Number : 157826181
Email : jahn31@myseneca.ca
Date : 12/1/2019
Section : NEE
*/

#ifndef SDDS_MAGAZINE_H
#define SDDS_MAGAZINE_H

#include "PubRecord.h"

namespace sdds {

    class Magazine : public PubRecord {

    protected:

        int m_Volumes;
        int m_issues;

	public:
        Magazine();
      Magazine(const Magazine &magazine);
       char recID() const;
        int vol() const;
        int issue() const;
       void checkIn();
       void checkOut();
        istream &read(istream &is);
        ostream &write(ostream &os) const;
       
    };
}

#endif