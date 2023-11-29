#include <iostream>

void moveDisk(int disk, int fromRod, int toRod) {
    std::cout << disk << " " << fromRod << " " << toRod << std::endl;
}

void hanoi(int n, int source, int aux, int destination) {
    if (n == 1) {
        moveDisk(1, source, destination);
        return;
    }

    hanoi(n - 1, source, destination, aux);
    moveDisk(n, source, destination);
    hanoi(n - 1, aux, source, destination);
}

int main() {
    int n;
    std::cin >> n;

    int rod1[10]; 
    for (int i = 0; i < n; ++i) {
        std::cin >> rod1[i];
    }

    int rod2 = 2, rod3 = 3;

    for (int i = n - 1; i >= 0; --i) {
        if (rod1[i] != 1) {
            moveDisk(rod1[i], 1, rod2);
            moveDisk(1, 1, rod3);
            moveDisk(rod1[i], rod2, rod3);
        }
        else {
            moveDisk(1, 1, rod2);
            moveDisk(1, 1, rod3);
        }
    }

    hanoi(n, rod2, 1, rod3);

    return 0;
}
