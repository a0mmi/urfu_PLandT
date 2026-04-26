#pragma once

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
    Node(const string& key, const string& value, Node* next=nullptr);
};

class HashTable {
private:
    Node** buckets;
    int bucketCount;
    int countElements;

    double maxLoadFactor = 0.75;
    void rehash(int newBucketCount);

    size_t (*hash)(const string& key);
    bool (*validKey)(const string& key);
    bool (*validValue)(const string& value);

    static size_t defhash(const string& key);
    static bool defvalidKey(const string& key);
    static bool defvalidValue(const string& value);
public:
    HashTable(int size);
    HashTable(int size, size_t (*hash_)(const string& x));
    HashTable(int size, bool (*validKey_)(const string& x), bool (*validValue_)(const string& x));
    HashTable(int size, size_t (*hash_)(const string& x),
            bool (*validKey_)(const string& x), bool (*validValue_)(const string& x));
    ~HashTable();
    
    void clear();

    double loadFactor() const;
    void setLoadFactor(double factor);

    bool add(const string& key, const string& value);
    bool find(const string& key);
    bool remove(const string& key);

    string get(const string& key);

    void show();
};