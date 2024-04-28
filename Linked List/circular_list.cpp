#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *insertAtHead(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        newNode->next = newNode;
        return newNode;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

Node *insertAtTail(Node *head, int data)
{
    if (!head)
    {
        return insertAtHead(head, data);
    }
    Node *newNode = new Node(data);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node *insertAtMiddle(Node *head, int data)
{
    if (!head)
    {
        return insertAtHead(head, data);
    }
    Node *newNode = new Node(data);
    Node *slowPtr = head;
    Node *fastPtr = head->next;
    while (fastPtr != head && fastPtr->next != head)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    newNode->next = slowPtr->next;
    slowPtr->next = newNode;
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
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