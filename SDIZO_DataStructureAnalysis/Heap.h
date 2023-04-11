#pragma once

#include <string>

class Heap {

public:

	//zmienne

	int* rootPointer;

	int heap_length;

	//metody

	Heap();
	~Heap();

	//metody zwracaj¹ce index ojca, lewego lub prawego syna elementu
	int parent(int i);
	int left(int i);
	int right(int i);

	//metoda naprawia w³asnoœæ w kierunku korzenia po linii od wybranej pozycji, któr¹ przyjmuje jako argument
	void heapifyUp(int i);
	//metoda naprawia w³asnoœæ kopca dla wybranego elementu 'i'
	void heapifyDown(int i);
	//metoda naprawia w³asnoœæ ca³ego kopca
	void heapifyAll();

	//praktyczna metoda zwracaj¹ca wartoœæ korzenia i usuwaj¹ca go
	int extractMax();

	void deleteFromHeap(int index);

	void addValue(int i);

	bool isValueInHeap(int value);

	void loadFromFile(std::string filename);

	void generateHeap(int length);

	void display();
	void display(std::string sp, std::string sn, int value);

	void deleteAll();

};
