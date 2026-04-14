#include "table.hpp"

CountNode::CountNode(const string& w) {
    word = w; cnt = 1; next = nullptr;
}

WordCounter::WordCounter() {
    head = nullptr;
}

WordCounter::~WordCounter() {
    clear();
}

void WordCounter::add(const string& word) {
    CountNode* cur = head;
    while (cur != nullptr) {
        if (cur->word == word) {
            cur->cnt++;
            return;
        }
        cur = cur->next;
    }

    CountNode* nn = new CountNode(word);
    nn->next = head;
    head = nn;
}

pair<string, int> WordCounter::best() const {
    string ans = "";
    int mx = -1;

    const CountNode* cur = head;
    while (cur != nullptr) {
        if (cur->cnt > mx || (cur->cnt == mx && (ans.empty() || cur->word < ans))) {
            mx = cur->cnt;
            ans = cur->word;
        }
        cur = cur->next;
    }

    return pair<string, int>(ans, mx);
}

void WordCounter::clear() {
    CountNode* cur = head;
    while (cur != nullptr) {
        CountNode* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = nullptr;
}

Entry::Entry(const string& k) {
    key = k; next = nullptr; used = false;
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
            cur->counts.add(nextWord);
            return;
        }
        cur = cur->next;
    }

    Entry* nn = new Entry(key);
    nn->counts.add(nextWord);
    nn->next = head;
    head = nn;
}

void table::print() {
    while (true) {
        Entry* best = nullptr;

        for (Entry* cur = head; cur != nullptr; cur = cur->next) {
            if (cur->used) continue;
            if (best == nullptr || cur->key < best->key) {
                best = cur;
            }
        }

        if (best == nullptr) break;

        best->used = true;
        pair<string, int> res = best->counts.best();
        cout << best->key << " -> " << res.first
             << " (frequency: " << res.second << ")\n";
    }

    for (Entry* cur = head; cur != nullptr; cur = cur->next) {
        cur->used = false;
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