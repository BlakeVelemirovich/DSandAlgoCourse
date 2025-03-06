#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
  int value;
  Node* next;
};

// Define the LinkedList class
class LinkedList {
private:
  Node* head; 

public:
  // Constructor to initialize the head to NULL
  LinkedList() : head(nullptr) {}

  // Deconstructor
  ~LinkedList() {
    Node* curNode = head;

    while(curNode != nullptr) {
      Node* temp = curNode;
      curNode - curNode->next;
      delete temp;
    }
  }

  // Insert a set of numbers
  void insertSet(int *arr, int len ) {
    Node* curNode = head;
    
    if (head != nullptr) {
      while (curNode->next != nullptr) {
        curNode = curNode->next;
      }
    }

    for (int i = 0; i < len; i++) {
      Node* newNode = new Node();
      newNode->value = arr[i];
      newNode->next = nullptr;

      if (curNode == nullptr) {
        curNode = newNode;
        head = curNode;
      } else {
        curNode->next = newNode;
        curNode = curNode->next;
      }
    }
}

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

  void deleteNode(int value) {
    if (head == nullptr) { // If the list is empty
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* current = head;

    
    // Traverse the list to find the node with the given value
    Node* prev = nullptr;
    while (current != nullptr && current->value != value) {
        prev = current;
        current = current->next;
    }

    // If the value is not found
    if (current == nullptr) {
        cout << "Value not found in the list." << endl;
        return;
    }

    // Update the previous node's next pointer to skip the current node
    prev->next = current->next;

    // Free the memory of the node to be deleted
    delete current;
  }
};

int main() {
  LinkedList* linkedList = new LinkedList();

  int nums[10] = {5, 7, 22, 1, 3, 9, 8, 11, 14, 18};
  int numsLength = sizeof(nums) / sizeof(nums[0]);

  linkedList->insertSet(nums, numsLength);

  int numsTwo[2] = {10, 15};
  int numsTwoLength = sizeof(numsTwo) / sizeof(nums[0]);

  linkedList->insertSet(numsTwo, numsTwoLength);

  linkedList->traverse();

  delete linkedList; 

  return 0;
}

