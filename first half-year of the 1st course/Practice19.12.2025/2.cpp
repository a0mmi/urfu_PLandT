#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ifstream rin("reservedwords.txt");
    if (!rin) { cerr << "! reservedwords.txt" << endl; return 1; }

    int rcnt = 0;
    string tmp;
    while (rin >> tmp) ++rcnt;
    rin.close();

    if (rcnt == 0) { cerr << "No reserved words" << endl; return 1; }

    string *reserved = new string[rcnt];
    long long *counts = new long long[rcnt];
    for (int i = 0; i < rcnt; ++i) counts[i] = 0;

    rin.open("reservedwords.txt");
    int idx = 0;
    while (rin >> tmp && idx < rcnt) {
        for (char &c : tmp) c = (char)tolower((unsigned char)c);
        reserved[idx++] = tmp;
    }
    rin.close();

    ifstream tin("text.txt");
    if (!tin) { cerr << "! text.txt" << endl; delete[] reserved; delete[] counts; return 1; }

    string line;
    while (getline(tin, line)) {
        for (char &c : line) {
            if (!isalnum((unsigned char)c)) c = ' ';
            else c = (char)tolower((unsigned char)c);
        }
        istringstream iss(line);
        while (iss >> tmp) {
            for (int i = 0; i < rcnt; ++i) {
                if (tmp == reserved[i]) { ++counts[i]; break; }
            }
        }
    }
    tin.close();

    ofstream out("reserved_counts.txt");
    if (!out) { cerr << "! reserved_counts.txt" << endl; delete[] reserved; delete[] counts; return 1; }
    for (int i = 0; i < rcnt; ++i) out << reserved[i] << " : " << counts[i] << endl;
    out.close();

    delete[] reserved;
    delete[] counts;

    cout << "Done!";
    return 0;
}

// int main() {
//     ifstream rin("reservedwords.txt");
//     int rcnt = 0;
//     string tmp;
//     while (rin >> tmp) ++rcnt;
//     rin.close();

//     string *reserved = new string[rcnt];
//     long long *counts = new long long[rcnt];
//     for (int i = 0; i < rcnt; ++i) counts[i] = 0;

//     rin.open("reservedwords.txt");
//     int idx = 0;
//     while (rin >> tmp) {
//         for (char &c : tmp) c = (char)tolower((unsigned char)c);
//         reserved[idx++] = tmp;
//     }
//     rin.close();

//     ifstream tin("text.txt");
//     string line;
//     while (getline(tin, line)) {
//         for (char &c : line) {
//             if (!isalnum((unsigned char)c)) c = ' ';
//             else c = (char)tolower((unsigned char)c);
//         }
//         istringstream iss(line);
//         while (iss >> tmp) {
//             for (int i = 0; i < rcnt; ++i) {
//                 if (tmp == reserved[i]) { ++counts[i]; break; }
//             }
//         }
//     }
//     tin.close();

//     ofstream out("reserved_counts.txt");
//     for (int i = 0; i < rcnt; ++i) out << reserved[i] << " : " << counts[i] << '\n';
//     out.close();

//     delete[] reserved;
//     delete[] counts;
//     return 0;
// }
