#include <iostream>

using namespace std;

int main() {
    char myCharArray[10] = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};
    
    int leftPointer = 0;
    int rightPointer = size(myCharArray) - 1;
    
    char reversedArray[10];
    char temp;
    
    while (leftPointer < rightPointer) {
        temp = reversedArray[leftPointer];
        reversedArray[leftPointer] = myCharArray[rightPointer];
        reversedArray[rightPointer] = myCharArray[leftPointer];
        leftPointer++;
        rightPointer--;
    }
    
    cout << reversedArray;
    
    return 0;
}
