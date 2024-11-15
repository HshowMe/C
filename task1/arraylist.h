#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"
#include <vector>
#include <iostream>

class ArrayList : public List {
private:
    std::vector<int> arr;
public:
    ArrayList();                         
    ArrayList(const ArrayList& other);   
    ArrayList& operator=(const ArrayList& other);
    void AddFront(int value) override;
    void AddBack(int value) override;
    void AddAt(int index, int value) override;
    void RemoveFront() override;
    void RemoveBack() override;
    void RemoveAt(int index) override;
    void Swap(int index1, int index2) override;
    void Print() const override;
};

#endif
