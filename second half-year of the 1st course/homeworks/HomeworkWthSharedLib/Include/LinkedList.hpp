#pragma once
#include <bits/stdc++.h>
using namespace std;

class LinkedList {
private:
    struct Node {
        string data;
        Node* next;
        Node* prev;
        Node(const string& val);
    };

    Node* head;
    Node* tail;
    size_t nsize;

public:
    LinkedList();
    ~LinkedList();
    void push_back(const string& value);
    void push_front(const string& value);
    
    string pop_front();
    string pop_back();
    string pop(int index);
    
    string front() const;
    string back() const;
    int find(const string& value) const;
    
    void clear();
    bool empty() const;
    size_t size() const;
};