#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linked_list
{
public:
    node *head, *tail;
    int size = 0;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void addLast(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        size++;
    }
    void display()
    {
        node *temp = new node();
        temp = head;
        while (temp != NULL)
        {

            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void displayfor()
    {
       for(node * temp = head; temp!=NULL ; temp=temp->next){
           cout<<temp->data<<" ";
       }
       cout<<endl;
    }

    void testList()
    {
        for (node *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << endl;
        }
        cout << size << endl;

        if (size > 0)
        {
            cout << tail->data << endl;
        }
    }
};

int main()
{

    string str;
    linked_list l;
    while (true)
    {
        getline(cin, str);
        if (str[0] == 'q')
        {
            break;
        }
        else if (str[0] == 'a')
        {
            string ss = str.substr(8, 2);
            int n = stoi(ss);
            l.addLast(n);
        }
        else if (str[0] == 's')
        {
            cout << l.size << endl;
        }
        else if (str[0] == 'd')
        {
            l.displayfor();
        }
    }

    return 0;
}