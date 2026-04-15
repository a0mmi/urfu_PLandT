#include "NgramModel.hpp"

void NgramModel::splitToWords(const string& text, LinkedList& wordsList) {
    wordsList.clear();

    string cleaned;
    for (char c : text) {
        unsigned char uc = (unsigned char)c;
        if (isalpha(uc)) cleaned += (char)tolower(uc); // символ = буква --> в нижнем регистре добавляю
        else if (isspace(uc)) cleaned += ' ';
    }

    size_t pos = 0;
    while (pos < cleaned.size()) {
        while (pos < cleaned.size() && cleaned[pos] == ' ') ++pos;
        if (pos >= cleaned.size()) break;

        size_t start = pos;
        while (pos < cleaned.size() && cleaned[pos] != ' ') ++pos;

        string word = cleaned.substr(start, pos - start);
        if (!word.empty()) wordsList.push_back(word);
    }
}

NgramModel::NgramModel() = default;

void NgramModel::build(LinkedList& sentences) {
    const Node* sNode = sentences.getHead();

    while (sNode != nullptr) {
        LinkedList words;
        splitToWords(sNode->data, words);

        const Node* curr = words.getHead();
        while (curr != nullptr && curr->next != nullptr) {
            bigramCounts.add(curr->data, curr->next->data);
            curr = curr->next;
        }

        curr = words.getHead();
        while (curr != nullptr && curr->next != nullptr && curr->next->next != nullptr) {
            string prefix = curr->data + " " + curr->next->data;
            trigramCounts.add(prefix, curr->next->next->data);
            curr = curr->next;
        }

        sNode = sNode->next;
    }
}

void NgramModel::printBigrams() {
    bigramCounts.print();
}

void NgramModel::printTrigrams() {
    trigramCounts.print();
}

void NgramModel::printResults() {
    printBigrams();
    cout << endl;
    printTrigrams();
}