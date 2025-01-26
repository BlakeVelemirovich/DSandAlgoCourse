#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<char> findDuplicates(const char arr[], int size) {
    std::unordered_map<char, int> charCount; 
    std::vector<char> duplicates; 

    // Count occurrences of each character
    for (int i = 0; i < size; ++i) {
        charCount[arr[i]]++;
    }

    // Find characters with count > 1
    for (const auto& pair : charCount) {
        if (pair.second > 1) {
            duplicates.push_back(pair.first);
        }
    }

    return duplicates;
}

int main() {
    char arr[12] = {'D', 'A', 'C', 'E', 'A', 'F', 'G', 'D', 'H', 'I', 'J', 'F'};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::vector<char> duplicates = findDuplicates(arr, size);

    std::cout << "Duplicates in the array: ";
    for (char c : duplicates) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}