#pragma once
#include<string>
#include "Date.h"

class Account{

	private:

	std::string name;
	char type;
	int balance;
	Date lastTransaction;

	public:
	Account();

	Account(std::string nameIn, char typeIn, int balanceIn, int YYYY, int MM, int DD);

	void setName(std::string nameIn);

	void setType(char typeIn);

	void setBalance(int balanceIn);

	void setDate(int YYYY, int MM, int DD);

	std::string getName();

	char getType();

	int getBalance();

	Date getDate();
};