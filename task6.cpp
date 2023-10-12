#include <iostream>

int main() {
    int n;
    std::cout << "Please enter the size of the array: ";
    std::cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    for (int i = 0; i < n - 1; i += 2) { // Loop through the array to swap elements with odd indexes (1, 3, 5,.....) with even indexes (0, 2, 4,.....)
        std::swap(arr[i], arr[i + 1]);
    }

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