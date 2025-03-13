// Blake Velemirovich

#include <iostream>

using namespace std;

// Node structures
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue function
    void enqueue(int val) {
        Node* newNode = new Node(val);
        // Check if there are values in the queue becuase we need to keep track of the front and back values
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue function
    void dequeue() {
        // ERror checking to see if the queeue is empty
        if (front == nullptr) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        // Temp value because need to make sure that we keep track of the front and rear values without changing them
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Peek function
    int peek() {
        // If there is a nullptr at front it's empty
        if (front == nullptr) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function to test the queue
int main() {
    // Print Job Elements from the quizz page
    int printJobs[6] = {1, 2, 3, 4, 5, 6};

    Queue q;
    
    // Iterate through print jobs and insert into the back of queue
    for (int i = 0; i < sizeof(printJobs) / sizeof(printJobs[0]); i++) {
        q.enqueue(printJobs[i]);
    }

    // Remove from front of the queue to siulate the print job order
    for (int i = 0; i < sizeof(printJobs) / sizeof(printJobs[0]); i++) {
        // Retrieve the value from the front of the queue
        cout << "Print Job Id sent to printer: " << q.peek() << endl;
        // Remove the value from the front of the queue
        q.dequeue();
    }

    // Demonstrate values were totally removed with deqeuue
    if (q.isEmpty()) cout << "Queue is empty";
    else cout << "Queue is not empty";
    
    return 0;
}