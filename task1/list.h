#ifndef LIST_H
#define LIST_H

class List {
public:
    virtual ~List() {}
    virtual void AddFront(int value) = 0;
    virtual void AddBack(int value) = 0;
    virtual void AddAt(int index, int value) = 0;
    virtual void RemoveFront() = 0;
    virtual void RemoveBack() = 0;
    virtual void RemoveAt(int index) = 0;
    virtual void Swap(int index1, int index2) = 0;
    virtual void Print() const = 0;
};

#endif
