#include <bits/stdc++.h>
using namespace std;

int rec(int n, vector<int> &dp)
{

    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }
    cout << n << endl;

    int p1 = rec(n - 1, dp);
    int p2 = rec(n - 2, dp);
    int p3 = rec(n - 3, dp);
    dp[n] = p1 + p2 + p3;
    return p1 + p2 + p3;
}

int tab(int n)
{
    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {

            dp[i] = 1;
        }
        else if (i == 1)
        {
            dp[i] = dp[i - 1];
        }
        else if (i == 2)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }
    return dp[n];
}

vector<string> GetPaths(int n)
{
    if (n == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    if (n < 0)
    {
        vector<string> base;
        return base;
    }

    vector<string> ans1 = GetPaths(n - 1);
    vector<string> ans2 = GetPaths(n - 2);
    vector<string> ans3 = GetPaths(n - 3);
    vector<string> mans;
    for (string str : ans1)
    {
        mans.push_back(to_string(1) + str);
    }
    for (string str : ans2)
    {
        mans.push_back(to_string(2) + str);
    }
    for (string str : ans3)
    {
        mans.push_back(to_string(3) + str);
    }

    return mans;
}

void Printpaths(int n, string asf)
{

    if (n == 0)
    {
        cout << asf << endl;
        return;
    }
    if (n < 0)
    {
        return;
    }

    Printpaths(n - 1, asf + to_string(1));
    Printpaths(n - 2, asf + to_string(2));
    Printpaths(n - 3, asf + to_string(3));
}

int PrintpathsMemo(int n, vector<int> &strg)
{

    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (strg[n] != 0)
    {
        return strg[n];
    }

    int p1 = PrintpathsMemo(n - 1, strg);
    int p2 = PrintpathsMemo(n - 2, strg);
    int p3 = PrintpathsMemo(n - 3, strg);
    int ans = p1 + p2 + p3;
    strg[n] = ans;
    return ans;
}

int main()
{

    int n;
    cin >> n;
    int tabAns, recAns;
    vector<int> dp(n + 1);
    recAns = rec(n, dp);
    tabAns = tab(n);
    cout << tabAns << endl;
    cout << recAns << endl;
    
}