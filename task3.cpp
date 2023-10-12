#include <iostream>

int main() {
    int n;
    std::cout << "Please enter the size of the array: ";
    std::cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n / 2; ++i) {
        std::swap(arr[i], arr[n - i - 1]);
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
