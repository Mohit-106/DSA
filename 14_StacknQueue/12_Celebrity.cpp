#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<string>&v)
{

    int n = v.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }


    while (st.size() > 1)
    {
        int v1 = st.top();
        st.pop();
        int v2 = st.top();
        st.pop();

        if (v[v1][v2] == '1')
        {
            st.push(v2);

        }else
        {
            st.push(v1);
        }
        
    }


    int win = st.top();
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (win != i)
        {
            if (v[win][i] == '1' || v[i][win] == '0')
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        return win;
    }
    else
    {
        return -1;
    }
}

int main()
{

    int n;
    cin >> n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int ans = celebrity(s);
    if (ans != -1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "none" << endl;
    }

    return 0;
}
