#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Normal array
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array elements: ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // I am unable to add anything more to the array as it is full, and thus I need to make a new array if need to make more

    // Vector implementation
    vector<int> vector = {1, 2, 3, 4, 5};
    cout << "Vector elements: ";
    for (int i = 0; i < vector.size(); ++i) {
        cout << vector[i] << " ";
    }
    cout << endl;

    // I can easily add more elements to my vector, as it automatically will adjust it's size for me,
    // and handle the memory management without me doing anything.
    vector.push_back(6);
    vector.push_back(7);
    vector.push_back(8);
    vector.push_back(9);

    // Checking to see if the additions worked
    cout << "Vector elements: ";
    for (int i = 0; i < vector.size(); ++i) {
        cout << vector[i] << " ";
    }
    cout << endl;

    // Accessing elements
    cout << "Element at index 3: " << vector[3];

    return 0;
}