
#ifndef SDDS_PUBRECORD_H
#define SDDS_PUBRECORD_H

#include "ReadWriteable.h"
#include "Utils.h"

namespace sdds {

	const int SDDS_CONSOLE = 0;
	const int SDDS_FILE = 1;

	class PubRecord : public ReadWriteable {

	protected:
		char* PR_name;
		int Shelf_num;
		int M_type;

		void name(const char* new_name);
		const char* name() const;

	public:
		PubRecord();
		PubRecord(const PubRecord& pr);
		virtual ~PubRecord();

		void mediaType(int m_type);
		int mediaType() const;
		int shelfNo() const;
		void readShelfNo();

		void shelfNo(int num);
		virtual void checkIn() = 0;
		virtual void checkOut() = 0;

		virtual char recID() const;

		PubRecord& operator=(const PubRecord& pr);

		bool operator==(char g) const;
		bool operator==(const char* cc) const;
		operator bool() const;


	};
}

#endif