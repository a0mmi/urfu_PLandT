#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

Node::Node(const string& val) {
    data = val; next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr; tail = nullptr;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push_back(const string& value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
}

Node* LinkedList::getHead() {
    return head;
}

bool LinkedList::empty() {
    return head == nullptr;
}