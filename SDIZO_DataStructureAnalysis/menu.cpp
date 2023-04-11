// menu.cpp : Defines the entry point for the console application.
//

#include <conio.h>
#include <string>
#include <iostream>
#include "AutoTest.h"
#include "Table.h"
#include "List.h"
#include "Heap.h"

using namespace std;

/*
//przyk³adowa implementacja tablicy ale tylko jest TYLKO szkielet 

//normalnie ka¿da klasa powinna zawieraæ definicjê w pliku .h a implementacje metod w pliku .cpp


//staramy siê unikaæ u¿ywania funkcji we/wy w klasie (opócz metody  display)
//ta definicja klast Table powinna normalnie znajdowac siê w pliku .h np. table.h
class Table
{
	int *tab;
	int cnt; //iloœæ elementów w tablicy
public:
	
	Table(); //konstruktor - wywo³ywany automatycznie przy tworzeniu obieku
	~Table(); //destrukor - wyw³ywany automatycznie przy usuwaniu obiektu

	int loadFromFile(string fileName);
	
	bool IsValueInTable(int val);
	
	void addValue(int index, int value);

	void deleteFromTable(int index);

	void display();

	void generateTable(int size);

};

//ta implementacja poni¿ej powinna znajdowaæ siê w pliku cpp np. table.cpp
Table::Table()
{
}

Table::~Table()
{
}

int Table::loadFromFile(string fileName)
{
	return 0;
}

bool Table::IsValueInTable(int val)
{
	return false;
}

void Table::addValue(int index, int value)
{
}

void Table::deleteFromTable(int index)
{
}

void Table::display()
{
}

void Table::generateTable(int size)
{
}

*/




//w³aœciwy program

void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void testMenu() {
	
	cout << endl;
	cout << "---------MENU TESTÓW---------" << endl;
	cout << "1. dodawanie na pocz¹tku		>>tablica/lista<<" << endl;
	cout << "2. dodawanie na koñcu			>>tablica/lista<<" << endl;
	cout << "3. dodawanie w losowym miejscu >>tablica/lista<<" << endl;
	cout << "4. usuwanie z pocz¹tku			>>tablica/lista/kopiec<<" << endl;
	cout << "5. usuwanie z koñca			>>tablica/lista<<" << endl;
	cout << "6. usuwanie z losowego miejsca >>tablica/lista<<" << endl;
	cout << "7. wyszukiwanie				>>tablica/lista/kopiec" << endl;
	cout << "8. dodawanie					>>kopiec<<" << endl;
	cout << "Podaj opcje:";


}

//Table myTab; //myTab mo¿e byæ dynamiczna, mo¿e byc takze zadeklarowana w manu_table albo tutaj jako zmienna globalna 

void menu_table()
{
	Table table;
	char opt;
	string fileName;
	int index, value;

	

	do{
		displayMenu("--- TABLICA ---");
		opt = _getche();
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			table.loadFromFile(fileName);
			table.display();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			cout << " podaj index:";
			cin >> index;
			table.deleteFromTable(index);
			table.display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj waertoœæ:";
			cin >> value;
			table.addValue(index,value);
			table.display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (table.isValueInTable(value))
				cout << "poadana wartosc jest w tablicy";
			else
				cout << "poadanej wartosci NIE ma w tablicy";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementów tablicy:";
			cin >> value;
			table.generateTable(value);
			table.display();
			break;

		case '6':  //tutaj wyœwietlanie tablicy
			table.display();
			break;

		case 's': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie danych) - nie bêdzie testowana przez prowadz¹cego 
			      // mo¿na sobie tu dodaæ w³asne dodatkowe case'y

			AutoTest autoTest;
			autoTest.tableTest();

			break;
		}

	} while (opt != '0');
}

void menu_list()
{
	//analogicznie jak menu_table()Table table;
	List list;
	char opt;
	string fileName;
	int index, value;



	do {
		displayMenu("--- LISTA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie listy z pliku
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			list.loadFromFile(fileName);
			list.display();
			break;

		case '2': //tutaj usuwanie elemenu z listy
			cout << " podaj wartosc:";
			cin >> value;
			list.deleteFromList(value);
			list.display();
			break;

		case '3': //tutaj dodawanie elemetu do listy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj wartosc:";
			cin >> value;
			list.addValue(index, value);
			list.display();
			break;

		case '4': //tutaj znajdowanie elemetu w liscie
			cout << " podaj wartosc:";
			cin >> value;
			if (list.isValueInList(value))
				cout << "poadana wartosc jest w liscie";
			else
				cout << "podanej wartosci NIE ma w liscie";
			break;

		case '5':  //tutaj generowanie  listy
			cout << "Podaj ilosc elementow tablicy:";
			cin >> value;
			list.generateList(value);
			list.display();
			break;

		case '6':  //tutaj wyœwietlanie listy
			list.display();
			break;

		case 's': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
			// mo¿na sobie tu dodaæ w³asne dodatkowe case'y

			break;
		}

	} while (opt != '0');
}

void menu_heap()
{
	Heap heap;
	char opt;
	string fileName;
	int index, value;



	do {
		displayMenu("--- KOPIEC BINARNY ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie kopca z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			heap.loadFromFile(fileName);
			heap.display();
			break;

		case '2': //tutaj usuwanie elemenu z kopca
			cout << " podaj index:";
			cin >> index;
			heap.deleteFromHeap(index);
			heap.display();
			break;

		case '3': //tutaj dodawanie elemetu do kopca
			cout << " podaj wartoœæ:";
			cin >> value;
			heap.addValue(value);
			heap.display();
			break;

		case '4': //tutaj znajdowanie elemetu w kopcu
			cout << " podaj wartosc:";
			cin >> value;
			if (heap.isValueInHeap(value))
				cout << "poadana wartosc jest w kopcu";
			else
				cout << "poadanej wartosci NIE ma w kopcu";
			break;

		case '5':  //tutaj generowanie  kopcu
			cout << "Podaj ilosc elementów kopca:";
			cin >> value;
			heap.generateHeap(value);
			heap.display();
			break;

		case '6':  //tutaj wyœwietlanie kopca
			heap.display();
			break;

		case 's': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
			// mo¿na sobie tu dodaæ w³asne dodatkowe case'y

			AutoTest autoTest();

			break;
		}

	} while (opt != '0');
}

int main(int argc, char* argv[])
{

	char option;
	do{
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";		
		option = _getche();
		cout << endl;

		switch (option){
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;
		}


	} while (option != '0');
	

	return 0;
}

