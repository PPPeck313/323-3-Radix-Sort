//Preston Peck
//CS 323
//October 16, 2016
//Project 3.1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int, char**);

class listNode {
    private:
	    string data;
	    listNode* next;
		
    public:
        listNode();
		~listNode();
        listNode(string d);
        listNode(string d, listNode* n);
        string getData();
        listNode* getNext();
        void setData(string d);
        void setNext(listNode* n);

	friend class linkedListStack;
	friend class linkedListQueue;
	friend class RadixSort;
	friend int ::main(int, char**);
};

class linkedListStack {
    private:
	    listNode* top;
	
    public:
        linkedListStack();
        void push(listNode* ln);
        listNode* pop();
        bool isEmpty();
        void printStack();
};

class linkedListQueue {
    private:
	    listNode* head;
	    listNode* tail;
    public:
        linkedListQueue();
        void addTail(listNode* ln);
        listNode* deleteHead();
        bool isEmpty();
        void printQueue(ofstream& outFile);

	friend class RadixSort;
	friend int ::main(int, char**);
};

class RadixSort {
    private:
	    int tableSize;
		linkedListQueue*** hashTable;
	    int currentTable;
	    int previousTable;
	    int longestStringLength;
	    int currentDigit;
	    int tableIndex;
    public:
        RadixSort();
		~RadixSort();
        char getVal(listNode* ln);
        int hashIndex(char c);
        void printTable(ofstream& outFile);
        void padString(listNode* ln);

		friend int ::main(int, char**);
};


int main(int argc, char *argv[]) {
    ifstream inFile;
	ofstream outFile;
    inFile.open(argv[1]);
        if (!inFile.is_open()) {
        cerr<<"File failed to open!"<<endl;
        return 0;
    }
	
	RadixSort* rS = new RadixSort();
	linkedListStack* Top = new linkedListStack();
	
	string data = "";
	while(inFile >> data) {
		listNode* newNode = new listNode(data);
		Top->push(newNode);
		if (data.length() > rS->longestStringLength) {
			rS->longestStringLength = data.length();
		}
	}
	inFile.close();
	Top->printStack();
	
	listNode* node;
	char val;
	int hashIndex;
	
	outFile.open(argv[2]);
	rS->currentDigit = rS->longestStringLength - 1;
	while (!Top->isEmpty()) {
		node = Top->pop();
		rS->padString(node);
		
		val = rS->getVal(node);
		hashIndex = rS->hashIndex(val);
		rS->hashTable[rS->currentTable][hashIndex]->addTail(node);
	}
	rS->printTable(outFile);
	
	rS->currentDigit--;
	while (rS->currentDigit >= 0) {
		if (rS->currentTable == 0) {
			rS->currentTable = 1;
			rS->previousTable = 0;
		}
		else {
			rS->currentTable = 0;
			rS->previousTable = 1;
		}
		
		for (rS->tableIndex = 0; rS->tableIndex < rS->tableSize; rS->tableIndex++) {
			while (rS->hashTable[rS->previousTable][rS->tableIndex]->head->next != NULL) {
				node = rS->hashTable[rS->previousTable][rS->tableIndex]->deleteHead();
				
				val = rS->getVal(node);
				hashIndex = rS->hashIndex(val);
				rS->hashTable[rS->currentTable][hashIndex]->addTail(node);
			}
		}
		rS->printTable(outFile);
		rS->currentDigit--;
	}
	outFile.close();
}



listNode::listNode() {
	data = "";
	next = NULL;
}

listNode::~listNode() {
	delete this;
}

listNode::listNode(string d) {
	data = d;
	next = NULL;
}

listNode::listNode(string d, listNode* n) {
	data = d;
	next = n;
}

string listNode::getData() {
	return data;
}

listNode* listNode::getNext() {
	return next;
}

void listNode::setData(string d) {
	data = d;
}

void listNode::setNext(listNode* n) {
	next = n;
}



linkedListStack::linkedListStack() {
	top = NULL;
}

void linkedListStack::push(listNode* ln) {
	ln->next = top;
	top = ln;
}

listNode* linkedListStack::pop() {
	listNode* pop = new listNode(top->data);
	top = top->next;
	return pop;
}

bool linkedListStack::isEmpty() {
	if (top == NULL) {
		return true;
	}
	return false;
}

void linkedListStack::printStack() {
	listNode* traveler = top;
	while (traveler != NULL) {
		cout << traveler->data << endl;
		traveler = traveler->next;
	}
}



linkedListQueue::linkedListQueue() {
	head = new listNode();//dummy
	tail = head;
}

void linkedListQueue::addTail(listNode* ln) {
	tail->next = ln;
	tail = ln;
}

listNode* linkedListQueue::deleteHead() {
	listNode* temp = NULL;
	if (!isEmpty()) {
		temp = new listNode(head->next->data);
		head->next = head->next->next;
	}
	if (head->next == NULL) {
		tail = head;
	}
	return temp;
}

bool linkedListQueue::isEmpty() {
	if (head == tail) {
		return true;
	}
	return false;
}

void linkedListQueue::printQueue(ofstream& outFile) {
	listNode* traveler = head->next;
	while (traveler != NULL) {
		int counter = 0;
		for (int i = 0; i < traveler->data.length(); i++) {
			if (traveler->data.at(i) == ' ') {
				counter++;
			}
		}
		string temp = traveler->data.substr(counter);
		if (traveler->next == NULL) {
			outFile << temp;
		}
		else {
			outFile << temp << ", ";
		}
		traveler = traveler->next;
	}
}



RadixSort::RadixSort() {
	tableSize = 256;
	hashTable = new linkedListQueue**[2];
	for (int i = 0; i <= 1; i++) {
		hashTable[i] = new linkedListQueue*[tableSize];
		for (int j = 0; j < tableSize; j++) {
			hashTable[i][j] = new linkedListQueue();
		}
	}
	currentTable = 0;
	previousTable = 0;
	longestStringLength = 0;
	currentDigit = 0;
	tableIndex = 0;
}

RadixSort::~RadixSort() {
	for (int i; i <=1 ; i++) {
		for (int j; j < tableSize; j++) {
			delete hashTable[i][j];
		}
		delete hashTable[i];
	}
	delete this;
}

char RadixSort::getVal(listNode* ln) {
	return ln->data.at(currentDigit);
}

int RadixSort::hashIndex(char c) {
	int toInt = (int) c;
	return toInt;
}

void RadixSort::printTable(ofstream& outFile) {
	for (tableIndex = 0; tableIndex < tableSize; tableIndex++) {
		if (hashTable[currentTable][tableIndex]->head->next != NULL) {
			outFile << "Table " << "[" << currentTable << "]" << "[" << tableIndex << "]: ";
			hashTable[currentTable][tableIndex]->printQueue(outFile);
			outFile << endl;
		}
	}
	outFile << endl;
}

void RadixSort::padString(listNode* ln) {
	while (ln->data.length() < longestStringLength) {
		ln->data = ' ' + ln->data;
	}
}