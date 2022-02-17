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

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string str = "";
    str += node->left == nullptr ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == nullptr ? "." : to_string(node->right->data) + "";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

// Post Order wala code fooot jayega
// Node *removeLeaves(Node *node)
// {

//     if (node == NULL)
//     {
//         return NULL;
//     }
//     Node *leftnode = removeLeaves(node->left);
//     Node *rightnode = removeLeaves(node->right);
//     if (node->left != NULL)
//     {
//         if (leftnode->left == NULL && leftnode->right == NULL)
//         {
//             node->left = NULL;
//         }
//     }

//     if(node->right != NULL){

//          if (rightnode->left == NULL && rightnode->right == NULL)
//         {
//             node->right = NULL;
//         }

//     }

//     return node;
// }

Node *removeLeaves(Node *node)
{

    if (node == NULL)
    {
        return NULL;
    }

    if (node->left == NULL && node->right == NULL)
    {
        return NULL;
    }

    node->left = removeLeaves(node->left);
    node->right = removeLeaves(node->right);

    return node;
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string inp;
        cin >> inp;
        if (inp != "n")
        {
            arr.push_back(stoi(inp));
        }
        else
        {
            arr.push_back(-1);
        }
    }

    Node *root = constructTree(arr);
    root = removeLeaves(root);
    display(root);
}