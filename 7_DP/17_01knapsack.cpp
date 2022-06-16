//no of items ->> runs
//wt->>balls
//Capacity of knapsack == match with no of balls

#include <bits/stdc++.h>

using namespace std;

int Knapsack(int n , vector<int>&runs, vector<int>&balls, int k){

    vector<vector<int>> dp(n+1,vector<int>(k+1));

    for(int i=1;i<=n;i++){

        for(int j=1;j<=k;j++){

            int idx = i-1; // for val in arrays
            int run = runs[idx];
            int ball = balls[idx];
            if(j>=ball){
                int val = run+dp[i-1][j-ball];
                dp[i][j]=max(val,dp[i-1][j]);

            }else{
                dp[i][j]=dp[i-1][j];
            }

        }

    }
    // for(vector<int> &v : dp){

    //     for(int val : v){
    //         cout<<val<<" ";
    //     }
    //     cout<<endl;
        
    // }

    return dp[n][k];




}

int main(){

    int n;
    cin>>n;
    vector<int>val(n);
    vector<int>wt(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int k;
    cin>>k;

    int ans = Knapsack(n,val,wt,k);
    cout<<ans;


    return 0;
}