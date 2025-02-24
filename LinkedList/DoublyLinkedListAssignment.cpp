#include <iostream>
using namespace std;

// Define a Node struct to represent each element in the doubly linked list
// Use templates to make the Node generic (can store any data type)
template <typename T>
struct Node {
    T data; 
    Node* next;
    Node* prev;

    // Constructor to initialize a node with a given value
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    // Pointer to the first node in the list (front of the deque)
    Node<T>* head; 
    // Pointer to the last node in the list (rear of the deque)
    Node<T>* tail; 

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Method to insert an element at the front of the deque
    void insertFront(T value) {
        // Create a new node with the given value
        Node<T>* newNode = new Node<T>(value);

        // Check if the list is empty
        if (!head) {
            // If empty, set both head and tail to the new node
            head = tail = newNode;
        } else {
            //  Set the new node's next pointer to the current head
            newNode->next = head;
            // Set the current head's previous pointer to the new node
            head->prev = newNode;
            // Pointer to the last node in the list (rear of the deque)
            head = newNode;
        }
    }

    // Method to insert an element at the rear of the deque
    void insertEnd(T value) {
        // Create a new node with the given value
        Node<T>* newNode = new Node<T>(value);

        // Check if the list is empty
        if (!tail) {
            // If empty, set both head and tail to the new node
            head = tail = newNode;
        } else {
            // Set the current tail's next pointer to the new node
            tail->next = newNode;
            // Set the new node's previous pointer to the current tail
            newNode->prev = tail;
            // Update the tail to point to the new node
            tail = newNode;
        }
    }

    // Method to delete an element from the front of the deque
    void deleteFront() {
        // Check if the list is empty
        if (!head) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node<T>* temp = head;

        // Move the head pointer to the next node
        head = head->next;

        // This is here for error checking and making sure if the list is now empty after deletion
        if (head) {
            // If not empty, set the new head's previous pointer to nullptr
            head->prev = nullptr;
        } else {
            // If empty, set the tail to nullptr as well
            tail = nullptr;
        }

        delete temp;
    }

    // Method to delete an element from the rear of the deque
    void deleteEnd() {
        // Check if the list is empty
        if (!tail) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node<T>* temp = tail;

        // Move the tail pointer to the previous node
        tail = tail->prev;

        // This is here for error checking and making sure if the list is now empty after deletion
        if (tail) {
            // If not empty, set the new tail's next pointer to nullptr
            tail->next = nullptr;
        } else {
            // If empty, set the head to nullptr
            head = nullptr;
        }

        delete temp;
    }

    // Method to print the entire list for demonstrations and to make sure everything is going fine so I don't have to go through the debugger over and over again
    void printList() {
        // Start from the head of the list
        Node<T>* temp = head;

        // Traverse the list and print each node's data with a fancy little arrow to show as a visual representation that it's a doubly linked list and points both forwards and backwords.
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        // Print "NULL" to indicate the end of the list
        cout << "NULL" << endl;
    }

    // Destructor to free all memory used by the list
    ~DoublyLinkedList() {
        // Continuously delete nodes from the front until the list is empty
        while (head) {
            deleteFront();
        }
    }
};

int main() {
    // Demonstration of the doubly linked list
    DoublyLinkedList<int> doublyLinkedList;

    // Insert elements at the front and rear of the deque
    doublyLinkedList.insertFront(10); 
    doublyLinkedList.insertFront(20); 
    doublyLinkedList.insertEnd(30); 
    doublyLinkedList.insertEnd(40); 

    // Print the list
    cout << "Doubly Linked List: ";
    doublyLinkedList.printList();

    // Delete an element from the front
    doublyLinkedList.deleteFront();
    cout << "After deleting front: ";
    doublyLinkedList.printList();

    // Delete an element from the rear
    doublyLinkedList.deleteEnd(); 
    cout << "After deleting end: ";
    doublyLinkedList.printList();

    return 0;
}