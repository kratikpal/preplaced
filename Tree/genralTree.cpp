#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> child;

    Node(int val)
    {
        data = val;
    }
};

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            for (int i = 0; i < temp->child.size(); i++)
            {
                q.push(temp->child[i]);
            }
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(10);
    (root->child).push_back(new Node(2));
    (root->child).push_back(new Node(34));
    (root->child).push_back(new Node(56));
    (root->child).push_back(new Node(100));
    (root->child[0]->child).push_back(new Node(77));
    (root->child[0]->child).push_back(new Node(88));
    (root->child[2]->child).push_back(new Node(1));
    (root->child[3]->child).push_back(new Node(7));
    (root->child[3]->child).push_back(new Node(8));
    (root->child[3]->child).push_back(new Node(9));
    levelOrder(root);
    return 0;
}