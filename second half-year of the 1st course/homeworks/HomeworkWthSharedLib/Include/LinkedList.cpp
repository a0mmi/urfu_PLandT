#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

LinkedList::Node::Node(const string& val) {
    data = val; next = nullptr; prev = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr; tail = nullptr; nsize = 0;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push_back(const string& value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    nsize++;
}

void LinkedList::push_front(const string& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    nsize++;
}

string LinkedList::pop_front() {
    if (empty()) throw out_of_range("pop_front on empty list");
    Node* toRemove = head;
    string data = toRemove->data;
    
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    
    delete toRemove;
    nsize--;
    return data;
}

string LinkedList::pop_back() {
    if (empty()) throw out_of_range("pop_back on empty list");
    Node* toRemove = tail;
    string data = toRemove->data;
    
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    
    delete toRemove;
    nsize--;
    return data;
}

string LinkedList::pop(int index) {
    if (index < 0 || index >= nsize) 
        throw out_of_range("pop index out of range");
    
    if (index == 0) return pop_front();
    if (index == nsize - 1) return pop_back();

    Node* nodeToRemove;
    if (index <= nsize / 2) {
        nodeToRemove = head;
        for (int i = 0; i < index; i++) 
            nodeToRemove = nodeToRemove->next;
    } else {
        nodeToRemove = tail;
        for (int i = nsize - 1; i > index; i--) 
            nodeToRemove = nodeToRemove->prev;
    }

    // Unlink and remove
    nodeToRemove->prev->next = nodeToRemove->next;
    nodeToRemove->next->prev = nodeToRemove->prev;
    
    string data = nodeToRemove->data;
    delete nodeToRemove;
    nsize--;
    return data;
}

string LinkedList::front() const {
    if (empty()) throw out_of_range("front on empty list");
    return head->data;
}

string LinkedList::back() const {
    if (empty()) throw out_of_range("back on empty list");
    return tail->data;
}

int LinkedList::find(const string& value) const {
    Node* current = head;
    int index = 0;
    while (current) {
        if (current->data == value) 
            return index;
        current = current->next;
        index++;
    }
    return -1;
}

void LinkedList::clear() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
    nsize = 0;
}

bool LinkedList::empty() const {
    return size == 0;
}

size_t LinkedList::size() const {
    return nsize;
}