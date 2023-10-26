#include <iostream>

int main() {
    int n;
    std::cout << "Please enter the size of the array: ";
    std::cin >> n;
    int* arr = new int[n];
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        sum += arr[i];
    }

    std::cout << sum << std::endl;

    delete[] arr;
    return 0;
}
