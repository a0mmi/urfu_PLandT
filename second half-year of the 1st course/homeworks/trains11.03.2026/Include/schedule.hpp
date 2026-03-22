#pragma once

#include <bits/stdc++.h>
#include "train.hpp"

using namespace std;

class schedule {
private:
    struct Node {
        train data;
        Node* next;
        Node(const train& t);
    };

    Node* head;
    size_t sz;

    void insertSorted(const train& t);

public:
    schedule();
    schedule(const train& t);
    schedule(const schedule& other);
    schedule& operator=(const schedule& other);
    ~schedule();
    
    schedule& operator+=(const schedule& other);

    friend schedule operator+(schedule a, const schedule& b);

    // Первая строка — количество N
    // Затем N строк вида: number|City|HH:MM
    friend istream& operator>>(istream& in, schedule& s);
    friend ostream& operator<<(ostream& out, const schedule& s);

    size_t size() const { return sz; }
    bool empty() const { return head == nullptr; }
};