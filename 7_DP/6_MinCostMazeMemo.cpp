#include <bits/stdc++.h>
using namespace std;

int MinCostMemo(vector<vector<int>> &arr, int n, int m, vector<vector<int>> &dp, int i, int j)
{

    if (i > n - 1 || j > m - 1)
    {
        return INT_MAX;
    }
    if (i == n - 1 && j == m - 1)
    {
        dp[i][j]=arr[i][j];
        return arr[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int val1 = MinCostMemo(arr, n, m, dp, i + 1, j);
    int val2 = MinCostMemo(arr, n, m, dp, i, j + 1);
    int ans = arr[i][j] + min(val1,val2);
    dp[i][j] = ans;
    return ans;

}

int MinCost(vector<vector<int>> &arr, int n, int m)
{

    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            if (i == n - 1 && j == m - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == n - 1)
            {
                dp[i][j] = dp[i][j + 1] + arr[i][j];
            }
            else if (j == m - 1)
            {

                dp[i][j] = dp[i + 1][j] + arr[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + arr[i][j];
            }
        }
    }
    // for (vector<int> &v : dp)
    // {
    //     for (int &val : v)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    return dp[0][0];
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
    vector<vector<int>> dp(n, vector<int>(m,-1));

    cout << MinCost(arr, n, m) << endl;
    // cout << MinCostMemo(arr, n, m, dp, 0, 0) << endl;
    // for(vector<int>& v : dp){
    //     for(int &val : v){
    //         cout<<val<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}