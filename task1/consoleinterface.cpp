#include "consoleinterface.h"
#include <iostream>

void ConsoleInterface::Run(List& list) {
    int choice;
    do {
        DisplayMenu();
        std::cin >> choice;
        HandleChoice(choice, list);
    } while (choice != 0);
}

void ConsoleInterface::DisplayMenu() {  
    std::cout << "Menu:\n"
              << "1. Add to front\n"
              << "2. Add to back\n"
              << "3. Add at index\n"
              << "4. Remove from front\n"
              << "5. Remove from back\n"
              << "6. Remove at index\n"
              << "7. Swap elements\n"
              << "8. Print list\n"
              << "0. Exit\n"
              << "Enter choice: ";
}

void ConsoleInterface::HandleChoice(int choice, List& list) {
    int value, index1, index2;
    switch (choice) {
        case 1: std::cout << "Enter value: "; std::cin >> value; list.AddFront(value); break;
        case 2: std::cout << "Enter value: "; std::cin >> value; list.AddBack(value); break;
        case 3: std::cout << "Enter index and value: "; std::cin >> index1 >> value; list.AddAt(index1, value); break;
        case 4: list.RemoveFront(); break;
        case 5: list.RemoveBack(); break;
        case 6: std::cout << "Enter index: "; std::cin >> index1; list.RemoveAt(index1); break;
        case 7: std::cout << "Enter two indices: "; std::cin >> index1 >> index2; list.Swap(index1, index2); break;
        case 8: list.Print(); break;
    }
}
