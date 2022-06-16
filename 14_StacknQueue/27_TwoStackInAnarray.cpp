#include <bits/stdc++.h>

using namespace std;

class TwoStack
{
public:
    vector<int> data;
    int tos1;
    int tos2;

    TwoStack(int cap)
    {

        data.resize(cap);
        tos1 = -1;
        tos2 = cap;
    }

    int size1()
    {
        return tos1 + 1;
    }

    int size2()
    {
        return data.size() - tos2;
    }

    void push1(int val)
    {
        if (tos1 + 1 == tos2)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        data[++tos1] = val;
    }

    void push2(int val)
    {
        if (tos1 + 1 == tos2)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        data[--tos2] = val;
    }

    int pop1()
    {
        if (tos1 == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return data[tos1--];


    }

    int pop2()
    {
         if (tos2 == data.size())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return data[tos2++];
    }

    int top1()
    {
        if (tos1 == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return data[tos1];
    }

    int top2()
    {
        if (tos2 == data.size())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return data[tos2];
    }
};

int main()
{
    string str;

    int cap;
    cin >> cap;
    TwoStack st(cap);

    while (true)
    {
        getline(cin, str);
        if (str[0] == 'q')
        {
            break;
        }
        else if (str[0] == 'p' && str[4] == '1')
        {
            string ss = str.substr(6, 2);
            int n = stoi(ss);
            st.push1(n);
        }
        else if (str[0] == 't' && str[3] == '1')
        {
            int tp = st.top1();
            if (tp != -1)
                cout << tp << endl;
        }
        else if (str[0] == 'p' && str[3] == '1')
        {
            int tp = st.pop1();
            if (tp != -1)
                cout << tp << endl;
        }
        else if (str[0] == 'p' && str[4] == '2')
        {
            string ss = str.substr(6, 2);
            int n = stoi(ss);
            st.push2(n);
        }
        else if (str[0] == 't' && str[3] == '2')
        {
            int tp = st.top2();
            if (tp != -1)
                cout << tp << endl;
        }
        else if (str[0] == 'p' && str[3] == '2')
        {
            int tp = st.pop2();
            if (tp != -1)
                cout << tp << endl;
        }
    }
    return 0;
}