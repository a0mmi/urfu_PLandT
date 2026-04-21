#pragma once

#include <string>
#include <iostream>

using namespace std;

class Sentence {
public:
    struct WordNode {
        string word;
        WordNode* next;
        WordNode(const string& w);
    };

    WordNode* head;
    WordNode* tail;

    Sentence();
    ~Sentence();

    bool empty() const;
    void addWord(const string& w);
    void clearWords();
    void print(ostream& out) const;
};