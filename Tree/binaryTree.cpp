#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void preOrderItrative(Node *root)
{
    if (!root)
    {
        return;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }
    }
}

void inOrderItrative(Node *root)
{
    if (!root)
    {
        return;
    }
    stack<Node *> st;
    Node *curr = root;
    while (1)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

void postOrderItrative(Node *root)
{
    if (!root)
    {
        return;
    }
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        Node *temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left)
        {
            st1.push(temp->left);
        }
        if (temp->right)
        {
            st1.push(temp->right);
        }
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    postOrder(root);
    cout << endl;
    postOrderItrative(root);
    return 0;
}