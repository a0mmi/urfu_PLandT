#pragma once
#include <bits/stdc++.h>

using namespace std;

class LinearList {
private:
    struct Node { // Двусвязный
        string word;
        int count;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    int size;

    void add(const string& word); // В начало
    void destroy();

    Node* mergesort(Node* head);
    Node* merge(Node* left, Node* right);

public:
    LinearList();
    ~LinearList();

    // Работа только с потоками
    void loadReserved(istream& in);
    void countInText(istream& in);

    void sort();

    int getSize() const;
    string getWord(int index) const;
    int getCount(int index) const;

    friend istream& operator>>(istream& is, LinearList& list);
};