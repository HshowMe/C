#include <iostream>

int main() {
    int n;
    std::cout << "Please enter the size of the array: ";
    std::cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int minIndex = 0, maxIndex = 0;
    int minValue = arr[0], maxValue = arr[0];

    // Find the first maximum element
    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }

    // Find the last minimum element
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
    }

    // Swap the first maximum and last minimum elements
    std::swap(arr[minIndex], arr[maxIndex]);

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << arr[i];
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
