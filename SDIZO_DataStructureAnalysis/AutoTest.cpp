#include "AutoTest.h"
#include "Table.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <chrono>
#include "Timer.h"

using namespace std;

void AutoTest::randomIntFile(int amount)
{

	numberFileName = "randomint/" + to_string(amount) + ".txt";

	fstream myFile;
	myFile.open(numberFileName, ios::out);

	srand((unsigned int)time(0));

	if (myFile.is_open()) {

		myFile << amount << endl;

		for (int i = 0; i < amount; i++) {
			myFile << rand() << endl;
		}

		cout << "Pomyœlnie wygenerowano plik :)" << endl;
	}
	else {
		cout << "Nie uda³o siê utworzyæ pliku :(" << endl;
	}

	myFile.close();
}


void AutoTest::tableTest()
{
	Table table;
	Timer timer;

	ofstream resultFile;
	fstream numberFile;

	resultFileName = "results/Testy_tablicy.csv";

	resultFile.open(resultFileName);

	if (resultFile.is_open()) {
		
		{	cout << "Rozpoczynam test dodawania 100 do 5000 na pocz¹tek tablicy..." << endl;

			resultFile << "dodawanie 100 do 5000 na pocz¹tek tablicy" << "\n";
			resultFile << "nr testu" << ";";
			for (int i = 0; i < 100;) {
				resultFile << ++i << ";";
			}
			resultFile << "\n";

			long summary_time = 0;
			
			for(int i = 0; i < 100; i ++){
				resultFile << ";";
				table.generateTable(5000);
				randomIntFile(100);
				numberFile.open(numberFileName, ios::in);

				if (numberFile.is_open()) {
					int value;
					numberFile >> value;

					for (int k = 0; k < 100; k++) {
						numberFile >> value;
						timer.startTimer();
						table.addValue(0, value);
						timer.stopTimer();
						summary_time += timer.result();
					}
					resultFile << summary_time;
					numberFile.close();
				}
			}
			resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 10 000 na pocz¹tek tablicy..." << endl;

			resultFile << "dodawanie 100 do 10 000 na pocz¹tek tablicy" << "\n";
			resultFile << "nr testu" << ";";
			for (int i = 0; i < 100;) {
				resultFile << ++i << ";";
			}
			resultFile << "\n";

			long summary_time = 0;

			for (int i = 0; i < 100; i++) {
				resultFile << ";";
				table.generateTable(10000);
				randomIntFile(100);
				numberFile.open(numberFileName, ios::in);

				if (numberFile.is_open()) {
					int value;
					numberFile >> value;

					for (int k = 0; k < 100; k++) {
						numberFile >> value;
						timer.startTimer();
						table.addValue(0, value);
						timer.stopTimer();
						summary_time += timer.result();
					}
					resultFile << summary_time;
					numberFile.close();
				}
			}
			resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 15 000 na pocz¹tek tablicy..." << endl;

			resultFile << "dodawanie 100 do 15 000 na pocz¹tek tablicy" << "\n";
			resultFile << "nr testu" << ";";
			for (int i = 0; i < 100;) {
				resultFile << ++i << ";";
			}
			resultFile << "\n";

			long summary_time = 0;

			for (int i = 0; i < 100; i++) {
				resultFile << ";";
				table.generateTable(15000);
				randomIntFile(100);
				numberFile.open(numberFileName, ios::in);

				if (numberFile.is_open()) {
					int value;
					numberFile >> value;

					for (int k = 0; k < 100; k++) {
						numberFile >> value;
						timer.startTimer();
						table.addValue(0, value);
						timer.stopTimer();
						summary_time += timer.result();
					}
					resultFile << summary_time;
					numberFile.close();
				}
			}
			resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 20 000 na pocz¹tek tablicy..." << endl;

			resultFile << "dodawanie 100 do 20 000 na pocz¹tek tablicy" << "\n";
			resultFile << "nr testu" << ";";
			for (int i = 0; i < 100;) {
				resultFile << ++i << ";";
			}
			resultFile << "\n";

			long summary_time = 0;

			for (int i = 0; i < 100; i++) {
				resultFile << ";";
				table.generateTable(20000);
				randomIntFile(100);
				numberFile.open(numberFileName, ios::in);

				if (numberFile.is_open()) {
					int value;
					numberFile >> value;

					for (int k = 0; k < 100; k++) {
						numberFile >> value;
						timer.startTimer();
						table.addValue(0, value);
						timer.stopTimer();
						summary_time += timer.result();
					}
					resultFile << summary_time;
					numberFile.close();
				}
			}
			resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 30 000 na pocz¹tek tablicy..." << endl;

			resultFile << "dodawanie 100 do 30 000 na pocz¹tek tablicy" << "\n";
			resultFile << "nr testu" << ";";
			for (int i = 0; i < 100;) {
				resultFile << ++i << ";";
			}
			resultFile << "\n";

			long summary_time = 0;

			for (int i = 0; i < 100; i++) {
				resultFile << ";";
				table.generateTable(30000);
				randomIntFile(100);
				numberFile.open(numberFileName, ios::in);

				if (numberFile.is_open()) {
					int value;
					numberFile >> value;

					for (int k = 0; k < 100; k++) {
						numberFile >> value;
						timer.startTimer();
						table.addValue(0, value);
						timer.stopTimer();
						summary_time += timer.result();
					}
					resultFile << summary_time;
					numberFile.close();
				}
			}
			resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 40 000 na pocz¹tek tablicy..." << endl;

			resultFile << "dodawanie 100 do 40 000 na pocz¹tek tablicy" << "\n";
			resultFile << "nr testu" << ";";
			for (int i = 0; i < 100;) {
				resultFile << ++i << ";";
			}
			resultFile << "\n";

			long summary_time = 0;

			for (int i = 0; i < 100; i++) {
				resultFile << ";";
				table.generateTable(40000);
				randomIntFile(100);
				numberFile.open(numberFileName, ios::in);

				if (numberFile.is_open()) {
					int value;
					numberFile >> value;

					for (int k = 0; k < 100; k++) {
						numberFile >> value;
						timer.startTimer();
						table.addValue(0, value);
						timer.stopTimer();
						summary_time += timer.result();
					}
					resultFile << summary_time;
					numberFile.close();
				}
			}
			resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 50 000 na pocz¹tek tablicy..." << endl;

			resultFile << "dodawanie 100 do 50 000 na pocz¹tek tablicy" << "\n";
			resultFile << "nr testu" << ";";
			for (int i = 0; i < 100;) {
				resultFile << ++i << ";";
			}
			resultFile << "\n";

			long summary_time = 0;

			for (int i = 0; i < 100; i++) {
				resultFile << ";";
				table.generateTable(50000);
				randomIntFile(100);
				numberFile.open(numberFileName, ios::in);

				if (numberFile.is_open()) {
					int value;
					numberFile >> value;

					for (int k = 0; k < 100; k++) {
						numberFile >> value;
						timer.startTimer();
						table.addValue(0, value);
						timer.stopTimer();
						summary_time += timer.result();
					}
					resultFile << summary_time;
					numberFile.close();
				}
			}
			resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 100 000 na pocz¹tek tablicy..." << endl;

			resultFile << "dodawanie 100 do 100 000 na pocz¹tek tablicy" << "\n";
			resultFile << "nr testu" << ";";
			for (int i = 0; i < 100;) {
				resultFile << ++i << ";";
			}
			resultFile << "\n";

			long summary_time = 0;

			for (int i = 0; i < 100; i++) {
				resultFile << ";";
				table.generateTable(100000);
				randomIntFile(100);
				numberFile.open(numberFileName, ios::in);

				if (numberFile.is_open()) {
					int value;
					numberFile >> value;

					for (int k = 0; k < 100; k++) {
						numberFile >> value;
						timer.startTimer();
						table.addValue(0, value);
						timer.stopTimer();
						summary_time += timer.result();
					}
					resultFile << summary_time;
					numberFile.close();
				}
			}
			resultFile << "\n";
		}

		////////////////////////////////////////////////////////////////////////////////


		{	cout << "Rozpoczynam test dodawania 100 do 5000 na koniec tablicy..." << endl;

		resultFile << "dodawanie 100 do 5000 na koniec tablicy" << "\n";
		resultFile << "nr testu" << ";";
		for (int i = 0; i < 100;) {
			resultFile << ++i << ";";
		}
		resultFile << "\n";

		long summary_time = 0;

		for (int i = 0; i < 100; i++) {
			resultFile << ";";
			table.generateTable(5000);
			randomIntFile(100);
			numberFile.open(numberFileName, ios::in);

			if (numberFile.is_open()) {
				int value;
				numberFile >> value;

				for (int k = 0; k < 100; k++) {
					numberFile >> value;
					timer.startTimer();
					table.addValue(table.table_length, value);
					timer.stopTimer();
					summary_time += timer.result();
				}
				resultFile << summary_time;
				numberFile.close();
			}
		}
		resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 10 000 na koniec tablicy..." << endl;

		resultFile << "dodawanie 100 do 10 000 na koniec tablicy" << "\n";
		resultFile << "nr testu" << ";";
		for (int i = 0; i < 100;) {
			resultFile << ++i << ";";
		}
		resultFile << "\n";

		long summary_time = 0;

		for (int i = 0; i < 100; i++) {
			resultFile << ";";
			table.generateTable(10000);
			randomIntFile(100);
			numberFile.open(numberFileName, ios::in);

			if (numberFile.is_open()) {
				int value;
				numberFile >> value;

				for (int k = 0; k < 100; k++) {
					numberFile >> value;
					timer.startTimer();
					table.addValue(table.table_length, value);
					timer.stopTimer();
					summary_time += timer.result();
				}
				resultFile << summary_time;
				numberFile.close();
			}
		}
		resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 15 000 na koniec tablicy..." << endl;

		resultFile << "dodawanie 100 do 15 000 na koniec tablicy" << "\n";
		resultFile << "nr testu" << ";";
		for (int i = 0; i < 100;) {
			resultFile << ++i << ";";
		}
		resultFile << "\n";

		long summary_time = 0;

		for (int i = 0; i < 100; i++) {
			resultFile << ";";
			table.generateTable(15000);
			randomIntFile(100);
			numberFile.open(numberFileName, ios::in);

			if (numberFile.is_open()) {
				int value;
				numberFile >> value;

				for (int k = 0; k < 100; k++) {
					numberFile >> value;
					timer.startTimer();
					table.addValue(table.table_length, value);
					timer.stopTimer();
					summary_time += timer.result();
				}
				resultFile << summary_time;
				numberFile.close();
			}
		}
		resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 20 000 na koniec tablicy..." << endl;

		resultFile << "dodawanie 100 do 20 000 na koniec tablicy" << "\n";
		resultFile << "nr testu" << ";";
		for (int i = 0; i < 100;) {
			resultFile << ++i << ";";
		}
		resultFile << "\n";

		long summary_time = 0;

		for (int i = 0; i < 100; i++) {
			resultFile << ";";
			table.generateTable(20000);
			randomIntFile(100);
			numberFile.open(numberFileName, ios::in);

			if (numberFile.is_open()) {
				int value;
				numberFile >> value;

				for (int k = 0; k < 100; k++) {
					numberFile >> value;
					timer.startTimer();
					table.addValue(table.table_length, value);
					timer.stopTimer();
					summary_time += timer.result();
				}
				resultFile << summary_time;
				numberFile.close();
			}
		}
		resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 30 000 na koniec tablicy..." << endl;

		resultFile << "dodawanie 100 do 30 000 na koniec tablicy" << "\n";
		resultFile << "nr testu" << ";";
		for (int i = 0; i < 100;) {
			resultFile << ++i << ";";
		}
		resultFile << "\n";

		long summary_time = 0;

		for (int i = 0; i < 100; i++) {
			resultFile << ";";
			table.generateTable(30000);
			randomIntFile(100);
			numberFile.open(numberFileName, ios::in);

			if (numberFile.is_open()) {
				int value;
				numberFile >> value;

				for (int k = 0; k < 100; k++) {
					numberFile >> value;
					timer.startTimer();
					table.addValue(table.table_length, value);
					timer.stopTimer();
					summary_time += timer.result();
				}
				resultFile << summary_time;
				numberFile.close();
			}
		}
		resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 40 000 na koniec tablicy..." << endl;

		resultFile << "dodawanie 100 do 40 000 na koniec tablicy" << "\n";
		resultFile << "nr testu" << ";";
		for (int i = 0; i < 100;) {
			resultFile << ++i << ";";
		}
		resultFile << "\n";

		long summary_time = 0;

		for (int i = 0; i < 100; i++) {
			resultFile << ";";
			table.generateTable(40000);
			randomIntFile(100);
			numberFile.open(numberFileName, ios::in);

			if (numberFile.is_open()) {
				int value;
				numberFile >> value;

				for (int k = 0; k < 100; k++) {
					numberFile >> value;
					timer.startTimer();
					table.addValue(table.table_length, value);
					timer.stopTimer();
					summary_time += timer.result();
				}
				resultFile << summary_time;
				numberFile.close();
			}
		}
		resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 50 000 na koniec tablicy..." << endl;

		resultFile << "dodawanie 100 do 50 000 na koniec tablicy" << "\n";
		resultFile << "nr testu" << ";";
		for (int i = 0; i < 100;) {
			resultFile << ++i << ";";
		}
		resultFile << "\n";

		long summary_time = 0;

		for (int i = 0; i < 100; i++) {
			resultFile << ";";
			table.generateTable(50000);
			randomIntFile(100);
			numberFile.open(numberFileName, ios::in);

			if (numberFile.is_open()) {
				int value;
				numberFile >> value;

				for (int k = 0; k < 100; k++) {
					numberFile >> value;
					timer.startTimer();
					table.addValue(table.table_length, value);
					timer.stopTimer();
					summary_time += timer.result();
				}
				resultFile << summary_time;
				numberFile.close();
			}
		}
		resultFile << "\n";
		}

		{	cout << "Rozpoczynam test dodawania 100 do 100 000 na koniec tablicy..." << endl;

		resultFile << "dodawanie 100 do 100 000 na koniec tablicy" << "\n";
		resultFile << "nr testu" << ";";
		for (int i = 0; i < 100;) {
			resultFile << ++i << ";";
		}
		resultFile << "\n";

		long summary_time = 0;

		for (int i = 0; i < 100; i++) {
			resultFile << ";";
			table.generateTable(100000);
			randomIntFile(100);
			numberFile.open(numberFileName, ios::in);

			if (numberFile.is_open()) {
				int value;
				numberFile >> value;

				for (int k = 0; k < 100; k++) {
					numberFile >> value;
					timer.startTimer();
					table.addValue(table.table_length, value);
					timer.stopTimer();
					summary_time += timer.result();
				}
				resultFile << summary_time;
				numberFile.close();
			}
		}
		resultFile << "\n";
		}

			resultFile.close();
	}
}
