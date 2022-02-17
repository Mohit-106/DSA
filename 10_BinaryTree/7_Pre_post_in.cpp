#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};



Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    pair<Node *, int> p = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty())
    {
        if (st.top().second == 1)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->left = new Node(arr[idx]);
                pair<Node *, int> lp = {st.top().first->left, 1};
                st.push(lp);
            }
            else
            {
                st.top().first->left = nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->right = new Node(arr[idx]);
                pair<Node *, int> rp = {st.top().first->right, 1};
                st.push(rp);
            }
            else
            {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

//recursive can be done by creating three separate functions

class Pair
{

public:
    Node *node;
    int state;
    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};
void iterativePrePostInTraversal(Node *node)
{

    stack<Pair> st;
    Pair Tpair = Pair(node, 1);
    st.push(Tpair);

    string pre = "";
    string in = "";
    string post = "";

    while (st.size() > 0)
    {
        Pair top = st.top();
        if (top.state == 1)
        {

            pre += top.node->data;
            if (top.node != NULL)
            {
                Pair Tpair = Pair(top.node->left, top.state+1);
            }
            st.push(Tpair);

        }
        else if (top.state == 2)
        {
            in += top.node->data;
            if (top.node != NULL)
            {
                Pair Tpair = Pair(top.node->right, top.state+1);
            }
            st.push(Tpair);
        }
        else
        {
            post+=top.node->data;
            st.pop();
        }
    }

    cout<<pre<<endl;
    cout<<in<<endl;
    cout<<post<<endl;

}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(temp);
        }
    }
    Node *root = construct(arr);
    iterativePrePostInTraversal(root);
}