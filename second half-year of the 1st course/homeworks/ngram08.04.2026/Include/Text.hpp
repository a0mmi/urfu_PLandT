#pragma once

#include "Sentence.hpp"

class Text {
public:
    struct SentenceNode {
        Sentence* sentence;
        SentenceNode* next;

        SentenceNode(Sentence* s);
    };

    SentenceNode* head;
    SentenceNode* tail;

    Text();
    ~Text();

    void addSentence(Sentence* sentence);
    void clear();
    void print(std::ostream& out) const;
};