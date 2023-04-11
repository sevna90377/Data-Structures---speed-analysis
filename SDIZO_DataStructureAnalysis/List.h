#pragma once

#include <string>

struct ListElement {
	int value;
	ListElement* next;
	ListElement* previous;
};

class List {

public:

	//zmienne

	ListElement* headPointer;
	ListElement* tailPointer;

	int list_length;

	//metody

	List();
	~List();

	void deleteFromList(int value);

	void addValue(int index, int value);

	bool isValueInList(int value);

	void loadFromFile(std::string fileName);

	void generateList(int list_length);

	void display();

	void deleteAll();

};