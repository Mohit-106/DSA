#include <bits/stdc++.h>
using namespace std;

int sum = 0;
int Max = INT_MIN;
int Min = INT_MAX;
int height = -1;

class Node
{
public:
    int data;
    vector<Node *> children;
};

Node *newNode(int val)
{ // here we are just setting the data in the node
    Node *node = new Node;
    node->data = val;
    return node;
}

// Tree Constructor
Node *Constructor(vector<int> &arr, int n)
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
            if (st.size() == 0)
            {
                root = t;
            }
            else
            {

                st.top()->children.push_back(t);
            }
            st.push(t);
        }
    }

    return root;
}



void multiSolver(Node *node, int depth)
{

    sum += node->data;
    if (node->data > Max)
    {
        Max = node->data;
    }
    if (node->data < Min)
    {
        Min = node->data;
    }
    if (depth > height)
    {
        height = depth;
    }

    for (Node *child : node->children)
    {
        multiSolver(child, depth + 1);
    }
}







int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = Constructor(arr, n);
    multiSolver(root, 0);
    cout << "sum"<< " " << sum << endl;
    cout << "max"<< " " << Max << endl;
    cout << "min"<< " " << Min << endl;
    cout << "height"<< " " << height << endl;

   









    return 0;
}
