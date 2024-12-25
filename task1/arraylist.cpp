#include "arraylist.h"

ArrayList::ArrayList() = default;

ArrayList::ArrayList(const ArrayList& other) : arr(other.arr) {}

ArrayList& ArrayList::operator=(const ArrayList& other) {
    if (this != &other) {
        arr = other.arr;
    }
    return *this;
}

void ArrayList::AddFront(int value) {
    arr.insert(arr.begin(), value);
}

void ArrayList::AddBack(int value) {
    arr.push_back(value);
}

void ArrayList::AddAt(int index, int value) {
    if (index >= 0 && index <= arr.size())
    {
        arr.insert(arr.begin() + index, value);
    }
}

void ArrayList::RemoveFront() {
    if (!arr.empty()) 
    {
        arr.erase(arr.begin());
    }
}

void ArrayList::RemoveBack() {
    if (!arr.empty()) {
        arr.pop_back();
    }
}

void ArrayList::RemoveAt(int index) {
    if (index >= 0 && index < arr.size()) 
    {
        arr.erase(arr.begin() + index);
    }
}

void ArrayList::Swap(int index1, int index2) {
    if (index1 >= 0 && index1 < arr.size() && index2 >= 0 && index2 < arr.size())
    {
        std::swap(arr[index1], arr[index2]);
    }
}

void ArrayList::Print() const {
    for (int val : arr){
    std::cout << val << " ";
    std::cout << std::endl;
    }
}