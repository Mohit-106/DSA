#include <bits/stdc++.h>
using namespace std;

class QueueToStackAdapter
{
public:
    queue<int> mainQ;
    queue<int> helperQ;

    int size()
    {
        return mainQ.size();
    }

    void push(int data)
    {
        mainQ.push(data);
    }

    int top()
    {
        if (mainQ.size() == 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        while (mainQ.size() > 1)
        {

            helperQ.push(mainQ.front());
            mainQ.pop();
        }
        int val = mainQ.front();
        mainQ.pop();
        helperQ.push(val);
        while (helperQ.size() > 0)
        {
            mainQ.push(helperQ.front());
            helperQ.pop();
        }
        return val;
    }

    int pop()
    {
        if (mainQ.size() == 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        while (mainQ.size() > 1)
        {

            helperQ.push(mainQ.front());
            mainQ.pop();
        }
        int val = mainQ.front();
        mainQ.pop();
        while (helperQ.size() > 0)
        {
            mainQ.push(helperQ.front());
            helperQ.pop();
        }
        return val;
    }
};

int main()
{
    QueueToStackAdapter st;
    string str;
    cin >> str;

    while (str != "quit")
    {
        if (str == "push")
        {
            int val;
            cin >> val;
            st.push(val);
        }
        else if (str == "pop")
        {
            int val = st.pop();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "top")
        {
            int val = st.top();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "size")
        {
            cout << st.size() << endl;
        }
        cin >> str;
    }
    return 0;
}