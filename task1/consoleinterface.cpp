#include "consoleinterface.h"
#include <iostream>

ConsoleInterface::ConsoleInterface() {
    operationFunctions = {
        [this](List& list) { addToFront(list); },
        [this](List& list) { addToBack(list); },
        [this](List& list) { addAtIndex(list); },
        [this](List& list) { removeFromFront(list); },
        [this](List& list) { removeFromBack(list); },
        [this](List& list) { removeAtIndex(list); },
        [this](List& list) { swapElements(list); },
        [this](List& list) { printList(list); }
    };
}

void ConsoleInterface::Run(List& list) {
    int choice = 0;
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
    if (choice > 0 && choice <= operationFunctions.size()) {
        operationFunctions[choice - 1](list);
    }
}

void ConsoleInterface::addToFront(List& list) {
    int value = 0;
    std::cout << "Enter value: ";
    std::cin >> value;
    list.AddFront(value);
}

void ConsoleInterface::addToBack(List& list) {
    int value = 0;
    std::cout << "Enter value: ";
    std::cin >> value;
    list.AddBack(value);
}

void ConsoleInterface::addAtIndex(List& list) {
    int index = 0, value = 0;
    std::cout << "Enter index and value: ";
    std::cin >> index >> value;
    list.AddAt(index, value);
}

void ConsoleInterface::removeFromFront(List& list) {
    list.RemoveFront();
}

void ConsoleInterface::removeFromBack(List& list) {
    list.RemoveBack();
}

void ConsoleInterface::removeAtIndex(List& list) {
    int index = 0;
    std::cout << "Enter index: ";
    std::cin >> index;
    list.RemoveAt(index);
}

void ConsoleInterface::swapElements(List& list) {
    int index1 = 0, index2 = 0;
    std::cout << "Enter two indices: ";
    std::cin >> index1 >> index2;
    list.Swap(index1, index2);
}

void ConsoleInterface::printList(List& list) {
    list.Print();
}
