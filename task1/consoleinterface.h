#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "list.h"

class ConsoleInterface {
public:
    static void Run(List& list);  
private:
    static void DisplayMenu();    
    static void HandleChoice(int choice, List& list);  
};

#endif
