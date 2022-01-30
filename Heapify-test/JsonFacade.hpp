///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Tery Griffin
// Email:            terry.griffin@msutexas.edu
// Title:            JsonFacade
//
// Description:
//          This class is a facade pattern that simplifies the use of a very nicely written
//          hpp file from here: https://github.com/nlohmann/json 
//          
//          There is a lot of functionality that the header file includes, that we don't need.
//          This class lets a student treat a json array objects as an array. 
//
// Usage:
//
//      J = new JsonFacade("file_to_read");
//      size = J->getSize();                    // get array size
//
//      for (int i = 0; i < size; i++) {
//          obj = J->getNext();                 // read next object in json array
//          // do something with your json object
//      }
//
// Files:           
//      json.hpp
/////////////////////////////////////////////////////////////////////////////////
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>

#include "json.hpp"

//using namespace std;
using std::cout;
using std::ofstream;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;

using json = nlohmann::json;

class JsonFacade {
private:
    json Data;
    int Size;
    int Index;
    string FileName;
    vector<string> Keys;
    vector<string> Values;
    

public:
    /**
     * JsonFacade: constructor that reads a file containing json and subsequently creates
     *             an aray of dictionaries. 
     * 
     * Params:
     *     string filename : the filename containing the json to be read
     * 
     */
    JsonFacade(string filename) {
        FileName = filename;

        ifstream input(FileName);
        input >> Data;
        input.close();

        Size = Data.size();

        for (auto& [key, value] : Data.items()) {
            Keys.push_back(key);
            Values.push_back(value);
        }
        
        Index = 0;
    }

    /**
     * getKeys: gets a vector of keys
     * 
     * 
     */
    vector<string> getKeys(){
        return Keys;
    }

    /**
     * getKey: gets a key at position i
     * 
     * 
     */
    string getKey(int i){
        return Keys[i];
    }
    
    /**
     * getValue: gets a value at array[key]
     * 
     * 
     */
    string getValue(string key){
        return Data[key];
    }


    /**
     * getNext: gets the "next" value in the array. Used to
     *          traverse the array with directly accessing it.
     * 
     * 
     */
    json getNext() {
        if (Index < Size) {
            return Data[Index++];
        }
        return NULL;
    }

    /**
     * getIth: gets the Ith json object from the array 
     * 
     * 
     */
    json getIth(int i) {
        if (i < Size) {
            return Data[i];
        }
        return NULL;
    }

    /**
     * pushBack: converts a string to json and pushes on end of array
     * 
     * Params:
     *     string obj  : a string json object which whould be in the following format:
     * 
     *                           "{\"key0\":"value0",\"key1\":1,\"keyn\":\"valuen"\}"
     * Returns:
     *     void
     *                
     */ 
    void pushBack(string obj){
        
        json j = json::parse(obj);
        Data.push_back(j);
        cout << Data.dump(4) << endl;
    }

    /** 
     * getSize: returns the size of the json object (count of objects)
     * 
     */
    int getSize() {
        return Size;
    }

    /**
     * saveFile: saves the json object to a file
     * 
     * Params:
     * 
     *     string filename : a filename to save object to. Defaults to 
     *                       name passed into constructor, meaning it will
     *                       overwrite the original file!
     *  Returns:
     *     NULL
     */
    void saveFile(string filename = ""){
        if(filename == ""){
            filename = FileName;
        }
        
        ofstream out(filename);
        out << std::setw(4) << Data << endl;
        out.close();
    }
};
