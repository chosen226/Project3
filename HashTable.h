#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "dataNode.h"
using namespace std;

class HashTable {
	vector<vector<dataNode>> table;
	//IDs should be in the form ccdddd, where cc is a 2 digit country ID and dddd is a 4 digit date ID
public:
	//Change placeholder for whatever dataNode needs
	void insert(int ID, double placeholder);
	dataNode search(int ID);
	int searchVal(double val);
};



#include "HashTable.h"
using namespace std;

void HashTable::insert(int ID, double placeholder) {
	dataNode toInsert(placeholder);
	unsigned int countryID = ID / 10000;
	unsigned int dateID = ID % 10000;
	if (table.size() <= countryID) {
		table.resize(countryID + 1);
	}
	if (table[countryID].size() <= dateID) {
		table[countryID].resize(dateID + 1);
	}
	table[countryID][dateID] = toInsert;
}

dataNode HashTable::search(int ID) {
	int countryID = ID / 10000;
	int dateID = ID % 10000;
	if (countryID >= table.size() || dateID >= table[countryID].size()) {
		dataNode empty;
		return empty;
	}
	return table[countryID][dateID];
}

int HashTable::searchVal(double val) {
	int len = table[0].size();
	for (int i = 0; i < len; i++) {
		//Change access function here
		if (table[0][i].getPlaceholder() >= val) {
			return i;
		}
	}
	return -123456;
}