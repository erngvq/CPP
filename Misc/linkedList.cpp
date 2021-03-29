#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printLinkedlList(Node *root)
{
    while (root)
    {
        cout << root->data << " -> ";
        root = root->next;
    }
    cout << "null" << endl;
}

int main()
{
    Node *root = new Node();
    Node *second = new Node();
    Node *third = new Node();

    root->data = 10;
    root->next = second;

    second->data = 4;
    second->next = third;

    third->data = 60;
    third->next = NULL;

    printLinkedlList(root);
}
