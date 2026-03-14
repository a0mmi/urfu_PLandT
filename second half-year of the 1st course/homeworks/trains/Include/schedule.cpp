#include <bits/stdc++.h>
#include "schedule.hpp"

using namespace std;

string trim_str_local(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    if (st == string::npos) return string();
    size_t ed = s.find_last_not_of(" \t\r\n");
    return s.substr(st, ed - st + 1);
}

schedule::Node::Node(const train& t) {
    data = t;
    next = nullptr;
}

static int compare_trains(const train& a, const train& b) {
    const string& A = a.getCity();
    const string& B = b.getCity();
    if (A < B) return -1;
    if (A > B) return 1;
    if (a.getTime() < b.getTime()) return -1;
    if (a.getTime() > b.getTime()) return 1;
    return 0;
}

schedule::schedule() {
    head = nullptr;
    sz = 0;
}

schedule::schedule(const train& t) {
    head = nullptr;
    sz = 0;
    Node* n = new Node(t);
    head = n;
    sz = 1;
}

schedule::schedule(const schedule& other) {
    head = nullptr;
    sz = 0;
    if (!other.head) return;
    Node* cur = other.head;
    Node* tail = nullptr;
    while (cur) {
        Node* n = new Node(cur->data);
        if (!head) head = n;
        else tail->next = n;
        tail = n;
        cur = cur->next;
        ++sz;
    }
}

schedule& schedule::operator=(const schedule& other) {
    if (this == &other) return *this;
    // очистка текущего списка
    Node* cur = head;
    while (cur) {
        Node* nx = cur->next;
        delete cur;
        cur = nx;
    }
    head = nullptr;
    sz = 0;
    // копирование
    Node* cur2 = other.head;
    Node* tail = nullptr;
    while (cur2) {
        Node* n = new Node(cur2->data);
        if (!head) head = n;
        else tail->next = n;
        tail = n;
        cur2 = cur2->next;
        ++sz;
    }
    return *this;
}

schedule::~schedule() {
    Node* cur = head;
    while (cur) {
        Node* nx = cur->next;
        delete cur;
        cur = nx;
    }
    head = nullptr;
    sz = 0;
}

void schedule::insertSorted(const train& t) {
    Node* n = new Node(t);
    if (!head || compare_trains(n->data, head->data) < 0) {
        n->next = head;
        head = n;
        ++sz;
        return;
    }
    Node* cur = head;
    while (cur->next && compare_trains(cur->next->data, n->data) <= 0) {
        cur = cur->next;
    }
    n->next = cur->next;
    cur->next = n;
    ++sz;
}

schedule& schedule::operator+=(const schedule& other) {
    if (this == &other) {
        schedule copy(other);
        return (*this) += copy;
    }
    Node* cur = other.head;
    while (cur) {
        insertSorted(cur->data);
        cur = cur->next;
    }
    return *this;
}

schedule operator+(schedule a, const schedule& b) {
    a += b;
    return a;
}

// Ввод: первая непустая строка — число N.
// Затем N строк вида number|City|HH:MM
// В случае ошибки парсинга бросает std::invalid_argument
istream& operator>>(istream& in, schedule& s) {
    string first;
    while (true) {
        if (!std::getline(in, first)) {
            // EOF — вернуть поток
            return in;
        }
        if (!first.empty()) break;
    }

    first = trim_str_local(first);

    int N;
    try {
        N = stoi(first);
    } catch (const exception& e) {
        throw invalid_argument(string("Invalid schedule size: '") + first + "': " + e.what());
    }

    if (N < 0) throw invalid_argument("Negative schedule size: " + to_string(N));

    for (int i = 0; i < N; ++i) {
        train t;
        if (!(in >> t)) {
            throw invalid_argument("Unexpected end of input while reading trains");
        }
        s.insertSorted(t);
    }
    return in;
}

ostream& operator<<(ostream& out, const schedule& s) {
    out << s.sz << "\n";
    auto cur = s.head;
    while (cur) {
        out << cur->data << "\n";
        cur = cur->next;
    }
    return out;
}