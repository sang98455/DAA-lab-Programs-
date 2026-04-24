#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void HuffmanCoding(char data[], int freq[], int size) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < size; i++) {
        pq.push(new Node(data[i], freq[i]));
    }

    while (pq.size() != 1) {

        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *top = new Node('$',
                             left->freq + right->freq);

        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printCodes(pq.top(), "");
}

int main() {
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(data) / sizeof(data[0]);

    cout << "Huffman Codes:\n";

    HuffmanCoding(data, freq, size);

    return 0;
}