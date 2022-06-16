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

void display(Node *node)
{
    string str = to_string(node->data) + "-> ";
    for (Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
    }
    str = str + ".";
    cout << str << endl;
    for (Node *child : node->children)
    {
        display(child);
    }
}

int size(Node *root)
{

    int sz = 0;
    for (Node *child : root->children)
    {
        sz += size(child);
    }
    return sz + 1;
}
// lerning from this question-> loops are not dynamic while recursive call is//
// IMPORTANT CONCEPT//
int sizeByloop(Node *node)
{
    int sz = 0;
    for (Node *val : node->children)
    {
        // int csz= size(val);
        int csz = 0;

        for (Node *val2 : val->children)
        {
            csz++;
        }
        sz = sz + csz + 1;
    }
    return sz + 1;
    // This code will not work for tree having height more than 2(in terms of edges)
    // Because it has only 2 nested loop and allow go deep upto 2 height
    //  IN case of recursive solution we can go deep as much as possible.
}

int s(Node *root)
{
    int sum = 0;
    sum += root->data;
    for (Node *child : root->children)
    {
        sum += s(child);
    }
    return sum;
}
int s2(Node *root)
{

    int sum = 0;
    for (Node *child : root->children)
    {
        sum += s2(child);
    }
    sum += root->data;
    return sum;
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
    Node *root = construct(arr, n);
    int sz = s(root);
    int sz2 = s2(root);

    cout << sz << " " << sz2 << endl;
    // display(root);
}