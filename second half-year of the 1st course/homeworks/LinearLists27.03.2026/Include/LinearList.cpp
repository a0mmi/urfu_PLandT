#include <bits/stdc++.h>
#include "LinearList.hpp"

LinearList::LinearList() : head(nullptr), tail(nullptr), size(0) {}

LinearList::~LinearList() {
    destroy();
}

void LinearList::destroy() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}

void LinearList::add(const string& word) {
    Node* newNode = new Node{word, 0, head, nullptr};
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
    size++;
}

istream& operator>>(istream& is, LinearList& list) {
    string word;
    if (is >> word) {
        list.add(word);
    }
    return is;
}

void LinearList::loadReserved(istream& in) {
    while (in >> *this) {}
}

void LinearList::countInText(istream& in) {
    string word;
    while (in >> word) {
        Node* current = head;
        while (current) {
            if (current->word == word) {
                current->count++;
            }
            current = current->next;
        }
    }
}

LinearList::Node* LinearList::mergesort(Node* head) {
    if (!head || !head->next) {
        if (head) head->prev = nullptr;
        return head;
    }

    // середина
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow;
    Node* rightHead = mid->next;

    // деление списка
    mid->next = nullptr;
    if (rightHead) rightHead->prev = nullptr;

    Node* left = mergesort(head);
    Node* right = mergesort(rightHead);

    return merge(left, right);
}

LinearList::Node* LinearList::merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;
    Node* current = nullptr;

    // Первый элемент
    if (left->count > right->count || 
        (left->count == right->count && left->word < right->word)) {
        result = left;
        left = left->next;
    } else {
        result = right;
        right = right->next;
    }
    result->prev = nullptr;
    current = result;

    while (left && right) {
        Node* nextNode;
        if (left->count > right->count || 
            (left->count == right->count && left->word < right->word)) {
            nextNode = left;
            left = left->next;
        } else {
            nextNode = right;
            right = right->next;
        }
        current->next = nextNode;
        nextNode->prev = current;
        current = nextNode;
    }

    // Оставшееся часть
    if (left) {
        current->next = left;
        left->prev = current;
    } else if (right) {
        current->next = right;
        right->prev = current;
    }

    return result;
}

void LinearList::sort() {
    if (size <= 1) return;
    head = mergesort(head);

    // tail после сортировки
    if (head) {
        head->prev = nullptr;
        tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
    } else {
        tail = nullptr;
    }
}

int LinearList::getSize() const {
    return size;
}

string LinearList::getWord(int index) const {
    if (index < 0 || index >= size) return "";
    
    int distHead = index;
    int distTail = size - 1 - index;
    
    if (distHead <= distTail) {
        // от начала (head)
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->word;
    } else {
        // от конца (tail)
        Node* current = tail;
        int steps = size - 1 - index;
        for (int i = 0; i < steps; i++) {
            current = current->prev;
        }
        return current->word;
    }
}

int LinearList::getCount(int index) const {
    if (index < 0 || index >= size) return 0;
    
    int distHead = index;
    int distTail = size - 1 - index;
    
    if (distHead <= distTail) {
        // от начала (head)
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->count;
    } else {
        // от конца (tail)
        Node* current = tail;
        int steps = size - 1 - index;
        for (int i = 0; i < steps; i++) {
            current = current->prev;
        }
        return current->count;
    }
}