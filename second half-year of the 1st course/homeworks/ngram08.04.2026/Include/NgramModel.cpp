#include "NgramModel.hpp"

NgramModel::NgramModel() {}

void NgramModel::build(const Text& text) {
    LinkedList words;

    for (Text::SentenceNode* sNode = text.head; sNode != nullptr; sNode = sNode->next) {
        Sentence* sent = sNode->sentence;
        if (!sent || sent->empty()) continue;

        words.clear();

        for (Sentence::WordNode* wNode = sent->head; wNode != nullptr; wNode = wNode->next) {
            words.push_back(wNode->word);
        }
        
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