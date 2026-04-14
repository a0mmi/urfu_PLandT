#pragma once

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(const string& val);
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList();
    ~LinkedList();
    void push_back(const string& value);
    void clear();
    Node* getHead();
    bool empty();
};