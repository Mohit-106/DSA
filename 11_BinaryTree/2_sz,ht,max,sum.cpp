#include <iostream>
#include <climits>
#include <string.h>
#include <vector>

using namespace std;

// structure of node
class Node
{
public:
    int data;
    Node *left ;
    Node *right ;
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
    if (node == nullptr)return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

int size(Node *node)
{

    if (node == NULL)
        return 0;
    int ls = size(node->left);
    int rs = size(node->right);
    return ls + rs + 1;

    //one line code
    //return (node==NULL? 0: size(node->left)+size(node->right)+1);
}

int height(Node *node)  
{

    if(node==NULL) return -1;
    int lm=height(node->left);
    int rm=height(node->right);

    return (max(lm,rm)+1);


    
}

int maximum(Node *node)
{
    if(node==NULL) return 0;
    int lm=maximum(node->left);
    int rm=maximum(node->right);
    
    return max(node->data, max(lm,rm));



}

int sum(Node *node)
{

    if(node==NULL)return 0;

    int ls=sum(node->left);
    int rs=sum(node->right);

    return ls+rs+node->data;

    // return (node==NULL? 0 : sum(node->left)+sum(node->right)+node->data);
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

    Node *root = constructTree(arr);

    int sz1 = size(root);
    int sm = sum(root);
    int max = maximum(root);
    int ht = height(root);
    cout << sz1 << endl;
    cout << sm << endl;
    cout << max << endl;
    cout << ht << endl;
}

