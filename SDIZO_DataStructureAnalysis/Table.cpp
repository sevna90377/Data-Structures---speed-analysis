#include "Table.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>


using namespace std;


Table::Table() {

	Table::headPointer = nullptr;
	Table::table_length = 0;

}

Table::~Table() {

	if (headPointer != nullptr) {
		delete[]headPointer;
	}

}

void Table::deleteFromTable(int index) {
	
	if(table_length > 0 && index >=0 && index < table_length){

		//Alokacja pamiêci na tablicê mniejsz¹ o jeden element
		int* newHeadPointer = new int[table_length - 1];

		//Przepisanie do nowej tablicy wyników z pominiêciem usuwanego elementu
		for (int i = 0; i < index; i++) {
			newHeadPointer[i] = headPointer[i];
		}
		for (int i = index; i < table_length - 1; i++) {
			newHeadPointer[i] = headPointer[i + 1];
		}

		//Zwolnienie pamiêci po poprzedniej tablicy i przypisanie wskaŸnikowi na pierszy element tablicy adresu nowej tablicy
		delete headPointer;
		headPointer = newHeadPointer;

		//Dekrementacja zmiennej przechowuj¹cej rozmiar tablicy
		table_length--;
	}
	else if (table_length == 0) {
		cout << "Tablica nie zawiera ¿adnych elementów!" << endl;
	}
	else {
		cout << "Na podanym miejscu nie ma ¿adnego elementu!" << endl;
		cout << "Pocz¹tek tablicy: 0" << endl << "Koniec tablicy: " << table_length - 1 << endl;
	}
}

void Table::addValue(int index, int value) {

	if(index >= 0 && index <= table_length){
		//Alokacja pamiêci na tablicê wiêksz¹ o jeden element
		int* newHeadPointer = new int[table_length + 1];

		//Przepisanie wartoœci do nowej tablicy wraz z dodawanym elementem
		for (int i = 0; i < index; i++) {
			newHeadPointer[i] = headPointer[i];
		}
		newHeadPointer[index] = value;
		for (int i = index; i < table_length; i++) {
			newHeadPointer[i + 1] = headPointer[i];
		}

		//Zwolnienie pamiêci po poprzedniej tablicy
		// i przypisanie nowego adresu wskaŸnikowi na pierwszy element tablicy
		delete headPointer;
		headPointer = newHeadPointer;

		//Inkrementacja zmiennej przechowuj¹cej rozmiar tablicy
		table_length++;
	}
	else {
		cout << "Wybrane miejsce znajduje siê poza tablic¹!" << endl;
		cout << "Pocz¹tek tablicy: 0" << endl << "Koniec tablicy: " << table_length << endl;
	}
}

bool Table::isValueInTable(int value) {
	for (int i = 0; i < table_length; i++)
		if (headPointer[i] == value)
			return true;
	return false;
}

void Table::loadFromFile(string filename) {
	ifstream myFile;
	int amount, value;

	myFile.open(filename);

	if (myFile.is_open())
	{
		//usuniêcie ewentualnych wartoœci ju¿ obecnych w tablicy
		deleteAll();

		//pobranie iloœci wartoœci do odczytania z pierwszej linijki pliku
		myFile >> amount;

		//dodanie do tablicy wszystkich wartoœci
		for (int i = 0; i < amount; i++) {
			myFile >> value;
			addValue(i, value);
		}

		myFile.close();
	}
	else {
		cout << "Nie uda³o siê otworzyæ pliku" << endl;
	}

}

void Table::generateTable(int table_length) {

	//usuniêcie obecnej tablicy
	deleteAll();
	delete headPointer;

	//alokacja pamiêci
	headPointer = new int[table_length];
	this->table_length = table_length;

	//pobranie ziarna dla generatora 
	srand((unsigned int)time(0));

	//zape³nienie tablicy losowymi wartoœciami (nieokreœlony przedzia³)
	for (int i = 0; i < table_length; i++) {
		headPointer[i] = rand();
	}
}

void Table::display() {

	//sprawdzenie, czy tablica posiada wartoœci do wyœwietlenia
	if (headPointer != nullptr) {
		for (int i = 0; i < table_length; i++) {
			cout << headPointer[i] << " ";
		}
	}
	else {
		cout << "Tablica nie ma zadnych elementow." << endl;
	}

}

void Table::deleteAll() {

	//Usuniêcie elementów z tablicy
	while (table_length > 0) {
		deleteFromTable(0);
	}
}
