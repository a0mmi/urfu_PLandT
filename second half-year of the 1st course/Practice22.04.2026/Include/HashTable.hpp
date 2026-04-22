#pragma once

#include <string>

class HashTable {
private:
    struct Node {
        char key;
        int count;
        Node* next;

        Node(char k, int c = 0);
    };

    static const int TABLE_SIZE = 128;
    Node* table[TABLE_SIZE];

    int hash(char c) const;

public:
    HashTable();
    ~HashTable();

    void insert(char c);
    int getCount(char c) ;
    void clear();
};