#pragma once

#include <bits/stdc++.h>
#include "LinkedList.hpp"
#include "table.hpp"

using namespace std;

class NgramModel {
private:
    table bigramCounts; // а можно map<string, map<string, int>>?
    table trigramCounts;

    void splitToWords(const string& text, LinkedList& wordsList);

public:
    NgramModel();
    void build(LinkedList& sentences);
    void printBigrams();
    void printTrigrams();
    void printResults();
};
