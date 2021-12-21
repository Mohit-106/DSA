#include <bits/stdc++.h>
using namespace std;
int Goldmine(vector<vector<int>> &arr)
{

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> dp(n, vector<int>(m));

    for (int c = m - 1; c >= 0; c--)
    {

        for (int r = n-1; r >= 0; r--)
        {
            

            if (c == m - 1)
            {
                dp[r][c]=arr[r][c];
            }
            else if (r == n - 1)
            {
                dp[r][c]=arr[r][c]+max(dp[r][c+1],dp[r-1][c+1]);

            }
            else if (r == 0)
            {
                dp[r][c]=arr[r][c]+max(dp[r][c+1],dp[r+1][c+1]);
            }
            else
            {
               
                int max2=max(max(dp[r][c+1],dp[r-1][c+1]),dp[r+1][c+1]);

                dp[r][c]=arr[r][c]+max2;
            }
        }
    }

    int ans=INT_MIN;
    for(int r=0; r<=n-1; r++){
        ans=max(ans,dp[r][0]);

    }

    return ans;


}

int main()
{

    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << Goldmine(arr);

    return 0;
}