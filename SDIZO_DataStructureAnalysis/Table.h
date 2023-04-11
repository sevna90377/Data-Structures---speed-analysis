#pragma once

#include <string>

class Table {

public:

	//zmienne

	int* headPointer;

	int table_length;

	//metody

	Table();
	~Table();

	void deleteFromTable(int index);

	void addValue(int index, int value);

	bool isValueInTable(int value);

	void loadFromFile(std::string fileName);

	void generateTable(int table_length);

	void display();

	void deleteAll();

};