#include <bits/stdc++.h>
using namespace std;

int Vjumps(int n, vector<int>&arr){

    vector<int>dp(n+1);
    dp[n]=1;

    for(int i=n-1; i>=0; i--){

        for(int j=i+1; j<=arr[i];j++){
            dp[i]+=dp[j];
        }


    }

    return dp[0];

    


}

int main()
{

    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<Vjumps(n,arr);

    return 0;
}