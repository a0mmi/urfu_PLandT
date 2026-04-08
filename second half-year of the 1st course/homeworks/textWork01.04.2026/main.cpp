#include <fstream>
#include <cctype>
#include <locale>
#include <string>
#include "Include\Text.hpp"

using namespace std;

static bool isWordChar(unsigned char c) {
    return isalpha(c) || c == '\'';
}

static bool isSentenceSeparator(unsigned char c) {
    return c == '.' || c == '!' || c == '?' || c == ';' || c == ':' || c == '(' || c == ')';
}

Text parseFile(const string& filename) {
    ifstream fin(filename, ios::binary);
    Text text;

    if (!fin) {
        cerr << "Не удалось открыть файл: " << filename << '\n';
        return text;
    }

    Sentence* currentSentence = new Sentence();
    string currentWord;

    char ch;
    while (fin.get(ch)) {
        unsigned char c = ch;

        if (isWordChar(c)) {
            currentWord += tolower(c);
        } else {
            if (!currentWord.empty()) {
                currentSentence->addWord(currentWord);
                currentWord.clear();
            }

            if (isSentenceSeparator(c)) {
                text.addSentence(currentSentence);
                currentSentence = new Sentence();
            }
        }
    }

    if (!currentWord.empty()) {
        currentSentence->addWord(currentWord);
    }

    text.addSentence(currentSentence);

    return text;
}

int main() {
    Text text = parseFile("input.txt");
    text.print(cout);

    return 0;
}