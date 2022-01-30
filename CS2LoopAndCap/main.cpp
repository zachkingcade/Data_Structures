#include <iostream>
#include <string>

//Prototypes
char lowerCaseCharater(char symbol);
char upperCaseCharater(char symbol);

int main() {
  //here we start our menu

	/*prime your loop here, that just means we set a varibles value to allow the loop to atleast run the first time
	based on whatever logic we are using to run our loop, in this case the loop goes until the user inputs "quit"*/
	std::string userInput = "";

	while(userInput != "quit"){
		//grab our input
		std::cout << "Please enter a command from the list below:\n";
		std::cout << "[upper_to_lower]\n";
		std::cout << "[lower_to_upper]\n";
		std::cout << "[option_3]\n";
		std::cout << "[option_4]\n";
		std::cout << "[quit]\n";
		std::cin >> userInput;

		//normalize user input (always same case)
		for(int i = 0; i < userInput.size(); i++){
			userInput[i] = lowerCaseCharater(userInput[i]);
		}

		//when thru the list of our commands
		/*make sure to use else if's here and not just a bunch of ifs so that
		1.It stops when it finds the command it is looking for and
		2.The lone else at the bottom doesn't fire only when the last command is not matched to */
		if(userInput == "upper_to_lower"){
			//grab our input text
			std::cout << "Please enter a word:\n";
			std::cin >> userInput;

			//make everything lowercase
			for(int i = 0; i < userInput.size(); i++){
				userInput[i] = lowerCaseCharater(userInput[i]);
			}
			std::cout << "Your new word: " << userInput << std::endl;
		} else if (userInput == "lower_to_upper"){
			//grab our input text
			std::cout << "Please enter a word:\n";
			std::cin >> userInput;

			//make everything lowercase
			for(int i = 0; i < userInput.size(); i++){
				userInput[i] = upperCaseCharater(userInput[i]);
			}
			std::cout << "Your new word: " << userInput << std::endl;
		}  else if (userInput == "option_3"){
			std::cout << "some code here for option 3\n";
		} else if (userInput == "option_4"){
			std::cout << "some code here for option 4\n";
		} else if (userInput == "quit"){
			//no need to do anything here, the while loop will end and so will the program
		} else {
			std::cout << "Unknown command please try again:\n";
		}
		//add a new line to make space between blocks of commands
		std::cout << "\n";
	}
	return 0;
}

/*so charcters are stored by the computer as a number of ascii, this means no only can we compare an character to
number but we can also add or subtract to a character to get another number. read below:
ASCII value of lowercase char a to z ranges from 97 to 122
ASCII value of uppercase char A to Z ranges from 65 to 92
so to go from upper to lower we add 32, and to go from lower to upper we subtract the same amount*/

char lowerCaseCharater(char symbol){
	//check if the character is an uppercase letter, if it is not return it
	if(symbol > 64 && symbol < 93){
		return (symbol + 32);
	} else {
		return symbol;
	}
}

char upperCaseCharater(char symbol){
	//check if the character is an uppercase letter, if it is not return it
	if(symbol > 96 && symbol < 123){
		return (symbol - 32);
	} else {
		return symbol;
	}
}