#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = NULL;
        color = RED;
    }
};

class RedBlackTree {
private:
    Node *root;

    void rotateLeft(Node *&pt) {
        Node *right_child = pt->right;

        pt->right = right_child->left;

        if (pt->right != NULL)
            pt->right->parent = pt;

        right_child->parent = pt->parent;

        if (pt->parent == NULL)
            root = right_child;

        else if (pt == pt->parent->left)
            pt->parent->left = right_child;

        else
            pt->parent->right = right_child;

        right_child->left = pt;
        pt->parent = right_child;
    }

    void rotateRight(Node *&pt) {
        Node *left_child = pt->left;

        pt->left = left_child->right;

        if (pt->left != NULL)
            pt->left->parent = pt;

        left_child->parent = pt->parent;

        if (pt->parent == NULL)
            root = left_child;

        else if (pt == pt->parent->left)
            pt->parent->left = left_child;

        else
            pt->parent->right = left_child;

        left_child->right = pt;
        pt->parent = left_child;
    }

    void fixViolation(Node *&pt) {
        while (pt != root &&
               pt->parent->color == RED) {

            Node *parent = pt->parent;
            Node *grandparent = parent->parent;

            if (parent == grandparent->left) {

                Node *uncle = grandparent->right;

                if (uncle != NULL &&
                    uncle->color == RED) {

                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    pt = grandparent;
                }
                else {

                    if (pt == parent->right) {
                        rotateLeft(parent);
                        pt = parent;
                        parent = pt->parent;
                    }

                    rotateRight(grandparent);
                    swap(parent->color,
                         grandparent->color);
                    pt = parent;
                }
            }
            else {

                Node *uncle = grandparent->left;

                if (uncle != NULL &&
                    uncle->color == RED) {

                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    pt = grandparent;
                }
                else {

                    if (pt == parent->left) {
                        rotateRight(parent);
                        pt = parent;
                        parent = pt->parent;
                    }

                    rotateLeft(grandparent);
                    swap(parent->color,
                         grandparent->color);
                    pt = parent;
                }
            }
        }

        root->color = BLACK;
    }

    void inorder(Node *node) {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    RedBlackTree() {
        root = NULL;
    }

    void insert(int data) {
        Node *newNode = new Node(data);

        Node *parent = NULL;
        Node *current = root;

        while (current != NULL) {
            parent = current;

            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        newNode->parent = parent;

        if (parent == NULL)
            root = newNode;

        else if (data < parent->data)
            parent->left = newNode;

        else
            parent->right = newNode;

        fixViolation(newNode);
    }

    void display() {
        inorder(root);
    }
};

int main() {
    RedBlackTree tree;
    int choice, value;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Display (Inorder)";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Tree elements: ";
            tree.display();
            break;

        case 3:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice";
        }

    } while(choice != 3);

    return 0;
}