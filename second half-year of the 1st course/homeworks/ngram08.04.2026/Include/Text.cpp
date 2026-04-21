#include "Text.hpp"

Text::SentenceNode::SentenceNode(Sentence* s) {
    sentence = s;
    next = nullptr;
}

Text::Text() {
    head = nullptr;
    tail = nullptr;
}

Text::~Text() {
    clear();
}

void Text::addSentence(Sentence* sentence) {
    if (!sentence || sentence->empty()) {
        delete sentence;
        return;
    }

    SentenceNode* node = new SentenceNode(sentence);

    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void Text::clear() {
    while (head) {
        SentenceNode* tmp = head;
        head = head->next;
        delete tmp->sentence;
        delete tmp;
    }
    tail = nullptr;
}

void Text::print(std::ostream& out) const {
    int index = 1;
    for (SentenceNode* p = head; p != nullptr; p = p->next, ++index) {
        out << "Sentence " << index << ": ";
        p->sentence->print(out);
        out << '\n';
    }
}