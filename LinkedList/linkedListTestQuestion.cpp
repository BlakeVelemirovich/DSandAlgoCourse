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
    // Create curNode that we will use to traverse through the linked list without modifying our head
    Node* curNode = head;
    
    // Check if we have any valuse in the list before trying to traverse a nullptr
    if (head != nullptr) {
      while (curNode->next != nullptr) {
        curNode = curNode->next;
      }
    }

    // Iterate through the entire input array
    for (int i = 0; i < len; i++) {
      // New node with input value
      Node* newNode = new Node();
      newNode->value = arr[i];
      newNode->next = nullptr;

      // Check to see if the head node is a nullptr, if it is we need to set the head to the first value
      if (curNode == nullptr) {
        curNode = newNode;
        head = curNode;
      } else {
        curNode->next = newNode;
        curNode = curNode->next;
      }
    }
  }

  // Find the element at a specific position
  void findElementAtPosition(int position) {
    if (head == nullptr) {
      cout << "The list is empty, please insert values and try again.";
      return;
    }
    
    Node* curNode = head;
    // Iterate through the nodes and stop when counter is equal to position
    for (int i = 0; i < position; i++) {
      curNode = curNode->next;

      // If curNode is nullptr, then we do not have a big enough list to accomdate the request, as we ran out of nodes.
      if (curNode == nullptr) {
        cout << "The list is not big enough yet to accomdate request, enter smaller position or add new elements";
        cout << endl << "Current size is: " << i;
        return;
      }
    }

    cout << "The value at position: " << position << " is: " << curNode->value << endl;
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

  // Demonstration of adding a set of numbers to the linked list
  int nums[10] = {5, 7, 22, 1, 3, 9, 8, 11, 14, 18};
  int numsLength = sizeof(nums) / sizeof(nums[0]);

  linkedList->insertSet(nums, numsLength);

  int numsTwo[2] = {10, 15};
  int numsTwoLength = sizeof(numsTwo) / sizeof(nums[0]);

  linkedList->insertSet(numsTwo, numsTwoLength);

  linkedList->traverse();

  // Demonstration of finding a value at a specific index
  linkedList->findElementAtPosition(3);

  // Demonstration of error checking if list isn't big enough to handle request
  linkedList->findElementAtPosition(30);

  // Free memory
  delete linkedList; 

  return 0;
}

