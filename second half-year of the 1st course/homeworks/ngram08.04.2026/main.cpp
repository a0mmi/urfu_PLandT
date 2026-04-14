#include <bits/stdc++.h>
#include "Include/LinkedList.hpp"
#include "Include/NgramModel.hpp"

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    LinkedList sentenceList;
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        sentenceList.push_back(line);
    }

    NgramModel model;
    model.build(sentenceList);
    model.printResults();

    return 0;
}