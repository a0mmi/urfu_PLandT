#include "table.hpp"

BestContinuation::BestContinuation() {
    word = "";
    count = 0;
}

BestContinuation::BestContinuation(const string& w, int c) {
    word = w;
    count = c;
}

Entry::Entry(const string& k) {
    key = k;
    best.word = "";
    best.count = 0;
    next = nullptr;
}

table::table() {
    head = nullptr;
}

table::~table() {
    clear();
}

void table::add(const string& key, const string& nextWord) {
    Entry* cur = head;
    while (cur != nullptr) {
        if (cur->key == key) {
            if (nextWord == cur->best.word) {
                cur->best.count++;
            } else if (cur->best.count <= 1 && (cur->best.word.empty() || nextWord < cur->best.word)) {
                cur->best.word = nextWord;
                cur->best.count = 1;
            }
            return;
        }
        cur = cur->next;
    }

    Entry* nn = new Entry(key);
    nn->best.word = nextWord;
    nn->best.count = 1;
    nn->next = head;
    head = nn;
}

void table::print() {
    Entry* cur = head;
    while (cur != nullptr) {
        cout << cur->key << " -> " << cur->best.word
             << " (frequency: " << cur->best.count << ")\n";
        cur = cur->next;
    }
}

void table::clear() {
    Entry* cur = head;
    while (cur != nullptr) {
        Entry* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = nullptr;
}