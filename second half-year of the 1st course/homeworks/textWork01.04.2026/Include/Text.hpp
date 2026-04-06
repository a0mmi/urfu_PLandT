#pragma once

#include "Sentence.hpp"

class Text {
private:
    struct SentenceNode {
        Sentence* sentence;
        SentenceNode* next;

        SentenceNode(Sentence* s);
    };

    SentenceNode* head;
    SentenceNode* tail;

public:
    Text();
    ~Text();

    void addSentence(Sentence* sentence);
    void clear();
    void print(std::ostream& out) const;
};
