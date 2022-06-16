#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
public:
    Node *head;
    Node *tail;
    int sz = 0;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void addLast(int val)
    {
        Node *temp = new Node();
        temp->data = val;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        sz++;
    }
    int size()
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
    void display()
    {
        for (Node *temp; temp != NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        // cout << endl;
    }
    void removeFirst()
    {
    }
    int getFirst()
    {
    }
    int getLast()
    {
    }
    int getAt(int idx)
    {
    }
    void addFirst(int val)
    {
    }
    void addAt(int idx, int val)
    {
    }
    void removeLast()
    {
    }
    void removeAt(int idx)
    {
    }
    void testList()
    {
        for (Node *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << endl;
        }
        cout << sz << endl;

        if (sz > 0)
        {
            cout << tail->data << endl;
        }
    }
};

int main()
{

    string str;
    LinkedList l;
    while (true)
    {
        getline(cin, str);
        if (str[0] == 'q')
        {
            break;
        }
        if (str[0] == 'a')
        {
            string ss = str.substr(8, 2);
            int n = stoi(ss);
            l.addLast(n);
        }
    }

    l.testList();
    return 0;

    return 0;
}