#include <bits/stdc++.h>
using namespace std;

class Vec
{
    int size;
    int currIdx;

public:
    int *arr;
    Vec()
    {
        arr = new int[8];
        size = 8;
        currIdx = 0;
    }
    Vec(int n)
    {
        arr = new int[n];
        size = n;
        currIdx = 0;
    }
    void push_back(int data)
    {
        if (currIdx == size)
        {
            int *temp = new int[size * 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete arr;
            arr = temp;
            size = size * 2;
        }
        arr[currIdx++] = data;
    }

    int sizee()
    {
        return currIdx;
    }
};

int main()
{
    Vec v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for (int i = 0; i < v.sizee(); i++)
    {
        cout << v.arr[i] << " ";
    }
    return 0;
}