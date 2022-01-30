#pragma once
#include "Account.h"
#include "Date.cpp"


Account::Account(){
	name = "";
	type = ' ';
	balance = 0;
}

Account::Account(std::string nameIn, char typeIn, int balanceIn, int YYYY, int MM, int DD){
	name = nameIn;
	type = typeIn;
	balance = balanceIn;
	lastTransaction.setYear(YYYY);
	lastTransaction.setMonth(MM);
	lastTransaction.setDay(DD);
}

void Account::setName(std::string nameIn){
	name = nameIn;
}

void Account::setType(char typeIn){
	type = typeIn;
}

void Account::setBalance(int balanceIn){
	balance = balanceIn;
}

void Account::setDate(int YYYY, int MM, int DD){
	lastTransaction.setYear(YYYY);
	lastTransaction.setMonth(MM);
	lastTransaction.setDay(DD);
}

std::string Account::getName(){
	return name;
}

char Account::getType(){
	return type;
}

int Account::getBalance(){
	return balance;
}

Date Account::getDate(){
	return lastTransaction;
}