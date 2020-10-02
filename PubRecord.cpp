#define _CRT_SECURE_NO_WARNINGS
#include "PubRecord.h"

namespace sdds {

	PubRecord::PubRecord() {
		PR_name = nullptr;
		Shelf_num = 0;
		M_type = 0;
	}

	PubRecord::PubRecord(const PubRecord& PR) {
		name(PR.PR_name);
		mediaType(PR.mediaType());
		Shelf_num = PR.shelfNo();
	}

	PubRecord::~PubRecord() {
		delete[] PR_name;
	}

	void PubRecord::name(const char* new_name) {
		if (new_name == nullptr) {
			PR_name = nullptr;
		}
		else {
			PR_name = new char[strlen(new_name) + 1];
			strcpy(PR_name, new_name);
		}
	}

	const char* PubRecord::name() const {
		return PR_name;
	}

	int PubRecord::shelfNo() const {
		return Shelf_num;
	}

	void PubRecord::shelfNo(int Num) {
		Shelf_num = Num;
	}

	int PubRecord::mediaType() const {
		return M_type;
	}

	void PubRecord::mediaType(int Media_type) {
		M_type = Media_type;
	}

	void PubRecord::readShelfNo() {
		::read(Shelf_num, 100, 999, "Invalid Shelf Number, Enter again: ");
	}

	char PubRecord::recID()const {
		return 'c';
	}

	PubRecord& PubRecord::operator=(const PubRecord& PR) {
		name(PR.PR_name);
		Shelf_num = PR.Shelf_num;
		M_type = PR.M_type;
		return *this;
	}

	bool PubRecord::operator==(char c) const {
		return (c == recID());
	}

	bool PubRecord::operator==(const char* cc) const {
		bool isSubstr = false;
		if (strstr(PR_name, cc) != nullptr) {
			isSubstr = true;
		}
		return isSubstr;
	}

	PubRecord::operator bool() const {
		return (PR_name != nullptr);
	}
}