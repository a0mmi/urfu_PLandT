#pragma once

#include <bits/stdc++.h>
#include "LinkedList.hpp"
#include "table.hpp"
#include "Text.hpp"

using namespace std;

class NgramModel {
private:
    table bigramCounts;
    table trigramCounts;

public:
    NgramModel();
    void build(const Text& text);
    void printBigrams();
    void printTrigrams();
    void printResults();
};