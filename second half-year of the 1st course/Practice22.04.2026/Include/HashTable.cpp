#include "HashTable.hpp"
#include <cctype>

HashTable::Node::Node(char k, int c) {
    key = k; count = c; next = nullptr;
}

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    clear();
}

int HashTable::hash(char c) const {
    return (unsigned char)(c) % TABLE_SIZE;
}

void HashTable::insert(char c) {
    char lower = std::tolower((unsigned char)c);
    int h = hash(lower);

    Node* cur = table[h];
    while (cur != nullptr) {
        if (cur->key == lower) {
            cur->count++;
            return;
        }
        cur = cur->next;
    }

    Node* nn = new Node(lower, 1);
    nn->next = table[h];
    table[h] = nn;
}

int HashTable::getCount(char c) {
    char lower = std::tolower((unsigned char)c);
    int h = hash(lower);

    Node* cur = table[h];
    while (cur != nullptr) {
        if (cur->key == lower) {
            return cur->count;
        }
        cur = cur->next;
    }
    return 0;
}

void HashTable::clear() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* cur = table[i];
        while (cur != nullptr) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        table[i] = nullptr;
    }
}