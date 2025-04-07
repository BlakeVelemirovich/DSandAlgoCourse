#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    // Iterate through all the elements
    for (int i = 0; i < n - 1; i++) {
        // Initially set the current smallest index to the first element
        int minIndex = i;
        
        // Inner loop to search through all elements except the first one to compare them
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                // We have found a new minimum element
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Traversal function
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    cout << "Original array: ";
    printArray(arr, n);

    // Execute the Selection Sort
    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
