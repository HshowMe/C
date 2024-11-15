#include "linkedlist.h"

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(const LinkedList& other) : head(nullptr) {
    Node* current = other.head;
    while (current) {
        AddBack(current->data);
        current = current->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        while (head) RemoveFront();
        Node* current = other.head;
        while (current) {
            AddBack(current->data);
            current = current->next;
        }
    }
    return *this;
}
Node* LinkedList::GetNodeAt(int index) const {
    Node* current = head;
    while (current && index--) current = current->next;
    return current;
}

void LinkedList::AddFront(int value) {
    head = new Node(value, head);
}

void LinkedList::AddBack(int value) {
    if (!head) return AddFront(value);
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = new Node(value);
}

void LinkedList::AddAt(int index, int value) {
    if (index == 0) return AddFront(value);
    Node* prev = GetNodeAt(index - 1);
    if (prev) prev->next = new Node(value, prev->next);
}

void LinkedList::RemoveFront() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::RemoveBack() {
    if (!head) return;
    if (!head->next) return RemoveFront();
    Node* prev = head;
    while (prev->next->next) prev = prev->next;
    delete prev->next;
    prev->next = nullptr;
}

void LinkedList::RemoveAt(int index) {
    if (index == 0) return RemoveFront();
    Node* prev = GetNodeAt(index - 1);
    if (prev && prev->next) {
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
}

void LinkedList::Swap(int index1, int index2) {
    if (index1 == index2) return;
    Node* node1 = GetNodeAt(index1);
    Node* node2 = GetNodeAt(index2);
    if (node1 && node2) std::swap(node1->data, node2->data);
}

void LinkedList::Print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
