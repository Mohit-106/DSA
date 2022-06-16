#include <bits/stdc++.h>
using namespace std;

int Tab(int n, vector<int> &arr)
{
    vector<int> dp(n + 1);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int count = 0;
        for (int j = 1; j <= arr[i] && j + i < dp.size(); j++)
        {
            count += dp[i + j];
        }
        dp[i] = count;
    }
    for (int val : dp)
    {
        cout << val << " ";
    }
    return dp[0];
}

int Memo(int n, vector<int> &arr, vector<int> &dp, int idx)
{

    if (arr[idx] == 0)
    {
        return 0;
    }
    if (idx == n)
    {
        dp[n] = 1;
        return 1;
    }

    if (dp[idx] != 0)
    {
        return dp[idx];
    }

    int ans = 0;
    for (int i = 1; i <= arr[idx] && i + idx <= n; i++)
    {
        ans += Memo(n, arr, dp, idx + i);
    }
    dp[idx] = ans;
    return ans;
}

vector<string> PrintPaths(int n, vector<int> &arr, int idx)
{
    if(arr[idx] == 0){

        vector<string> base;
        return base;
        
    }

    if (idx == n)
    {
        vector<string> base;
        base.push_back("");
        return base;

    }

    vector<string> mstr;
    for (int i = 1; i <= arr[idx] && i + idx <= n; i++)
    {
        
        vector<string> str = PrintPaths(n, arr, idx + i);
        for(string s : str){
            mstr.push_back(s + to_string(i));
        }

    }

    return mstr;

    
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
    // vector<int> dp(n + 1);
    // cout<<Tab(n,arr)<<endl;
    // cout << Memo(n, arr, dp, 0) << endl;
    // for (int val : dp)
    // {
    //     cout << val << " ";
    // }

    //----------------------Print Paths--------------//

    vector<string> ans = PrintPaths(n,arr,0);
    for(string str : ans){
        cout<<str<<endl;
    }



    return 0;
}