#include <iostream>

int main() {
    int n;
    std::cout << "Please enter the size of the array: ";
    std::cin >> n;
    int* arr = new int[n];
    int* positiveArr = new int[n]; // Array to store positive elements
    int newSize = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (arr[i] >= 0) {
            positiveArr[newSize] = arr[i];
            newSize++;
        }
    }

    for (int i = 0; i < newSize; ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << positiveArr[i];
    }
    std::cout << std::endl;

    delete[] arr;
    delete[] positiveArr;
    return 0;
}
