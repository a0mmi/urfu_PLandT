#pragma once
#include <bits/stdc++.h>
using namespace std;

struct CountNode {
    string word;
    int cnt;
    CountNode* next;

    CountNode(const string& w);
};

class WordCounter {
private:
    CountNode* head;

public:
    WordCounter();
    ~WordCounter();

    void add(const string& word);
    pair<string, int> best() const;
    void clear();
};

struct Entry {
    string key;
    WordCounter counts;
    Entry* next;
    bool used;

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