#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data): data{data}, left{nullptr}, right{nullptr} {}
};

void printBinaryTree(Node *root)
{
    if (root == nullptr) return;
    cout << root->data << " ";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int main()
{
    Node *root = new Node(1);
    Node *left = new Node(2);
    Node *right = new Node(3);
    Node *leftleft = new Node(4);
    Node *leftright = new Node(5);
    Node *rightleft = new Node(6);
    Node *rightright = new Node(7);

    root->left = left;
    root->right = right;
    left->left = leftleft;
    left->right = leftright;
    right->left = rightleft;
    right->right = rightright;

    printBinaryTree(root);
    cout << endl;
}
