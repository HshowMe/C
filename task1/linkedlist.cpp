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
        while (head){
            RemoveFront();
        }
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
    while (current && index--) {
        current = current->next;
    }
    return current;
}

void LinkedList::AddFront(int value) {
    head = new Node(value, head);
}

void LinkedList::AddBack(int value) {
    if (!head) return AddFront(value);
    Node* tail = head;
    while (tail->next) { 
        tail = tail->next;
    }
    tail->next = new Node(value);
}

void LinkedList::AddAt(int index, int value) {
    if (index == 0){
        return AddFront(value);
    }
    Node* prev = GetNodeAt(index - 1);
    if (prev) {
        prev->next = new Node(value, prev->next);
    }
}

void LinkedList::RemoveFront() {
    RemoveAt(0);
}


void LinkedList::RemoveBack() {
    if (!head) {
        return;
    }
    if (!head->next) { 
        RemoveFront();
        return;
    }

    Node* prev = head;
    while (prev->next->next) { 
        prev = prev->next;
    }
    delete prev->next;
    prev->next = nullptr;
}


void LinkedList::RemoveAt(int index) {
    {
  Node* node = ExtractNode(index);
  if (node)
  {
    delete node;
  }
  else
  {
    std::cout << "Invalid index.\n";
  }
}

}

Node* LinkedList::ExtractNode(int index) {
    if (index < 0 || !head) {
        return nullptr;
    }

    Node* extracted = nullptr;
    if (index == 0) {
        extracted = head;
        head = head->next;
        extracted->next = nullptr;
    } else {
        Node* prev = GetNodeAt(index - 1);
        if (prev && prev->next) {
            extracted = prev->next;
            prev->next = extracted->next;
            extracted->next = nullptr;
        }
    }
    return extracted;
}

void LinkedList::InsertNode(Node* node, int index) {
    if (!node) {
        return;
    }

    if (index == 0) {
        node->next = head;
        head = node;
    } else {
        Node* prev = GetNodeAt(index - 1);
        if (prev) {
            node->next = prev->next;
            prev->next = node;
        }
    }
}


void LinkedList::Swap(int index1, int index2) {
    if (index1 > index2) {
        return Swap(index2, index1);
    }
    if (index1 == index2) {
        return;
    }

    Node* node2 = ExtractNode(index2);
    Node* node1 = ExtractNode(index1);
    if (node1 && node2) {
        InsertNode(node2, index1);
        InsertNode(node1, index2);
    } else {
        std::cout << "Invalid indices.\n";
    }
}


void LinkedList::Print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
