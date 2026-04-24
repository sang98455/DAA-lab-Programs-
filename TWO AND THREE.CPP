#include <iostream>
using namespace std;

class Node {
public:
    int data[2];
    Node* child[3];
    int count;

    Node() {
        count = 0;
        for (int i = 0; i < 3; i++)
            child[i] = NULL;
    }
};

class TwoThreeTree {
private:
    Node* root;

    void display(Node* node) {
        if (node != NULL) {
            for (int i = 0; i < node->count; i++) {
                display(node->child[i]);
                cout << node->data[i] << " ";
            }
            display(node->child[node->count]);
        }
    }

public:
    TwoThreeTree() {
        root = NULL;
    }

    void insert(int value) {
        if (root == NULL) {
            root = new Node();
            root->data[0] = value;
            root->count = 1;
            return;
        }

        Node* current = root;

        while (current->child[0] != NULL) {
            if (value < current->data[0])
                current = current->child[0];

            else if (current->count == 1 ||
                     value < current->data[1])
                current = current->child[1];

            else
                current = current->child[2];
        }

        if (current->count < 2) {
            current->data[current->count] = value;
            current->count++;

            if (current->count == 2 &&
                current->data[0] > current->data[1]) {

                int temp = current->data[0];
                current->data[0] = current->data[1];
                current->data[1] = temp;
            }
        }
        else {
            cout << "Node split required (not implemented)\n";
        }
    }

    void displayTree() {
        display(root);
    }
};

int main() {
    TwoThreeTree tree;
    int choice, value;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Tree elements: ";
            tree.displayTree();
            break;

        case 3:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 3);

    return 0;
}