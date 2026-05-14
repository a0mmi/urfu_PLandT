#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr; 
    }
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void destroy(Node* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

void printTree(Node* root) {
    if (!root) {
        cout << "_";
        return;
    }

    cout << root->val;
    if (root->left || root->right) {
        cout << "(";
        printTree(root->left);
        cout << ",";
        printTree(root->right);
        cout << ")";
    }
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

Node* mirror(Node* root) {
    if (!root) return nullptr;
    Node* newNode = new Node(root->val);
    newNode->left = mirror(root->right);
    newNode->right = mirror(root->left);
    return newNode;
}

int findMax(Node* root) {
    if (!root) return INT_MIN;
    return max({ root->val, findMax(root->left), findMax(root->right) });
}

int countVal(Node* root, int target) {
    if (!root) return 0;
    return (root->val == target ? 1 : 0)
         + countVal(root->left,  target)
         + countVal(root->right, target);
}

int countMaxOccurrences(Node* root) {
    if (!root) return 0;
    return countVal(root, findMax(root));
}

Node* readTree() {
    int x;
    cin >> x;
    if (!cin) return nullptr;
    if (x == -1) return nullptr;

    Node* root = new Node(x);
    root->left = readTree();
    root->right = readTree();
    return root;
}

int main() {
    int task;
    cin >> task;

    Node* tree = readTree();

    switch (task) {
        case 1: {
            Node* mirrored = mirror(tree);

            cout << "mirror tree:\n";
            printTree(mirrored);
            cout << '\n';

            cout << "In-order: ";
            inorder(mirrored);
            cout << "\n";

            destroy(mirrored);
            break;
        }

        case 2: {
            int mx = findMax(tree);
            int cnt = countMaxOccurrences(tree);

            cout << "max el: " << mx << "\n";
            cout << "number of occurrences: " << cnt << "\n";
            break;
        }
    }

    destroy(tree);
    return 0;
}