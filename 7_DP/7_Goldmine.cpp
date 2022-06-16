#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Goldmine(vector<vector<int>> &arr, int n, int m)
{

    vector<vector<int>> dp(n, vector<int>(m));
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (j == m - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == n - 1)
            {
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            }
            else if (i == 0)
            {
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            }
            else
            {
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1]));
            }
        }
    }

    int ans = dp[0][0];
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i][0]);
    }
    cout << ans << endl;
    return dp;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> ans = Goldmine(arr, n, m);
    for (vector<int> v : ans)
    {
        for (int val : v)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}