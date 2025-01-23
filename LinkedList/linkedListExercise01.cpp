
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

  Node* findMidPoint() {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    cout << "Mid point: " << slow->value << endl;

    return fast;
  }
};

int main() {
  LinkedList* linkedList = new LinkedList();

  int nums[10] = {5, 7, 22, 1, 3, 9, 8, 11, 14, 18};
  int numsLength = sizeof(nums) / sizeof(nums[0]);

  for (int i = 0; i < numsLength; i++) {
    if (i == 0) linkedList->insertAtStart(nums[i]);
    else linkedList->insertAtEnd(nums[i]);
  }

  linkedList->traverse();

  Node* midPoint = linkedList->findMidPoint();

  delete linkedList; 

  return 0;
}

