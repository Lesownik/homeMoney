#pragma once
#ifndef	CLASSES
#define CLASSES

class WholeProgramForCalculations {
private:
	//variables
	int money, moneyPlus, moneyMinus;
	//functions
public:
	WholeProgramForCalculations(int=0, int=0, int=0);
	~WholeProgramForCalculations();
	int addMoney();
	int substractMoney();
	int openFile();
	void saveFile();
	void menu();
};





#endif

