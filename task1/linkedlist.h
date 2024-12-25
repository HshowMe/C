#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "list.h"
#include <iostream>

struct Node {
    int data = 0;
    Node* next;
    Node(int value, Node* next = nullptr) : data(value), next(next) {}
};

class LinkedList : public List {
private:
    Node* head = nullptr;
    Node* GetNodeAt(int index) const;
public:
    LinkedList();                         
    LinkedList(const LinkedList& other);  
    LinkedList& operator=(const LinkedList& other); 
    ~LinkedList();
    void AddFront(int value) override;
    void AddBack(int value) override;
    void AddAt(int index, int value) override;
    void RemoveFront() override;
    void RemoveBack() override;
    void RemoveAt(int index) override;
    void Swap(int index1, int index2) override;
    void Print() const override;
    Node* ExtractNode(int index);
    void InsertNode(Node* node, int index);

};

#endif
