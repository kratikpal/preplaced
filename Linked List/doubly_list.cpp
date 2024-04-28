#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

Node *insertAtHead(Node *head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        return newNode;
    }
    head->prev = newNode;
    newNode->next = head;
    return newNode;
}

Node *insertAtTail(Node *head, int value)
{
    if (!head)
    {
        return insertAtHead(head, value);
    }
    Node *newNode = new Node(value);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node *insertAtMiddle(Node *head, int value)
{
    if (!head)
    {
        return insertAtHead(head, value);
    }
    Node *newNode = new Node(value);
    Node *slowPtr = head;
    Node *fastPtr = head->next;
    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    newNode->next = slowPtr->next;
    slowPtr->next = newNode;
    newNode->prev = slowPtr;
    newNode->next->prev = newNode;
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    head = insertAtTail(head, 1);
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 4);
    head = insertAtHead(head, 0);
    head = insertAtMiddle(head, 5);
    printList(head);
    return 0;
}