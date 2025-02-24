#include <iostream>
using namespace std;

// Define Node as a struct
template <typename T> // Generic implementation for multiple data types
struct Node {
    T data;        // Data of the node
    Node* next;    // Pointer to the next node
    Node* prev;    // Pointer to the previous node

    // Constructor to initialize the node with a given value
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class to implement a deque
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head; // Pointer to the first node in the list
    Node<T>* tail; // Pointer to the last node in the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert an element at the front of the deque
    void insertFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) { // If the list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert an element at the rear of the deque
    void insertEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!tail) { // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete an element from the front of the deque
    void deleteFront() {
        if (!head) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // If the list becomes empty
        }
        delete temp;
    }

    // Delete an element from the rear of the deque
    void deleteEnd() {
        if (!tail) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; // If the list becomes empty
        }
        delete temp;
    }

    // Print the list (for debugging purposes)
    void printList() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        while (head) {
            deleteFront();
        }
    }
};

int main() {
    DoublyLinkedList<int> dll;
    dll.insertFront(10);
    dll.insertFront(20);
    dll.insertEnd(30);
    dll.insertEnd(40);

    cout << "Doubly Linked List: ";
    dll.printList();

    dll.deleteFront();
    cout << "After deleting front: ";
    dll.printList();

    dll.deleteEnd();
    cout << "After deleting end: ";
    dll.printList();

    return 0;
}