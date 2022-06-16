#include <bits/stdc++.h>
using namespace std;

int Goldmine(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp)
{

    if (j == arr[0].size() - 1)
    {
        return arr[i][j];
    }

    if(dp[i][j]!=0){
        return dp[i][j];
    }

    

    if (i == 0)
    {

        int val1 = Goldmine(arr, i, j + 1, dp);
        int val2 = Goldmine(arr, i + 1, j + 1, dp);
        int maxVal =  arr[i][j]+max(val1,val2);
        dp[i][j]=maxVal;
        return (maxVal);

    }
    else if (i == arr.size() - 1)
    {
        int val1 = Goldmine(arr, i, j + 1, dp);
        int val2 = Goldmine(arr, i - 1, j + 1, dp);
        int maxVal =  arr[i][j]+ max(val1, val2);
        dp[i][j]=maxVal;
        return (maxVal);
    }
    else
    {

        int val1 = Goldmine(arr, i, j + 1, dp);
        int val2 = Goldmine(arr, i + 1, j + 1, dp);
        int val3 = Goldmine(arr, i - 1, j + 1, dp);
        int maxVal =  arr[i][j]+max(val1, max(val2, val3));
        dp[i][j]=maxVal;
        return (maxVal);

    }
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

    vector<vector<int>> dp(n, vector<int>(m));
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        int cval = Goldmine(arr, i, 0, dp);
        ans = max(ans, cval);

    }

    cout << ans << endl;
    return 0;
    
}