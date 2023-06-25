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



class Solution {
public:
    bool isPossibleToCutPath(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        std::vector<std::vector<int>> dp1(m + 1, std::vector<int>(n + 1, 0));
        dp1[1][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i-1][j-1]) {
                    dp1[i][j] += dp1[i-1][j] + dp1[i][j-1];
                }
            }
        }

        std::vector<std::vector<int>> dp2(m + 1, std::vector<int>(n + 1, 0));
        dp2[m-1][n-1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j]) {
                    dp2[i][j] += dp2[i+1][j] + dp2[i][j+1];
                }
            }
        }

        int target = dp1[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i != 0 || j != 0) && (i != m-1 || j != n-1)) {
                    if (dp1[i+1][j+1] * dp2[i][j] == target) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
