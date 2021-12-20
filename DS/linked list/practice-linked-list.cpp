#include<bits/stdc++.h>

using namespace std;
struct  Node{
    int data;
    Node* next;
};

void insertNode(Node **root_ref, int data)
{
    Node* newNode;
    // If its first Node
    if (*root_ref == NULL)
    {
        newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        *root_ref = newNode;
        return;
    }

    // If it's not first node
    Node *last = *root_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    last->next = newNode;

    return;
}

void deleteNode(Node **root_ref, int key)
{
    Node *prev = NULL;
    Node *temp = *root_ref;

    if ((temp != NULL) && (temp->data == key))
    {
        *root_ref = temp->next;
        delete temp;
        return;
    }

    while ((temp!= NULL) && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp ==NULL)
    {
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void printList(Node* root)
{
    while (root != NULL)
    {
        cout << root->data << endl;
        root = root->next;
    }
}

int main()
{
    Node *root = NULL;
    int data, n;
    cout << "Enter total node - " << endl;
    cin >> n;

    cout << "Enter node data - " << endl;
    for (int i=0; i<n; i++)
    {
        cin >> data;
        insertNode(&root, data);
    }
    cout << endl;
    printList(root);

    insertNode(&root, 100);
    cout << endl;
    deleteNode(&root, 5);
    printList(root);

}