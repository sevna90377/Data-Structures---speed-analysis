#include "List.h"
#include <iostream>
#include <fstream>

using namespace std;

List::List() {

	List::headPointer = nullptr;
	List::tailPointer = nullptr;
	List::list_length = 0;

}

List::~List() {

	{
		ListElement* holder = nullptr;

		for (int i = 0; i < list_length; i++) {
			holder = headPointer->next;
			delete headPointer;
			headPointer = holder;
		}
	}

}

void List::deleteFromList(int value) {

	if (headPointer != nullptr) {

		ListElement* holder;

		if (headPointer->value == value) {

			if (list_length == 1) {

				delete headPointer;

				headPointer = nullptr;
				tailPointer = nullptr;
				list_length--;
			}else{
			holder = headPointer->next;
			
			delete headPointer;

			headPointer = holder;
			headPointer->previous = nullptr;
			list_length--;
			}
		}
		else if (tailPointer->value == value) {
			holder = tailPointer->previous;

			delete tailPointer;

			tailPointer = holder;
			tailPointer->next = nullptr;
			list_length--;
		}
		else {
			holder = headPointer->next;
			for (int i = 1; i < list_length - 1; i++) {
				if (holder->value == value) {
					holder->previous->next = holder->next;
					holder->next->previous = holder->previous;
					
					delete holder;
					list_length--;
					break;
				}
				holder = holder->next;
			}
		}
	}
	else {
		cout << "Lista nie zawiera zadnego elementu." << endl;
	}
}

void List::addValue(int index, int value) {

	if (index < 0 || index > list_length) {
		cout << "Wybrane miejsce znajduje sie poza list�!" << endl;
		cout << "Poczatek listy: 0" << endl << "Koniec listy: " << list_length << endl;
		return;
	}

	if (index == list_length) {	//dodawanie na koniec

		if (headPointer == nullptr) {	//gdy lista jest pusta
			tailPointer = new ListElement;
			tailPointer->next = nullptr;
			tailPointer->previous = nullptr;
			tailPointer->value = value;
			headPointer = tailPointer;
		}
		else{
			//Utworzenie wska�nika, kt�ry przechowa pozycj� poprzedniego elementu
			// po przypisaniu nowego elementu do wska�nika na ogon listy
			ListElement* lastElement = tailPointer;

			//Przypisanie do wska�nika na g�ow� nowego elementu i uzupe�nienie jego p�l
			tailPointer = new ListElement;
			tailPointer->value = value;
			tailPointer->next = nullptr;
			tailPointer->previous = lastElement;

			//Przypisanie ostatniemu elementowi wska�nika na nowy element
			lastElement->next = tailPointer;
		}
	}
	else if(index == 0){	//dodawanie na pocz�tek
		//Sytuacja, gdy lista jest pusta zostanie wy�apana w poprzednim warunku

		//Utworzenie wska�nika, kt�ry przechowa pozycj� nast�pnego elementu
		// po przypisaniu nowego elementu do wska�nika na g�ow� listy
		ListElement* firstElement = headPointer;
		
		//Przypisanie do wska�nika na g�ow� nowego elementu i uzupe�nienie jego p�l
		headPointer = new ListElement;
		headPointer->value = value;
		headPointer->next = firstElement;
		headPointer->previous = nullptr;

		//Przypisanie pierwszemu elementowi wska�nika na nowy element
		firstElement->previous = headPointer;
	}
	else {	//dodawanie w innym miejscu

		//Utworzenie pomocniczego wska�nika
		ListElement* holder;

		//Sprawdzenie w kt�rej po�owie listy znajduje si� szukany index,
		// od czego zale�e� b�dzie kierunek przeszukiwania
		if (list_length / 2 > index) {

			//Odnalezienie odpowiedniego elementu zaczynaj�c od g�owy
			holder = headPointer;
			for (int i = 0; i < index; i++) {
				holder = holder->next;
			}
		}
		else {

			//Odnalezienie odpowiedniego elementu zaczynaj�c od ogona
			holder = tailPointer;
			for (int i = list_length - 1; i > index; i--) {
				holder = holder->previous;
			}
		}

		//Utworzenie nowego elementu
		ListElement *newElement = new ListElement;
		newElement->value = value;
		newElement->next = holder;
		newElement->previous = holder->previous;


		//Przypisanie odpowienim wska�nikom pozycji nowego elementu
		holder->previous->next = newElement;
		holder->previous = newElement;
	}

	list_length++;
}

bool List::isValueInList(int value) {
	if (list_length == 0)
		return false;

	ListElement* holder = headPointer;

	for (int i = 0; i < list_length; i++) {
		if (holder->value == value)
			return true;
		holder = holder->next;
	}
	return false;
}

void List::loadFromFile(string fileName) {
	ifstream myFile;
	int amount, value;

	myFile.open(fileName);

	if (myFile.is_open())
	{
		deleteAll();

		myFile >> amount;

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

void List::generateList(int list_length) {
	deleteAll();

	srand(time(0));
	for (int i = 0; i < list_length; i++) {
		addValue(i, rand());
	}
}

void List::display() {

	if (headPointer != nullptr) {

		//Utworzenie wska�nika na aktualnie wy�wietlany element potrzebnego do iteracji
		// i przypisanie mu pocz�tku listy
		ListElement* holder = headPointer;

		for (int i = 0; i < list_length; i++){
			cout << holder->value << " ";
			holder = holder->next;
		}

		cout << endl;

		holder = tailPointer;

		for (int i = list_length; i > 0; i--) {
			cout << holder->value << " ";
			holder = holder->previous;
		}
	}
	else {
		cout << "Lista nie ma zadnych elementow." << endl;
	}
	
}

void List::deleteAll() {

	if(headPointer != nullptr){

		//Usuni�cie element�w z tablicy
		// brak inkrementacji zmiennej i ze wzgl�du na dekrementacj� zmiennej list_length przy wywo�aniu deleteFromTable();
		for (int i = 0; i < list_length;) {

			//Utworzenie wska�nika, kt�ry przechowa pozycj� nast�pnego elementu (lub nullptr gdyby nie istnia�)
			// po usuni�ciu elementu z g�owy listy
			ListElement* firstElement = headPointer->next;

			delete headPointer;

			//Rozpatrzenie przypadku, w kt�rym nie istnia� nast�pny element listy
			if (firstElement != nullptr) {
				firstElement->previous = nullptr;
				headPointer = firstElement;
			}
			else {
				headPointer = nullptr;
				tailPointer = nullptr;
			}

			list_length--;
		}
	}
}