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

		//Alokacja pami�ci na tablic� mniejsz� o jeden element
		int* newHeadPointer = new int[table_length - 1];

		//Przepisanie do nowej tablicy wynik�w z pomini�ciem usuwanego elementu
		for (int i = 0; i < index; i++) {
			newHeadPointer[i] = headPointer[i];
		}
		for (int i = index; i < table_length - 1; i++) {
			newHeadPointer[i] = headPointer[i + 1];
		}

		//Zwolnienie pami�ci po poprzedniej tablicy i przypisanie wska�nikowi na pierszy element tablicy adresu nowej tablicy
		delete headPointer;
		headPointer = newHeadPointer;

		//Dekrementacja zmiennej przechowuj�cej rozmiar tablicy
		table_length--;
	}
	else if (table_length == 0) {
		cout << "Tablica nie zawiera �adnych element�w!" << endl;
	}
	else {
		cout << "Na podanym miejscu nie ma �adnego elementu!" << endl;
		cout << "Pocz�tek tablicy: 0" << endl << "Koniec tablicy: " << table_length - 1 << endl;
	}
}

void Table::addValue(int index, int value) {

	if(index >= 0 && index <= table_length){
		//Alokacja pami�ci na tablic� wi�ksz� o jeden element
		int* newHeadPointer = new int[table_length + 1];

		//Przepisanie warto�ci do nowej tablicy wraz z dodawanym elementem
		for (int i = 0; i < index; i++) {
			newHeadPointer[i] = headPointer[i];
		}
		newHeadPointer[index] = value;
		for (int i = index; i < table_length; i++) {
			newHeadPointer[i + 1] = headPointer[i];
		}

		//Zwolnienie pami�ci po poprzedniej tablicy
		// i przypisanie nowego adresu wska�nikowi na pierwszy element tablicy
		delete headPointer;
		headPointer = newHeadPointer;

		//Inkrementacja zmiennej przechowuj�cej rozmiar tablicy
		table_length++;
	}
	else {
		cout << "Wybrane miejsce znajduje si� poza tablic�!" << endl;
		cout << "Pocz�tek tablicy: 0" << endl << "Koniec tablicy: " << table_length << endl;
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
		//usuni�cie ewentualnych warto�ci ju� obecnych w tablicy
		deleteAll();

		//pobranie ilo�ci warto�ci do odczytania z pierwszej linijki pliku
		myFile >> amount;

		//dodanie do tablicy wszystkich warto�ci
		for (int i = 0; i < amount; i++) {
			myFile >> value;
			addValue(i, value);
		}

		myFile.close();
	}
	else {
		cout << "Nie uda�o si� otworzy� pliku" << endl;
	}

}

void Table::generateTable(int table_length) {

	//usuni�cie obecnej tablicy
	deleteAll();
	delete headPointer;

	//alokacja pami�ci
	headPointer = new int[table_length];
	this->table_length = table_length;

	//pobranie ziarna dla generatora 
	srand((unsigned int)time(0));

	//zape�nienie tablicy losowymi warto�ciami (nieokre�lony przedzia�)
	for (int i = 0; i < table_length; i++) {
		headPointer[i] = rand();
	}
}

void Table::display() {

	//sprawdzenie, czy tablica posiada warto�ci do wy�wietlenia
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

	//Usuni�cie element�w z tablicy
	while (table_length > 0) {
		deleteFromTable(0);
	}
}
