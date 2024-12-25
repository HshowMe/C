#include <iostream>
#include "consoleinterface.h"
#include "list.h"
#include "arraylist.h"
#include "linkedlist.h"

void DisplayListTypeMenu() {
    std::cout << "Choose list type:\n"
              << "1. ArrayList\n"
              << "2. LinkedList\n"
              << "0. Exit\n"
              << "Enter choice: ";
}

List* CreateList(int choice) {
    if (choice == 1) {
        return new ArrayList();
    } else if (choice == 2) {
        return new LinkedList();
    }
    return nullptr;
}

void HandleListChoice(int choice) {
    List* list = CreateList(choice);
    if (list) {
        ConsoleInterface consoleInterface;
        consoleInterface.Run(*list);     
    }
}

void ProcessChoice(int choice) {
    if (choice == 1 || choice == 2) {
        HandleListChoice(choice);
    } else if (choice != 0) {
        std::cout << "Invalid choice.\n";
    }
}

void RunProgram() {
    int choice = 0;
    do {
        DisplayListTypeMenu();
        std::cin >> choice;
        ProcessChoice(choice);
    } while (choice != 0);
}

int main(int argc, char* argv[]){
    RunProgram();
    return 0;
}
