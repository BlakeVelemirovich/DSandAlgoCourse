#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    // Start from the second element
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift the element to the right if it is smaller than the current element, keeping doing this while elements are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  
            j--;
        }
        
        // Insert the key element at its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform Insertion Sort
    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
