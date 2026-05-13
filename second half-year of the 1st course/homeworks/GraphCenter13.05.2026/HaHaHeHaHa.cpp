#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct heap_node {
    int dist;
    int vertex;
};

struct min_heap {
    heap_node* data;
    int size;
    int capacity;
 
    min_heap(int cap) : size(0), capacity(cap) {
        data = new heap_node[cap];
    }
 
    ~min_heap() {
        delete[] data;
        data = nullptr;
    }
 
    bool empty() {
        return size == 0;
    }

    void sift_up(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (data[parent].dist > data[i].dist) {
                heap_node tmp = data[parent];
                data[parent] = data[i];
                data[i] = tmp;
                i = parent;
            } else break;
        }
    }
 
    void sift_down(int i) {
        while (true) {
            int left  = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
 
            if (left  < size && data[left].dist < data[smallest].dist) smallest = left;
            if (right < size && data[right].dist < data[smallest].dist) smallest = right;
 
            if (smallest == i) break;
 
            heap_node tmp = data[i];
            data[i] = data[smallest];
            data[smallest] = tmp;
            i = smallest;
        }
    }
 
    void push(int dist, int vertex) {
        data[size] = {dist, vertex};
        sift_up(size);
        size++;
    }
 
    heap_node pop() {
        heap_node top = data[0];
        data[0] = data[--size];
        sift_down(0);
        return top;
    }
};

void dijkstra(int** adj, int n, int src, int* d) {
    bool* visited = new bool[n]();
 
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[src] = 0;
 
    // В худшем случае в кучу попадёт n*n элементов (ленивое удаление)
    min_heap h(n * n);
    h.push(0, src);
 
    while (!h.empty()) {
        heap_node cur = h.pop();
 
        if (visited[cur.vertex]) continue;
        visited[cur.vertex] = true;
 
        for (int v = 0; v < n; v++) {
            if (adj[cur.vertex][v] != INF && !visited[v]) {
                int new_dist = d[cur.vertex] + adj[cur.vertex][v];
                if (new_dist < d[v]) {
                    d[v] = new_dist;
                    h.push(new_dist, v);
                }
            }
        }
    }
 
    delete[] visited;
}
 