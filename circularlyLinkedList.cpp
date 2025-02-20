#include <iostream>

using namespace std;

// Define the structure of a node in the circular linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Destructor to clean up memory
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* temp = head;
        Node* toDelete;

        // Traverse the list and delete all nodes
        do {
            toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } while (temp != head);

        head = nullptr;
    }


    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);

        // If the list is empty, make the new node the head and point it to itself
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Circular reference
            cout << "Node inserted as the head (list was empty)." << endl;
            return;
        }

        // If position is 0, insert at the head
        if (position == 0) {
            newNode->next = head;
            Node* temp = head;
            // Traverse to the last node to update its next pointer
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode; 
            cout << "Node inserted at the head." << endl;
            return;
        }

        // Traverse to the node just before the desired position
        Node* temp = head;
        int currentPosition = 0;
        while (currentPosition < position - 1 && temp->next != head) {
            temp = temp->next;
            currentPosition++;
        }

        // Insert the new node
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node inserted at position " << position << "." << endl;
    }


    void displayList() const {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList list;

    // Insert elements at specific positions
    list.insertAtPosition(10, 0); // Insert at head
    list.insertAtPosition(20, 1); // Insert at position 1
    list.insertAtPosition(30, 1); // Insert at position 1
    list.insertAtPosition(40, 3); // Insert at position 3

    list.displayList();

    return 0;
}