#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int left, int right) {
    // Base case: when left equals right, the string is a palindrome because if we reach the end without termination every character equals the others
    if (left >= right) {
        return true;
    }
    // If characters at left and right positions don't match, it's not a palindrome
    if (str[left] != str[right]) {
        return false;
    }
    // Recursively check the substring by providing the next value on the left side (left + 1) and the next value on the right side (right - 1) as arguments
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    string input;
    cout << "Enter a word (no spaces): ";
    cin >> input;

    if (isPalindrome(input, 0, input.length() - 1)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}
