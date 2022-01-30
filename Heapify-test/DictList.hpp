//----------PreCompiler Directives----------
#include<string>

/**
 * DictList
 * 
 * Description:
 *      Link List for storing dictionary definitions
 * 
 * Public Methods:
 *      - A list of 
 *      - each public method
 *      - with return types
 * 
 * Private Methods:
 *      - A list of 
 *      - each private method
 *      - with return types
 * 
 * Usage: 
 * 
 *      - examples of how
 *      - to use your class 
 *      
 */

class DictList {
    //node for storing our data and linking our points
    struct Node {
        std::string word;
        std::string definition;
        Node *next;
        Node *previous;

        Node(std::string word = "", std::string definition = ""){
        this->word = word;
        this->definition = definition;
        next = nullptr;
        previous = nullptr;
        }
    };

public://------------------------------
    void insert(std::string word, std::string definition){
        //create our node to link and add
        Node *tempNode = new Node(word,definition);
        //if the list is empty
        if (head == nullptr){
            head = tempNode;
            tracker = tempNode;
        //if we're not at the end of the list
        } else if (tracker->next != nullptr){
            Node *nextNode = tracker->next;
            tracker->next = tempNode;
            tempNode->previous = tracker;
            nextNode->previous = tempNode;
			tempNode->next = nextNode; 
        //if we are at the end of the list
        } else {
            tracker->next = tempNode;
            tempNode->previous = tracker;
			tracker = tracker->next;
        }
    }

	void sortedInsert(std::string word, std::string definition){
		//if the list is empty
        if (head == nullptr){
            insert(word,definition);
		}
		//find where to insert item first
		//start at the front
		tracker = head;
		//use a flag so our while logic dosen't get out of hand
		bool spotFound = false;
		//while a spot as not been found and we are not at the end
		//of the list
		while (spotFound == false && tracker->next != nullptr){
			if (word > tracker->word && word < tracker->next->word){
				spotFound = true;
			} else {
				tracker = tracker->next;
			}
		}
		insert(word,definition);
	}

    void remove(){
        //if the tracker is not at the front of the list
        if (tracker->previous != nullptr){
            //use temporary node to swap link previous and next of the nodes
            //infront of and behind one being deleted
            Node *tempPrevious = tracker->previous;
            tempPrevious->next = tracker->next;
            tempPrevious->next->previous = tempPrevious;
            //deletes the object being pointed to
            delete tracker;
            //put tracker at the node before the one being deleted
            tracker = tempPrevious;
        } else {
			head = tracker->next;
			head->previous = nullptr;
			delete tracker;
			tracker = head;
		}

    }

    void forward(){
        if (tracker->next != nullptr){tracker = tracker->next;}
    }

    void backward(){
        if (tracker->previous != nullptr){tracker = tracker->previous;}
    }

	void reset(){
		tracker = head;
	}

    void setWord(std::string word){tracker->word = word;}

    std::string getWord(){return tracker->word;}

    void setDefinition(std::string definition){tracker->definition = definition;}

    std::string getDefinition(){return tracker->definition;}


private://------------------------------
    Node *head = nullptr;
    Node *tracker = nullptr;

};