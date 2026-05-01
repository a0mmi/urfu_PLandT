#include "allrc++.hpp"
#include <bits/stdc++.h>

using namespace std;

string trim(const string& s) {
    size_t l = 0, r = s.size();
    while (l < r && isspace((unsigned char)s[l])) ++l;
    while (r > l && isspace((unsigned char)s[r - 1])) --r;
    return s.substr(l, r - l);
}

bool isLatinName(const string& s) {
    if (s.empty()) return false;
    for (unsigned char c : s) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            return false;
        }
    }
    return true;
}

bool isPhone(const string& s) {
    // Format: +7XXXYYYZZZZ
    if (s.size() != 12) return false;
    if (s[0] != '+') return false;
    if (s[1] != '7') return false;

    for (int i = 2; i < 12; ++i) {
        if (!isdigit((unsigned char)s[i])) {
            return false;
        }
    }
    return true;
}

int readChoice() {
    while (true) {
        string line;
        cout << "Choice: " << flush;

        if (!getline(cin, line)) return -1;
        line = trim(line);

        if (line.empty()) {
            cout << "Please enter a number.\n";
            continue;
        }

        try {
            size_t pos = 0;
            int choice = stoi(line, &pos);
            if (pos != line.size()) {
                cout << "Please enter a valid number.\n";
                continue;
            }
            return choice;
        } catch (...) {
            cout << "Please enter a valid number.\n";
        }
    }
}

string readLinePrompt(const string& prompt) {
    cout << prompt << flush;
    string line;
    getline(cin, line);
    return trim(line);
}

void menu() {
    cout << "\n=== Phone Book ===\n";
    cout << "1. Add contact\n";
    cout << "2. Find phone by name\n";
    cout << "3. Delete contact\n";
    cout << "4. Show all contacts\n";
    cout << "0. Exit\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    HashTable table(101);
    table.setLoadFactor(0.75);

    while (true) {
        menu();
        int choice = readChoice();

        if (choice == -1) {
            cout << "\nExiting.\n";
            break;
        }

        if (choice == 0) {
            cout << "Exiting.\n";
            break;
        }

        if (choice == 1) {
            string name = readLinePrompt("Name (Latin letters only): ");

            if (!isLatinName(name)) {
                cout << "Error: name must contain only Latin letters.\n";
                continue;
            }

            string phone = readLinePrompt("Phone (+7XXXYYYZZZZ): ");

            if (!isPhone(phone)) {
                cout << "Error: phone must be in format +7XXXYYYZZZZ.\n";
                continue;
            }

            if (table.add(name, phone)) {
                cout << "Contact added.\n";
            } else {
                cout << "Failed to add contact.\n";
            }
        }
        else if (choice == 2) {
            string name = readLinePrompt("Name: ");

            if (!isLatinName(name)) {
                cout << "Error: name must contain only Latin letters.\n";
                continue;
            }

            string phone = table.get(name);
            if (!phone.empty()) {
                cout << "Phone: " << phone << '\n';
            } else {
                cout << "Contact not found.\n";
            }
        }
        else if (choice == 3) {
            string name = readLinePrompt("Name: ");

            if (!isLatinName(name)) {
                cout << "Error: name must contain only Latin letters.\n";
                continue;
            }

            if (table.remove(name)) {
                cout << "Contact deleted.\n";
            } else {
                cout << "Contact not found.\n";
            }
        }
        else if (choice == 4) {
            table.show();
        }
        else {
            cout << "Unknown menu option.\n";
        }
    }

    return 0;
}