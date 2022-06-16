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

    void reversePRHelper(Node *h)
    {
        if (h == NULL)
        {
            return;
        }
        reversePRHelper(h->next);
        if (h == this->tail)
        {
            // DO Nothing!!
        }
        else
        {
            h->next->next = h; // mere next ka next  main hi hun
        }
    }

    void reversePR()
    {

        reversePRHelper(this->head);
        Node *temp = head;
        head = tail;
        tail = temp;
    }

    Node *left;

    bool IsPallindromeHelper(Node *h, int state)
    {
        if (h == NULL)
        {
            return true;
        }

        bool check = IsPallindromeHelper(h->next, state + 1);
        if (state >= this->sz / 2)
        {
            if (check == false)
            {
                return false;
            }
            else if (h->data != left->data)
            {
                return false;
            }
            else
            {
                left = left->next;
                return true;
            }
        }else{
            return check;
        }
    }

    bool IsPallindrome()
    {
        
        left = this->head;
        return IsPallindromeHelper(this->head, 0);

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
    bool ans = l1->IsPallindrome();
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}