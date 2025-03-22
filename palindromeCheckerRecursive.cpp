#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int left, int right) {
    // Base case: when left >= right, the string is a palindrome
    if (left >= right) {
        return true;
    }
    // If characters at left and right positions don't match, it's not a palindrome
    if (str[left] != str[right]) {
        return false;
    }
    // Recursively check the substring between left+1 and right-1
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input, 0, input.length() - 1)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}
