//----------PreCompiler Directives----------
#include "JsonFacade.hpp"
#include "DictList.hpp"
#include <algorithm>
#include "Timer.hpp"
#include <iostream>
#include "Termio.h"
#include <fstream>
#include <string>
#include <vector>

//----------Prototypes----------
std::string wordLookUp(DictList,std::string);

//----------Main----------
int main (){
    int itemIndex;                //used to keep track of where the letters having been searched for
                                  //apear in the dictinary
    char key = ' ';                             
    string searchBar = "";        //keeps track of string being searched for
	std::string resultsHolder;
	int jsonSize;
    Timer clock;
    long loadms;
	Term::IO stream;
	ofstream out;
	out.open("log.txt");

	//Fully clear screen for print using a 200x100 wall of spaces starting
	//at the very top of the console
	//set up cleanScreen;
	std::string cleanScreen = "";
	for (int i = 0; i < 100; i++){
		cleanScreen += "                                                                                                    ";
		cleanScreen += "                                                                                                    ";
		cleanScreen += '\n';
	}
	//print
	stream << Term::Point(0,0);
	stream << cleanScreen << Term::Point(0,0);

	//----------Load Up Our Linked-List Dictionary----------
    //start our clock to estimate how long it takes to load up our ditionary into our linked list
    clock.Start();

    //---Set up Dictinary---
    JsonFacade book("dict_w_defs.json");    //create dictinary object from json file
	DictList dict;

	jsonSize = book.getSize();
	for (int i = 0; i < jsonSize; i++){
		dict.insert(book.getKey(i),book.getValue(book.getKey(i)));
	}

    //stop the timer on our clock and print the time
    clock.End();
    stream << "Time to load up linked-list|\tMilliseconds: " << std::to_string(clock.MilliSeconds());
	stream << "\tSeconds: " << std::to_string(clock.Seconds()) << '\n';
	//print to log
	clock.End();
    out << "Time to load up linked-list|\tMilliseconds: " << std::to_string(clock.MilliSeconds());
	out << "\tSeconds: " << std::to_string(clock.Seconds()) << '\n';

	//----------Word Lookup Loop----------
	//exit the loop when ~ is pressed
	while (key != '~'){
		//read in our single key input
		stream >> key;

		//if it is actually character then add it to the searchBar
		//if it is the backspace then remove a character from the searchBar
		if (key != 8 && key != 127){
			searchBar += key;
		} else {
			searchBar = searchBar.substr(0, searchBar.length() - 1);
		}

		//clear the lookup area
		stream << Term::Point(1,0);
		stream << cleanScreen << Term::Point(1,0);

		//print searchBar
		stream << "search: " << searchBar << '\n';

		//look up the term and track lookup time
		clock.Start();

		resultsHolder = wordLookUp(dict, searchBar);

		clock.End();
		//print time to find recommendations and the 10 recommended words
    	stream << "Time to lookup " << searchBar <<  ":\tMilliseconds: " << std::to_string(clock.MilliSeconds());
		stream << "\tSeconds: " << std::to_string(clock.Seconds()) << '\n';
		stream << resultsHolder << '\n';


		//print to log file
		out << "----------------------------------------------------------------------";
		out << "search: " << searchBar << '\n';
		out << "Time to lookup " << searchBar <<  ":\tMilliseconds: " << std::to_string(clock.MilliSeconds());
		out << "\tSeconds: " << std::to_string(clock.Seconds()) << '\n';
		out << resultsHolder << '\n';
	}

	//close log file
	out.close();
	
} //End of Main

//----------Functions----------

std::string wordLookUp(DictList list, std::string word){
    //start from the front of the list
    list.reset();
    //go until you find where the words become bigger or equal
    while (word > list.getWord()){
        list.forward();
    }
    //create a string of the next 10 words after that
    std::string result = "";

    for (int i = 0; i < 10; i++){
        result = result + list.getWord() + " ";
        list.forward();
    }

    //return our result
    return result;
}