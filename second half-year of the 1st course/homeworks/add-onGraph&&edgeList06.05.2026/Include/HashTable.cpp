#include "HashTable.hpp"
#include <bits/stdc++.h>

using namespace std;

Node::Node(const long long& key, const int& value,
    Node* next, Node* prev, Node* nextAll, Node* prevAll) {
    this->key = key;
    this->value = value;
    this->next = next;
    this->prev = prev;
    this->nextAll = nextAll;
    this->prevAll = prevAll;
}

void HashTable::init(int size) {
    if (size < 1) size = 1;

    buckets = new Node*[size];
    for (int i = 0; i < size; i++) {
        buckets[i] = nullptr;
    }

    bucketCount = size;
    countElements = 0;
    headAll = nullptr;
    tailAll = nullptr;
    maxLoadFactor = 0.75;
    hash = defhash;
    validKey = defvalidKey;
    validValue = defvalidValue;
}

void HashTable::rehash(int newBucketCount) {
    if (newBucketCount < 1) return;

    Node** newBuckets = new Node*[newBucketCount];
    for (int i = 0; i < newBucketCount; i++) {
        newBuckets[i] = nullptr;
    }

    for (int i = 0; i < bucketCount; i++) {
        Node* curr = buckets[i];
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            size_t index = hash(curr->key) % newBucketCount;

            curr->prev = nullptr;
            curr->next = newBuckets[index];
            if (newBuckets[index] != nullptr) {
                newBuckets[index]->prev = curr;
            }
            newBuckets[index] = curr;

            curr = nextNode;
        }
    }

    delete[] buckets;
    buckets = newBuckets;
    bucketCount = newBucketCount;
}

size_t HashTable::defhash(const long long& key) {
    unsigned long long x = (unsigned long long)key;
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    x *= 0xc4ceb9fe1a85ec53ULL;
    x ^= x >> 33;
    return (size_t)x;
}

bool HashTable::defvalidKey(const long long& key) {
    return key >= 0;
}

bool HashTable::defvalidValue(const int& value) {
    return true;
}

HashTable::HashTable() {
    buckets = nullptr;
    bucketCount = 0;
    countElements = 0;
    headAll = nullptr;
    tailAll = nullptr;
    hash = defhash;
    validKey = defvalidKey;
    validValue = defvalidValue;
    init(1);
}

HashTable::HashTable(int size) {
    buckets = nullptr;
    bucketCount = 0;
    countElements = 0;
    headAll = nullptr;
    tailAll = nullptr;
    hash = defhash;
    validKey = defvalidKey;
    validValue = defvalidValue;
    init(size);
}

HashTable::HashTable(int size, size_t (*hash_)(const long long& x)) {
    buckets = nullptr;
    bucketCount = 0;
    countElements = 0;
    headAll = nullptr;
    tailAll = nullptr;
    hash = hash_;
    validKey = defvalidKey;
    validValue = defvalidValue;
    init(size);
}

HashTable::HashTable(int size, bool (*validKey_)(const long long& x), bool (*validValue_)(const int& x)) {
    buckets = nullptr;
    bucketCount = 0;
    countElements = 0;
    headAll = nullptr;
    tailAll = nullptr;
    hash = defhash;
    validKey = validKey_;
    validValue = validValue_;
    init(size);
}

HashTable::HashTable(int size, size_t (*hash_)(const long long& x),
    bool (*validKey_)(const long long& x), bool (*validValue_)(const int& x)) {
    buckets = nullptr;
    bucketCount = 0;
    countElements = 0;
    headAll = nullptr;
    tailAll = nullptr;
    hash = hash_;
    validKey = validKey_;
    validValue = validValue_;
    init(size);
}

HashTable::~HashTable() {
    clear();
    delete[] buckets;
}

void HashTable::clear() {
    Node* curr = headAll;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->nextAll;
        delete temp;
    }

    if (buckets != nullptr) {
        for (int i = 0; i < bucketCount; i++) {
            buckets[i] = nullptr;
        }
    }

    headAll = nullptr;
    tailAll = nullptr;
    countElements = 0;
}

double HashTable::loadFactor() const {
    if (bucketCount == 0) return 0.0;
    return (double)countElements / bucketCount;
}

void HashTable::setLoadFactor(double factor) {
    if (factor <= 0.0) return;
    maxLoadFactor = factor;
}

bool HashTable::add(const long long& key, const int& value) {
    if (loadFactor() > maxLoadFactor) {
        rehash(bucketCount * 2);
    }

    if (!validKey(key) || !validValue(value)) {
        return false;
    }

    size_t index = hash(key) % bucketCount;
    Node* curr = buckets[index];

    while (curr != nullptr) {
        if (curr->key == key) {
            curr->value = value;
            return true;
        }
        curr = curr->next;
    }

    Node* newNode = new Node(key, value, buckets[index], nullptr, nullptr, tailAll);

    if (buckets[index] != nullptr) {
        buckets[index]->prev = newNode;
    }
    buckets[index] = newNode;

    if (tailAll == nullptr) {
        headAll = newNode;
        tailAll = newNode;
    }
    else {
        tailAll->nextAll = newNode;
        tailAll = newNode;
    }

    countElements++;
    return true;
}

bool HashTable::find(const long long& key) {
    if (!validKey(key)) return false;

    size_t index = hash(key) % bucketCount;
    Node* curr = buckets[index];

    while (curr != nullptr) {
        if (curr->key == key) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool HashTable::remove(const long long& key) {
    if (!validKey(key)) return false;

    size_t index = hash(key) % bucketCount;
    Node* curr = buckets[index];

    while (curr != nullptr) {
        if (curr->key == key) {
            if (curr->prev == nullptr) {
                buckets[index] = curr->next;
            }
            else {
                curr->prev->next = curr->next;
            }

            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }

            if (curr->prevAll != nullptr) {
                curr->prevAll->nextAll = curr->nextAll;
            }
            else {
                headAll = curr->nextAll;
            }

            if (curr->nextAll != nullptr) {
                curr->nextAll->prevAll = curr->prevAll;
            }
            else {
                tailAll = curr->prevAll;
            }

            delete curr;
            countElements--;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int HashTable::get(const long long& key) {
    if (!validKey(key)) return 0;

    size_t index = hash(key) % bucketCount;
    Node* curr = buckets[index];

    while (curr != nullptr) {
        if (curr->key == key) {
            return curr->value;
        }
        curr = curr->next;
    }
    return 0;
}

Node* HashTable::first() const {
    return headAll;
}
