#include <bits/stdc++.h>
using namespace std;

int Combination(vector<int> &coins, int tar)
{

    int n = coins.size();
    int m= tar+1;
    vector<int> dp(m,0);
    dp[0] = 1;

    for (int coin: coins)
    {
        for (int j = coin; j<m ; j++)
        {

            dp[j]+=dp[j-coin];

        }
    }
    
    return dp[m-1];
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int tar;
    cin >> tar;
    cout << Combination(arr, tar);

    return 0;
}