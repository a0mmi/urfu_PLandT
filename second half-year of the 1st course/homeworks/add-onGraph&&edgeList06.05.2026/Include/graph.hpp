#pragma once

#include "HashTable.hpp"
#include <bits/stdc++.h>
using namespace std;

class graph {
private:
    HashTable table;

    long long encodeEdge(int u, int v);

public:
    graph(int hashSize = 1024);
    ~graph();

    void buildEdgeList(int n, int* degree, int** adj);
    void showEdgeList();

    int countIsolatedVertices(int n, int** matrix);
};