#include <bits/stdc++.h>
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

class HeapMover
{
public:
    Node *pre=NULL;
    Node *suc=NULL;
    int state = 0;
};

void prnsc(Node *node, int data, HeapMover *mover)
{

    if (mover->state == 0)
    {
        if (node->data == data)
        {

            mover->state++;
        }
        else
        {
            mover->pre = node;
        }
    }
    else if (mover->state == 1)
    {

        mover->suc = node;
        mover->state++;
    }

    for (Node *child : node->children)
    {
        prnsc(child, data, mover);
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
    int val;
    cin >> val;
    Node *root = construct(arr, n);
    HeapMover *mover = new HeapMover();
    prnsc(root, val, mover);
    if (mover->pre == NULL)
    {
        cout << "Predecessor = Not found" << endl;
    }
    else
    {
        cout << "Predecessor = " << mover->pre->data << endl;
    }

    if (mover->suc == NULL)
    {
        cout << "Successor = Not found";
    }
    else
    {
        cout << "Successor = " << mover->suc->data;
    }
}