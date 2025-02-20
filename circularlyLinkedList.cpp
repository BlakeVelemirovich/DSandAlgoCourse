#include <iostream>

using namespace std;

// Define the structure of a node in the circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = createNode(value);

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
        head = newNode; // Update the head
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

// Function to display the circular linked list
void displayList(Node* head) {
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

int main() {
    Node* head = nullptr; // Initialize an empty circular linked list

    // Insert elements at specific positions
    insertAtPosition(head, 10, 0); // Insert at head
    insertAtPosition(head, 20, 1); // Insert at position 1
    insertAtPosition(head, 30, 1); // Insert at position 1
    insertAtPosition(head, 40, 3); // Insert at position 3

    // Display the circular linked list
    displayList(head);

    return 0;
}