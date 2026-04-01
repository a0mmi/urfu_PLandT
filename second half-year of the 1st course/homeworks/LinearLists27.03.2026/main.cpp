#include <bits/stdc++.h>
#include "Include/LinearList.hpp"

using namespace std;

int main() {
    LinearList list;

    string reservedFile = "reserved.txt";
    string textFile = "Input.txt";
    string outputFile = "output.txt";

    ifstream reservedIn(reservedFile);
    list.loadReserved(reservedIn);

    ifstream textIn(textFile);

    list.countInText(textIn);

    list.sort();

    ofstream out(outputFile);

    int printed = 0;
    for (int i = 0; i < list.getSize(); i++) {
        int cnt = list.getCount(i);
        if (cnt >= 0) {
            out << list.getWord(i) << " " << cnt << endl;
            printed++;
        }
    }
    out.close();
    return 0;
}