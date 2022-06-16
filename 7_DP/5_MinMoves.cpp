// this is an important question
// In this question we have to store -1 at the cell from
// which there is no possible path
// if we will store 0 instead, code will not run for some test cases
// Because our base case is 0 and we assume there are a path througn 0

#include <bits/stdc++.h>
using namespace std;

int Memo(vector<int> &arr, int n, vector<int> &dp, int idx)
{

    if (idx == n)
    {
        dp[idx] = 0;
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int moves = INT_MAX;
    for (int i = 1; i <= arr[idx] && i + idx <= n; i++)
    {
        if (arr[idx + i] != -1)
        {
            int val = Memo(arr, n, dp, idx + i);
            if (val != -1)
            {

                moves = min(moves, val);
            }
        }
    }

    if (moves < INT_MAX)
    {
        int ans = moves + 1;
        dp[idx] = ans;
        return ans;
    }
    else
    {
        dp[idx] = -1;
        return -1;
    }
}

int tab(int n, vector<int> &arr)
{

    vector<int> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != -1)
        {
            int minimum = INT_MAX;
            for (int j = 1; j <= arr[i] && i + j <= n; j++)
            {
                if (dp[i + j] != -1)
                {

                    minimum = min(dp[i + j], minimum);
                }
            }
            if (minimum < INT_MAX)
            {
                dp[i] = minimum + 1;
            }
        }
        else
        {
            dp[i] = -1;
        }
    }
    for (int val : dp)
    {
        cout << val << " ";
    }
    cout << endl;

    return dp[0];
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n + 1, -1);
    cout << tab(n, arr) << endl;
    cout << Memo(arr, n, dp, 0) << endl;
    for(int val : dp){
        cout<<val<<" ";
    }

    return 0;
}