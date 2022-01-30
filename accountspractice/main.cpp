#include <iostream>
#include "Account.cpp"
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

//prototypes
std::string mainPrompt();
std::string getMainPromptInput();
std::string databaseToString(std::vector <Account> database, bool numberedList);

int main() {
	//varibles
	bool quit = false;
	std::string response;
	std::vector <Account>database;

	while(!quit){
		std::cout << mainPrompt();
		response = getMainPromptInput();

		if (response == "crt"){
			std::string name;
			char type;
			int balance;
			int YYYY, MM, DD;

			std::cout << "What is the name to go on your account?\n";
			std::cin >> name;
			std::cout << "What type of account would you like (c for checking, s for savings)\n";
			std::cin >> type;
			std::cout << "what is your starting balance?\n";
			std::cin >> balance;
			std::cout << "What is the current year?\n";
			std::cin >> YYYY;
			std::cout << "What is the current Month? (number)\n";
			std::cin >> MM;
			std::cout << "What is the current Day?\n";
			std::cin >> DD;

			Account newAccount(name,type,balance,YYYY,MM,DD);
			database.push_back(newAccount);
		} else if (response == "del"){
			std::cout << databaseToString(database, true);
			std::cout << "Please enter the number off to the left of the account to delete:\n";
			int index = -1;
			while(index == -1){
				std::cin >> index;
				if(index > 0 && index < database.size()){
					database.erase(database.begin() + index);
				} else {
					std::cout << "invalid index\n";
					index = -1;
				}
			}
		} else if (response == "dps"){
			
		} else if (response == "wit"){
			
		} else if (response == "ptr"){
			std::cout << databaseToString(database, false);
		} else if (response == "qit"){
			return 0;
		}
	}
}

std::string mainPrompt(){
	std::string result = "";
	result += "What would you like to do? Enter the command in parentheses:\n";
	result += "(crt) - Create a new account\n";
	result += "(del) - Delete an account\n";
	result += "(dps) - Deposit money into and account\n";
	result += "(wit) - Withdraw money from an account\n";
	result += "(ptr) - Display all account in a database\n";
	result += "(qit) - Quit out of the program\n";
	return result;
}

std::string getMainPromptInput(){
	std::string result = "";
	while(result == ""){
		std::cin >> result;
		std::cout << "result: " << result << std::endl;
		if(result == "crt" || result == "del" || result == "dps" || 
		result == "wit" || result == "ptr" || result == "qit"){
			return result;
		} else {
			//result = "";
			std::cout << "Incorrect Input, please try again:\n";
			return "qit";
		}
	}
}

std::string databaseToString(std::vector <Account>database, bool numberedList){
	std::stringstream string;
	for (int i = 0; i < database.size(); i++){
		if(numberedList){
			string << std::left << std::setw(5) << i << '.';
		}
		string << std::setw(15) << std::left << database[i].getName();
		string << std::setw(2) << std::left << database[i].getType();
		string << std::setw(15) << std::left << database[i].getBalance();
		string << std::left << database[i].getDate().getYear() << '/';
		string << std::left << database[i].getDate().getMonth() << '/';
		string << std::left << database[i].getDate().getDay() << '\n'; 
	}

	return string.str();
}