#include <iostream>
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
        node *temp= new node;
        temp->data = n;
        temp->next = NULL;

        if (head == NULL)
        {

            head = temp;
            tail = temp;
        }
        else
        {

            tail->next = temp;
            tail = tail->next;
        }
        size++;
    }
    void display()
    {

        for (node *i = head; i != NULL; i = i->next)  // print a linked list
        {
            cout << i->data<<" "<< endl;
        }
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
        if (str[0] == 'a')
        {
            string ss = str.substr(8, 2);
            int n = stoi(ss);
            l.addLast(n);
        }
    }

    l.testList();
    return 0;
}