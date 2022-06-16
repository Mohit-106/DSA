#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{

    if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void Evaluate(stack<string> &st1, stack<string> &st2, stack<char> &ost)
{

    string pre2 = st1.top();
    st1.pop();
    string pre1 = st1.top();
    st1.pop();
    string post2 = st2.top();
    st2.pop();
    string post1 = st2.top();
    st2.pop();
    string op(1, ost.top());
    ost.pop();
    string preval = (op + pre1 + pre2);
    string postval = (post1 + post2 + op);
    st1.push(preval);
    st2.push(postval);
}

void Convertor(string str)
{

    stack<string> st1;
    stack<string> st2;
    stack<char> ost;

    for (int i = 0; i < str.size(); i++)
    {

        char ch = str[i];

        if (ch == '(')
        {
            ost.push(ch);
        }
        else if (ch == ')')
        {
            while (ost.size() > 0 && ost.top() != '(')
            {
                Evaluate(st1, st2, ost);
            }
            ost.pop();
        }
        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            string s(1, ch);
            st1.push(s);
            st2.push(s);
        }
        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {

            while (ost.size() > 0 && ost.top() != '(' && precedence(ch) <= precedence(ost.top()))
            {
                Evaluate(st1, st2, ost);
            }
            ost.push(ch);
        }
    }

    while (ost.size() > 0)
    {
        Evaluate(st1, st2, ost);
    }

    string preans = st1.top();
    string postans = st2.top();
    cout << postans << endl;
    cout << preans << endl;
}

int main()
{

    string str;
    getline(cin, str);
    Convertor(str);
}