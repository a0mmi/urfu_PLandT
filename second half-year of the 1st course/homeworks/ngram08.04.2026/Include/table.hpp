#pragma once

#include <bits/stdc++.h>

using namespace std;

struct BestContinuation {
    string word;
    int count;

    BestContinuation();
    BestContinuation(const string& w, int c);
};

struct Entry {
    string key;
    BestContinuation best;
    Entry* next;

    Entry(const string& k);
};

class table {
private:
    Entry* head;

public:
    table();
    ~table();

    void add(const string& key, const string& nextWord);
    void print();
    void clear();
};