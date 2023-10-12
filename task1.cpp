#include <iostream>


int main() {
    int n;
    std::cout << "Please enter the size of the array: ";
    std::cin >> n;
    int* arr = new int[n];
    int count = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (arr[i] > 0) {
            count++;
        }
    }

    std::cout << count << std::endl;

    delete[] arr; // Memory cleanup
    return 0;
}
