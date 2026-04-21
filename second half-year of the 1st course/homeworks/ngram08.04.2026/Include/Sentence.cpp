#include "Sentence.hpp"

Sentence::WordNode::WordNode(const string& w) {
    word = w;
    next = nullptr;
}

Sentence::Sentence() {
    head = nullptr;
    tail = nullptr;
}

Sentence::~Sentence() {
    clearWords();
}

bool Sentence::empty() const {
    return head == nullptr;
}

void Sentence::addWord(const string& w) {
    WordNode* node = new WordNode(w);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void Sentence::clearWords() {
    while (head) {
        WordNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
}

void Sentence::print(ostream& out) const {
    out << "[";
    for (WordNode* p = head; p != nullptr; p = p->next) {
        out << p->word;
        if (p->next) out << ", ";
    }
    out << "]";
}