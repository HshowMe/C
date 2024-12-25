#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "list.h"
#include <functional>
#include <vector>

class ConsoleInterface {
public:
    void Run(List& list);
    ConsoleInterface();

private:
    void DisplayMenu();
    void HandleChoice(int choice, List& list);
    
    using OperationFunction = std::function<void(List&)>;
    std::vector<OperationFunction> operationFunctions;

    void addToFront(List& list);
    void addToBack(List& list);
    void addAtIndex(List& list);
    void removeFromFront(List& list);
    void removeFromBack(List& list);
    void removeAtIndex(List& list);
    void swapElements(List& list);
    void printList(List& list);
};

#endif
