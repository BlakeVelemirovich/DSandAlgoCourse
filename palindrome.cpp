#include <iostream>
#include <deque>    // Include the deque library
#include <string>   // Include the string library for input handling
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    // Create a deque to store characters of the string
    deque<char> charDeque;

    // Add each character of the string to the deque
    for (char ch : str) {
        charDeque.push_back(ch);
    }

    // Compare characters from the front and back of the deque
    while (charDeque.size() > 1) {
        // Get the front character
        char frontChar = charDeque.front();
        // Get the back character
        char backChar = charDeque.back();

        // If the characters don't match, it's not a palindrome
        if (frontChar != backChar) {
            return false;
        }

        // Remove the front and back characters
        charDeque.pop_front();
        charDeque.pop_back();
    }

    // If all characters matched, it's a palindrome
    return true;
}

int main() {
    // Ask the user to enter a string
    string input;
    cout << "Enter a string (lowercase letters only): ";
    cin >> input;

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}