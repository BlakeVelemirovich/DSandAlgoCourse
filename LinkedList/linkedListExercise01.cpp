
#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
  int value;
  Node* next;
};

// Define the LinkedList class
class LinkedList {
  Node* head; 

public:
  // Constructor to initialize the head to NULL
  LinkedList() : head(nullptr) {}

  // Insert a node at the start of the list
  void insertAtStart(int value) {
    Node* newNode = new Node(); 
    newNode->value = value;     
    newNode->next = head;       
    head = newNode;            
  }

  // Insert a node at the end of the list
  void insertAtEnd(int value) {
    Node* newNode = new Node(); 
    newNode->value = value;     
    newNode->next = nullptr;  

    Node* temp = head;          
    while (temp->next != nullptr) { 
      temp = temp->next;
    }

    temp->next = newNode;       
  }

  // Traverse the list and print the values
  void traverse() {
    Node* curNode = head;       
    while (curNode != nullptr) { 
      cout << curNode->value << " "; 
      curNode = curNode->next;   
    }
    cout << endl;               
  }
};

int main() {
  LinkedList* linkedList = new LinkedList();

  int numOne = 1;
  int numTwo = 34;
  int numThree = 40;

  linkedList->insertAtStart(numOne); 
  linkedList->insertAtEnd(numTwo); 
  linkedList->insertAtEnd(numThree);

  linkedList->traverse();

  delete linkedList; 

  return 0;
}

