#include <bits/stdc++.h>
using namespace std;

int operation(char ch, int v1, int v2)
{
    if (ch == '-')
    {

        return v1 - v2;
    }
    else if (ch == '+')
    {
        return v1 + v2;
    }
    else if (ch == '/')
    {
        return v1 / v2;
    }
    else if (ch == '*')
    {
        return v1 * v2;
    }
}

void EvaluateVS(char ch, stack<int> &st)
{

    int v2 = st.top();
    st.pop();
    int v1 = st.top();
    st.pop();
    int ans = operation(ch, v1, v2);
    st.push(ans);
}

void EvaluateIS(char ch, stack<string> &st)
{

    string v2 = st.top();
    st.pop();
    string v1 = st.top();
    st.pop();
    string op(1, ch);
    st.push("(" + v1 + op + v2 + ")");
}

void EvalustePS(char ch, stack<string> &st)
{

    string v2 = st.top();
    st.pop();
    string v1 = st.top();
    st.pop();
    string op(1, ch);
    st.push(op + v1 + v2);
}

int main()
{

    string str;
    getline(cin, str);
    stack<int> vs;
    stack<string> is;
    stack<string> ps;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {

            EvaluateVS(ch, vs);
            EvaluateIS(ch, is);
            EvalustePS(ch, ps);
        }
        else
        {
            vs.push(ch - '0');
            string s1(1, ch);
            is.push(s1);
            ps.push(s1);
        }
    }

    cout<<vs.top()<<endl;
    cout<<is.top()<<endl;
    cout<<ps.top()<<endl;

    return 0;
}