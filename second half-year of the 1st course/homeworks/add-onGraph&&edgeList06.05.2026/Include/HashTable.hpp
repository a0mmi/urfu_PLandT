#pragma once

#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long key;
    int value;
    Node* next;
    Node* prev;
    Node* nextAll;
    Node* prevAll;

    Node(const long long& key, const int& value,
         Node* next = nullptr, Node* prev = nullptr,
         Node* nextAll = nullptr, Node* prevAll = nullptr);
};

class HashTable {
private:
    Node** buckets;
    int bucketCount;
    int countElements;

    Node* headAll;
    Node* tailAll;

    double maxLoadFactor = 0.75;
    void rehash(int newBucketCount);

    size_t (*hash)(const long long& key);
    bool (*validKey)(const long long& key);
    bool (*validValue)(const int& value);

    static size_t defhash(const long long& key);
    static bool defvalidKey(const long long& key);
    static bool defvalidValue(const int& value);

public:
    HashTable();
    HashTable(int size);
    HashTable(int size, size_t (*hash_)(const long long& x));
    HashTable(int size, bool (*validKey_)(const long long& x), bool (*validValue_)(const int& x));
    HashTable(int size, size_t (*hash_)(const long long& x),
              bool (*validKey_)(const long long& x), bool (*validValue_)(const int& x));
    ~HashTable();

    void init(int size);
    void clear();

    double loadFactor() const;
    void setLoadFactor(double factor);

    bool add(const long long& key, const int& value);
    bool find(const long long& key);
    bool remove(const long long& key);

    int get(const long long& key);

    Node* first() const;
};