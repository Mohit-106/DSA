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

class Pair
{
public:
    Node *node = nullptr;
    int state = 0;
    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
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

void iterativePrePostInTraversal(Node *node)
{
    Pair *p = new Pair(node, 1);
    stack<Pair *> st;
    st.push(p);
    string pre = "";
    string in = "";
    string post = "";

    while (st.size() > 0)
    {

        Pair *top = st.top();

        if (top->state == 1)  // Pre,state++,add left
        {

            pre += to_string(top->node->data)+" ";
            top->state++;
            if (top->node->left != NULL)
            {

                Pair *p = new Pair(top->node->left, 1);
                st.push(p);
            }
        }
        else if (top->state == 2) // in, state++,add right
        {
            in += to_string(top->node->data)+" ";
            top->state++;
            if (top->node->right != NULL)
            {

                Pair *p = new Pair(top->node->right, 1);
                st.push(p);
            }
        }
        else  // Post,Pop
        {
            post += to_string(top->node->data)+" ";
            st.pop();
        }
    }

    cout << pre << endl;
    cout << in << endl;
    cout << post << endl;
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