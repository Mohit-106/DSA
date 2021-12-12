#include <bits/stdc++.h>
using namespace std;

string compression2(string str)
{

    string ans;
    ans.push_back(str[0]);
    int n = str.size();
    int count = 1;

    for (int i = 1; i < n; i++)
    {

        char curr = str[i];
        char prev = str[i - 1];

        if (curr == prev)
        {
            count++;
        }
        else
        {

            if (count > 1)
            {

                ans += to_string(count);
                count = 1;
            }
            ans += curr;
        }

    }

    if (count > 1)
    {

        ans += to_string(count);
    }

    return ans;
}

string compression1(string str)
{

    string ans;
    ans.push_back(str[0]); 
    int n = str.size();

    for (int i = 1; i < n; i++)
    {

        char curr = str[i];
        char prev = str[i - 1];
        if (curr != prev)
        {
            ans += curr;
        }
    }

    return ans;
}

int main()
{

    string str;
    cin >> str;
    cout<<compression1(str)<<endl;
    cout << compression2(str);

    return 0;
}