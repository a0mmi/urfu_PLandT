#pragma once

#include <iostream>

struct IntNode {
    int val;
    IntNode* next;

    IntNode(int v);
};

class IntList {
private:
    IntNode* head;
    IntNode* tail;

public:
    IntList();
    ~IntList();

    bool empty();
    void add(int val);
    void clear();
    IntNode* getHead();
    void print(std::ostream& out);
};

struct EdgeNode {
    int from;
    int to;
    EdgeNode* next;

    EdgeNode(int f, int t);
};

class EdgeList {
private:
    EdgeNode* head;
    EdgeNode* tail;

public:
    EdgeList();
    ~EdgeList();

    bool empty();
    void add(int from, int to);
    void clear();
    EdgeNode* getHead();
    void print(std::ostream& out);
};
class Graph {
private:
    int vertexCount;
    IntList*adjList;

public:
    Graph(int n);
    ~Graph();

    int getVertexCount();

    void addEdge(int from, int to);

    void loadFromMatrix(int** matrix, int n);

    EdgeList* getEdgeList();

    int countIsolated();

    void print(std::ostream& out);
};
