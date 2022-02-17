#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    return temp;
}

Node *construct(int arr[], int n)
{
    Node *root = NULL;
    stack<Node *> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = newNode(arr[i]);

            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

//By global variable
int c = INT_MAX;
int flloor = INT_MIN;
void cnf(Node *node, int data)
{

    if (node->data > flloor && node->data < data)
    {
        flloor = node->data;
    }
    else if (node->data > data && node->data < c)
    {
        c = node->data;
    }

    for (Node *child : node->children)
    {
        cnf(child, data);
    }
}

// By HeapMover
class Heapmover
{

public:
    int cm = INT_MAX;
    int flloorm = INT_MIN;
};
void cnf2(Node *node, int data, Heapmover *mover)
{

    if (node->data > mover->flloorm && node->data < data)
    {
        mover->flloorm = node->data;
    }
    else if (node->data > data && node->data < mover->cm)
    {
        mover->cm = node->data;
    }

    for (Node *child : node->children)
    {
        cnf2(child, data, mover);
    }
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int data;
    cin >> data;
    Node *root = construct(arr, n);
    cnf(root, data);
    cout << "CEIL = " << c << endl;
    cout << "FLOOR = " << flloor << endl;

    cout << "------" << endl;

    Heapmover *mover = new Heapmover();
    cnf2(root, data, mover);
    cout << "CEIL = " << mover->cm << endl;
    cout << "FLOOR = " << mover->flloorm << endl;
}