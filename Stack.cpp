#include <iostream>

using namespace std;

// Define the maximum size of the stack
const int MAX_SIZE = 100;

class Stack {
private:
    // Array of type char since it will be used to reverse a char array
    char data[MAX_SIZE]; 
    int top;

public:

    Stack() {
        // -1 to show that it is empty
        top = -1;
    }

    // Add a value to the stack
    void push(char value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push more elements." << endl;
            return;
        }
        top++;
        data[top] = value;
    }

    // Function to pop an element from the stack
    char pop() {
        if (top < 0) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return '\0'; // Return null character if stack is empty
        }
        return data[top--]; // Return the top element and decrement top
    }
    
    // These functins are not nesseccary for Question 2, but i've included them anyways for completeness of the stack class implementation for funsies
    // Function to check if the stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Function to get the top element of the stack
    char peek() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
            return '\0'; // Return null character if stack is empty
        }
        return data[top];
    }
};

// Function to reverse a character array using our custom stack
void reverseCharArray(char word[], int n) {
    Stack st;

    // Push all characters of the array onto the stack
    for (int i = 0; i < n; i++) {
        st.push(word[i]);
    }

    // Pop all characters from the stack and place them back into the array
    for (int i = 0; i < n; i++) {
        word[i] = st.pop();
    }
}

int main() {
    char word[] = {'h', 'e', 'l', 'l', 'o'}; 
    int n = sizeof(word) / sizeof(word[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << word[i];
    }
    cout << endl;

    // Reverse the array using our stack class
    reverseCharArray(word, n);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << word[i];
    }
    cout << endl;

    return 0;
}