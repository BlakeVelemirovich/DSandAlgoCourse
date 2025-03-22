#include <iostream>
#include <climits>
using namespace std;

// Function to find the maximum element in an array using binary recursion
int findMax(int arr[], int low, int high) {
    // Base case: if there's only one element, return it
    if (low == high) {
        return arr[low];
    }
    
    // Find the middle index
    int mid = (low + high) / 2;
    
    // Recursively find the maximum in the left and right halves
    int leftMax = findMax(arr, low, mid);
    int rightMax = findMax(arr, mid + 1, high);
    
    // Return the maximum of the two halves
    return (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
    int arr[] = {3, 5, 1, 7, 9, 2, 8, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Maximum element in the array is: " << findMax(arr, 0, n - 1) << endl;
    return 0;
}
