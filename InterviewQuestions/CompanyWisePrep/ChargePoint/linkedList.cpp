// Implementation of stacks and queues.
// Graph & Tree uses adjacency list representation which uses linked list to store adjacent vertices.
// Dynamic memory allocation (OS uses linked list to keep the track)
// OS uses linked list to loop through all process
// Next and Previous functionality can be implemented using linked list.
// MANY MORE....

#include<iostream>

using namespace std;

struct Node {
int key;
Node *next;
};

Node* createNode(int key)
{
    Node *tmpNode = (Node*)malloc(sizeof(Node*));
    tmpNode->key = key;
    tmpNode->next = NULL;
}

void append(Node **head_ref, int key)
{
    if (*head_ref == nullptr)
    {
        *head_ref = createNode(key);
        return;
    }

    Node *last = *head_ref;

    while(last->next!=NULL)
    {
        last = last->next;
    }

    last->next = createNode(key);
    return;
}

void print(Node *head)
{
    while(head!=NULL)
    {
        cout << head->key << " ";
        head = head->next;
    }
    return;
}

void reversePrint(Node *head)
{
    if(head!=NULL)
    {
        reversePrint(head->next);
        cout << head->key << " ";
    }
}

void reverse(Node **head_ref)
{
    Node *prev = NULL;
    Node *current = *head_ref;
    Node *next = current->next;

    while (current != NULL)
    {
        next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return;
}

int main()
{
    Node *head = NULL;

    append(&head, 5);
    
    append(&head, 7);
    
    append(&head, 9);

    append(&head, 12);

    append(&head, 1);

    append(&head, 4);

    append(&head, 6);


    append(&head, 45);

    // reversePrint(head);
    
    print(head);

    reverse(&head);

    cout << endl;
    print(head);

    return 0;
}