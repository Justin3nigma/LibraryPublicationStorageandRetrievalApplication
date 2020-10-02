/*
Book.h
Name : JaehyunAhn (Justin)
Student Number : 157826181
Email : jahn31@myseneca.ca
Date : 12/1/2019
Section : NEE
*/

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "PubRecord.h"
#include "Date.h"

namespace sdds {

    class Book : public PubRecord {

    protected:
        long int ISBN; 
        int Mem_ID;
        Date R_date;

    public:
        Book();
        Book(const Book &book);

        char recID() const;
        int memberID() const;
        long int isbn() const;
        void checkIn();
        void checkOut();

        Date returnDate() const;
        Book &operator=(const Book &b);

        istream &read(istream &is);
        ostream &write(ostream &os) const;

    };
}

#endif