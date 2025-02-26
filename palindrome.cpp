#include <iostream>
#include <deque>
#include <string>
using namespace std;

/*
I decided to use a deque over a queue because it's just a lot more natural and makes way more sense to use a 
deque in this situation. Think about how a palindrome works, it needs to read the same way from both ends,
so we must compare each sides of the word together and see if they are the same. If they are the same, then
we can remove those letters, and then do a comparison from each side of the word of the remaining letters, until
it is completed. A deque allows us to add letters to it, and then compare from each side of the deque, and then
remove values from either side. This fits our use case perfectly. A queue on the other hand would not be as good
because we are only able to add a letter to the back so that it pops out at the front. 

It's just more intuitive to use the deque in this situation as it matches perfectly with our usecase.
*/

bool isPalindrome(const string& str) {
    // Create a deque to store characters of the string
    deque<char> charDeque;

    // Add each character of the string to the deque
    for (char ch : str) {
        charDeque.push_back(ch);
    }

    // Compare characters from the front and back of the deque
    // If they are not the same then obviously it's not a palindrome
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