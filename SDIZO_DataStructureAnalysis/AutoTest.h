#pragma once

#include <string>
#include <fstream>

class AutoTest {

public:

	std::string resultFileName;
	std::string numberFileName;
	int amount;


	//metody


/*
*	---------MENU TEST�W---------
*	 1. dodawanie na pocz�tku			>>tablica/lista<<
*	 2. dodawanie na ko�cu				>>tablica/lista<<
*	 3. dodawanie w losowym miejscu		>>tablica/lista<<
*	 4. usuwanie z pocz�tku				>>tablica/lista/kopiec<<
*	 5. usuwanie z ko�ca				>>tablica/lista<<
*	 6. usuwanie z losowego miejsca		>>tablica/lista<<
*	 7. wyszukiwanie					>>tablica/lista/kopiec
*	 8. dodawanie						>>kopiec<<
*  
*/
	void tableTest();
	void listTest();
	void heapTest();

	void randomIntFile(int amount);
};