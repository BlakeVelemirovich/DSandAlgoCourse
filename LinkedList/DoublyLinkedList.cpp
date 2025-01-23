#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    ~DoublyLinkedList() {
        Node* curNode = head;
        while (curNode != nullptr) {
            Node* temp = curNode;
            curNode = curNode->next;
            delete temp;
        }
    }

    void insertNewNode(int value) {
        Node* newNode = new Node(value);

        Node* curNode = head;

        if (head == nullptr) {
            head = newNode;
        } else {
            while (curNode->next != nullptr) {
                curNode = curNode->next;
            }

            newNode->prev = curNode;
            curNode->next = newNode;
        }
    }

    void insertNewNodeAtStart() {
        
    }

    void traverse() {
        Node* curNode = head;       
        while (curNode != nullptr) { 
            cout << curNode->data << " "; 
            curNode = curNode->next;   
        }
        cout << endl;               
    }
};

int main() {
    DoublyLinkedList* linkedList = new DoublyLinkedList();

    int nums[10] = {5, 7, 22, 1, 3, 9, 8, 11, 14, 18};
    int numsLength = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < numsLength; i++) {
        linkedList->insertNewNode(nums[i]);
    }

    linkedList->traverse();

    return 0;
}