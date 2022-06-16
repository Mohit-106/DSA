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
        for (Node *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }
    void removeFirst()
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (sz == 1)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
        }

        sz--;
    }
    int getFirst()
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        return head->data;
    }
    int getLast()
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        return tail->data;
    }
    int getAt(int idx)
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else if (idx < 0 || idx > sz - 1)
        {
            cout << "Invalid arguments" << endl;
            return -1;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i <= idx; i++)
            {
                temp = temp->next;
            }
            return temp->data;
        }
    }
    void addFirst(int val)
    {
        if (sz == 0)
        {
            addLast(val);
        }
        else
        {
            Node *node = new Node();
            node->data = val;
            node->next = head;
            head = node;
            sz++;
        }
    }
    void addAt(int idx, int val)
    {
        if (idx < 0 || idx > sz)
        {
            cout << "Invalid arguments" << endl;
            return;
        }
        if (idx == 0)
        {

            addFirst(val);
        }
        else if (idx == sz)
        {

            addLast(val);
        }
        else
        {

            Node *node = new Node();
            node->data = val;
            Node *temp = head;
            for (int i = 1; i < idx; i++)
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
            sz++;
        }
    }
    void removeLast()
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        sz--;
    }
    void removeAt(int idx)
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (idx < 0 || idx >= sz)
        {
            cout << "Invalid arguments" << endl;
            return;
        }
        if (idx == 0)
        {
            removeFirst();
        }
        else if (idx == sz - 1)
        {
            removeLast();
        }
        else
        {

            Node *temp = new Node();
            temp = head;
            for (int i = 1; i < idx; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            sz--;
        }
    }

    void reversePI()
    {
        if (sz == 1)
        {
            return;
        }
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node *t = tail;
        tail = head;
        head = t;
    }

    void removeDuplicates()
    {

        LinkedList *list = new LinkedList();
        Node *p1 = this->head;
        Node *p2 = list->head;
        while (p1 != NULL)
        {
            if (list->sz == 0)
            {
                int data = p1->data;
                this->removeFirst();
                list->addLast(data);
                p2 = list->head;
                p1 = p1->next;
            }
            else
            {
                if (p1->data != p2->data)
                {
                    int data = p1->data;
                    this->removeFirst();
                    list->addLast(data);
                    p1 = p1->next;
                    p2 = p2->next;
                }
                else
                {
                    p1 = p1->next;
                }
            }
        }
        this->head = list->head;
        this->tail = list->tail;
        this->sz = list->sz;
    }
};

int main()
{
    LinkedList *l1 = new LinkedList();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        l1->addLast(data);
    }
    l1->display();
    l1->removeDuplicates();
    l1->display();

    return 0;
}