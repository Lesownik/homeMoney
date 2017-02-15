#include "Classe.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;


WholeProgramForCalculations::WholeProgramForCalculations(int a, int b, int c) {

	money = a;
	moneyPlus = b;
	moneyMinus = c;

}

WholeProgramForCalculations::~WholeProgramForCalculations() {

	cout << "Destructor works." << endl;
}

int WholeProgramForCalculations::openFile()
{
	//zmienne
	string fileName;
	string data;
	int moneySum;


	cout << "Wpisz nazwe pliku: \n";
	cin >> fileName;
	


	fstream fileRead;
	fileRead.open(fileName, ios::in);

	if (fileRead.good() == false) {

		cout << "Plik nie istnieje!";
		exit(0);
	}

	string line;
	int lineNum = 1;
	while (getline(fileRead, line)) {
		switch (lineNum) {
		case 1: data = line;	break;
		case 2: moneySum = atoi(line.c_str()); break;

		}
		lineNum++;

	}

	fileRead.close();
	fileRead.clear();

	cout << data << endl;
	cout << moneySum << endl;
	money = moneySum;

	menu();
	return money;

}

void WholeProgramForCalculations::saveFile(){
	//zmienne
	string data, nameFile;

	//wczytywanie danych
	cout << "Podaj date: ";				cin >> data;
	cout << "Nazwij plik: ";			cin >> nameFile;
	//inicjalizacja pliku tekstowego
	fstream plik;
	plik.open(nameFile, ios::out | ios::app);

	//wczytywanie do pliku
	plik << data << endl;
	plik << money << endl;

	plik.close();
	plik.clear();
	menu();
}

int WholeProgramForCalculations::addMoney()
{
	int x;
	cout << "Ile pieniedzy chcesz dodac? " << endl;
	cin>> x;
	money = money + x;
	cout << "Ogolnie pieniedzy w budzecie" << money << endl;
	menu();
	return 0;
}

int WholeProgramForCalculations::substractMoney()
{
	int y;
	cout << "Ile pieniedzy chcesz odjac? " << endl;
	cin >> y;
	money = money - y;
	cout << "Ogolnie pieniedzy w budzecie" << money << endl;
	menu();
	return 0;
}

void WholeProgramForCalculations::menu(){

	std::cout << "Witaj w programie do obliczania budzetu domowego. Najpierw trzeba otworzyc plik: " << std::endl;
	std::cout << "1. Otworz plik z danymi." << std::endl;
	std::cout << "2. Zapisz plik z danymi." << std::endl;
	std::cout << "3. Dodaj pieniadze." << std::endl;
	std::cout << "4. Odejmij pieniadze." << std::endl;
	std::cout << "5. Zamknij program." << std::endl;

	int x;
	std::cin >> x;

	switch (x) {

	case 1:
		openFile();
		break;
	case 2:
		saveFile();
		break;
	case 3:
		addMoney();
	case 4:
		substractMoney();
		break;
	case 5:
		std::cin.get();
		break;
	default:
			std::cout << "Taka opcja nie istnieje." << std::endl;
		break;
	}




}
