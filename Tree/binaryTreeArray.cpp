#include <bits/stdc++.h>
using namespace std;

vector<int> tree(20, -1);

void insertLeft(int parentIdx, int val)
{
    if (tree[parentIdx] == -1 || parentIdx >= tree.size())
    {
        cout << "Invalid parent index" << endl;
        return;
    }
    tree[(parentIdx * 2) + 1] = val;
}

void insertRight(int parentIdx, int val)
{
    if (tree[parentIdx] == -1 || parentIdx >= tree.size())
    {
        cout << "Invalid parent index" << endl;
        return;
    }
    tree[(parentIdx * 2) + 2] = val;
}

void preOrder(int rootIdx)
{
    if (rootIdx >= tree.size() || tree[rootIdx] == -1)
    {
        return;
    }
    cout << tree[rootIdx] << " ";
    preOrder(rootIdx * 2 + 1);
    preOrder(rootIdx * 2 + 2);
}

int main()
{
    tree[0] = 0;
    insertLeft(0, 1);
    insertRight(0, 2);
    insertLeft(1, 3);
    insertRight(1, 4);
    insertLeft(2, 5);
    insertRight(2, 6);
    preOrder(0);
    return 0;
}