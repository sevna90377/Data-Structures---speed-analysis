#include "Heap.h"
#include <iostream>


using namespace std;

Heap::Heap() {

	Heap::rootPointer = nullptr;
	Heap::heap_length = 0;

}

Heap::~Heap() {
      
	if (Heap::heap_length > 0) {
		delete[]rootPointer;
	}

}

//metody zwracaj�ce index ojca, lewego lub prawego syna elementu
//zwracaj� warto�� ujemn�, je�li szukane elementy nie istniej� w kopcu
int Heap::parent(int i) { if (rootPointer == nullptr || i == 0) return -1; return (int) floor((i - 1) / 2); }
int Heap::left(int i) { if (2 * i + 2 > heap_length) return -1; return 2 * i + 1; }
int Heap::right(int i) { if (2 * i + 2 > heap_length) return -1;  return 2 * i + 2; }

//metoda naprawia w�asno�� w kierunku korzenia po linii od wybranej pozycji
void Heap::heapifyUp(int i) {
    int l = left(i);
    int r = right(i);
    int largest;

    //sprawdzani s� potomkowie danego w�z�a, st�d warunek, �e w�ze� nie jest li�ciem
    if (l >= 0 && r >= 0) {

        //sprawdzenie czy lewy potomek jest wi�kszy od swojego ojca
        if (rootPointer[l] > rootPointer[i]) {
            largest = l;
        }
        else {
            largest = i;
        }
        //sprawdzenie czy prawy potomek jest wi�kszy od swojego ojca
        if (right(i) <= heap_length && rootPointer[right(i)] > rootPointer[largest]) {
            largest = right(i);
        }

        //zamiana warto�ci miejscami
        if (largest != i) {
            int holder;

            holder = rootPointer[i];
            rootPointer[i] = rootPointer[largest];
            rootPointer[largest] = holder;

        }            
    }

    //metoda zostaje wywo�ana rekurencyjnie w kierunku korzenia, je�li element 'i' nie by� nim
    if(i>0){ heapifyUp(parent(i)); }

}
//metoda naprawia w�asno�� kopca dla wybranego elementu 'i' (sprowadza go w d� na odpowiednie miejsce)
void Heap::heapifyDown(int i) {
    if (heap_length > 1) {
        int largest;

        //sprawdzenie czy lewy potomek jest wi�kszy od swojego ojca
        if (left(i) <= heap_length && rootPointer[left(i)] > rootPointer[i]) {
            largest = left(i);
        }
        else {
            largest = i;
        }

        if (heap_length > 2) {
            //sprawdzenie czy prawy potomek jest wi�kszy od swojego ojca
            if (right(i) <= heap_length && rootPointer[right(i)] > rootPointer[largest]) {
                largest = right(i);
            }
        }

        //zamiana warto�ci miejscami
        if (largest != i) {
            int holder;

            holder = rootPointer[i];
            rootPointer[i] = rootPointer[largest];
            rootPointer[largest] = holder;

            //metoda zostaje wywo�ana rekurencyjnie, gdy� zamiana pozycji mog�a spowodowa� 
            //zaburzenie w�asno�ci kopca w danym poddrzewie
            heapifyDown(largest);
        }
    }
}
//metoda naprawia w�asno�� ca�ego kopca
void Heap::heapifyAll() {
    for (int i = heap_length - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}


int Heap::extractMax() {

    //przechowanie zwracanej warto�ci
    int value = rootPointer[0];

    //przeniesienie ostatniego elementu w miejsce korzenia i zmniejszenie cz�ci tablicy rozpatrywanej jako kopiec
    rootPointer[0] = rootPointer[heap_length - 1];
    heap_length--;

    //przywr�cenie w�asno�ci kopca
    heapifyDown(0);
    
    return value;
}

void Heap::deleteFromHeap(int index) {

    if(index < heap_length && index >= 0){

        //warto�� na pozycji w tablicy o wybranym indeksie zostaje zmieniona na wi�ksz� od korzenia, 
        //aby po przywr�ceniu w�asno�ci kopca metoda 'extractMax()' wyodr�bni�a ten element 
        rootPointer[index] = rootPointer[0] + 1;
        heapifyUp(index);
        extractMax();
    }
    else {
        cout << "Wybrano index poza kopcem!" << endl << "Korze� kopca: 0" << endl << "Ostatni element: " << heap_length << endl;
    }
}

void Heap::addValue(int i) {

    //alokacja pami�ci przy pustym kopcu
    if (rootPointer == nullptr) {
        rootPointer = new int[50];
    }

    //dodanie warto�ci na koniec tablicy

    rootPointer[heap_length] = i;

    //przywr�cenie w�asno�ci kopca zaczynaj�c od ojca dodanego elementu
    //postinkrementacja d�ugo�ci kopca
    heapifyUp(parent(heap_length++));

}

bool Heap::isValueInHeap(int value) {
    for (int i = 0; i < heap_length; i++) {
        if (value == rootPointer[i]) {
            return true;
        }
    }
    return false;
}

void Heap::loadFromFile(string filename) {

}

void Heap::generateHeap(int length) {
    deleteAll();

    heap_length = length;

    rootPointer = new int[heap_length+30];

    srand((unsigned int) time(0));


    for (int i = 0; i < heap_length; i++) {
        rootPointer[i] = rand();
    }

    heapifyAll();
}

//metoda wypisuj�ca drzewo zosta�a zapo�yczona ze strony https://eduinf.waw.pl/inf/alg/001_search/0113.php
void Heap::display() {

    if (rootPointer != nullptr) {
        display("", "", 0);

        cout << endl;

        for (int i = 0; i < heap_length; i++) {
            cout << rootPointer[i] << ", ";
        }
    }
    else {
        cout << "Kopiec jest pusty." << endl;
    }
}
// Tworzenie kopca w tablicy
// Data: 27.02.2013
// (C)2013 mgr Jerzy Wa�aszek
//------------------------------
// Procedura wypisuje drzewo
//--------------------------
//
void Heap::display(string sp, string sn, int from)
{
        string cr, cl, cp;
        cr = cl = cp = "  ";
        cr[0] = 218; cr[1] = 196;
        cl[0] = 192; cl[1] = 196;
        cp[0] = 179;
        string s;

        if (from < heap_length)
        {
            s = sp;
            if (sn == cr) s[s.length() - 2] = ' ';
            display(s + cp, cr, 2 * from + 2);

            s = s.substr(0, sp.length() - 2);

            cout << s << sn << rootPointer[from] << endl;

            s = sp;
            if (sn == cl) s[s.length() - 2] = ' ';
            display(s + cp, cl, 2 * from + 1);
        }
}

void Heap::deleteAll() {



}

