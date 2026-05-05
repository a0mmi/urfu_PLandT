#include "Graph.hpp"
#include <bits/stdc++.h>

using namespace std;

IntNode::IntNode(int v) {
    this->val = v;
    this->next = nullptr;
}

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    clear();
}

bool IntList::empty() {
    return head == nullptr;
}

void IntList::add(int val) {
    IntNode* node = new IntNode(val);

    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void IntList::clear() {
    while (head) {
        IntNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
}

IntNode* IntList::getHead() {
    return head;
}

void IntList::print(std::ostream& out) {
    for (IntNode* p = head; p != nullptr; p = p->next) {
        out << p->val;
        if (p->next) out << " -> ";
    }
    out << " -> nullptr";
}

EdgeNode::EdgeNode(int f, int t) {
    this->from = f;
    this->to = t;
    this->next = nullptr;
}

EdgeList::EdgeList() {
    head = nullptr;
    tail = nullptr;
}

EdgeList::~EdgeList() {
    clear();
}

bool EdgeList::empty() {
    return head == nullptr;
}

void EdgeList::add(int from, int to) {
    EdgeNode* node = new EdgeNode(from, to);

    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void EdgeList::clear() {
    while (head) {
        EdgeNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
}

EdgeNode* EdgeList::getHead() {
    return head;
}

void EdgeList::print(std::ostream& out) {
    int idx = 1;
    for (EdgeNode* p = head; p != nullptr; p = p->next, ++idx) {
        out << "Edge " << idx << ": ("
            << p->from << " -> " << p->to << ")\n";
    }
}

Graph::Graph(int n) {
    vertexCount = n;
    adjList = new IntList[n];
}

Graph::~Graph() {
    delete[] adjList;
}

int Graph::getVertexCount() {
    return vertexCount;
}

void Graph::addEdge(int from, int to) {
    if (from < 0 || from >= vertexCount) return;
    if (to   < 0 || to   >= vertexCount) return;

    adjList[from].add(to);
}

void Graph::loadFromMatrix(int** matrix, int n) {
    // Сбрасываем текущее состояние
    for (int i = 0; i < vertexCount; i++) {
        adjList[i].clear();
    }

    int limit = (n < vertexCount) ? n : vertexCount;

    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            if (matrix[i][j] != 0) {
                adjList[i].add(j);
            }
        }
    }
}

EdgeList* Graph::getEdgeList() {
    EdgeList* edges = new EdgeList();

    for (int i = 0; i < vertexCount; i++) {
        IntNode* p = adjList[i].getHead();
        while(p != nullptr) {
            edges->add(i, p->val);
            p = p->next;
        }

    }
    return edges;
}

int Graph::countIsolated() {
    int count = 0;

    for (int i = 0; i < vertexCount; i++) {
        if (adjList[i].empty()) {
            count++;
        }
    }
    return count;
}

void Graph::print(std::ostream& out) {
    for (int i = 0; i < vertexCount; i++) {
        out << "vertex " << i << " --> ";
        adjList[i].print(out);
        out << '\n';
    }
}
