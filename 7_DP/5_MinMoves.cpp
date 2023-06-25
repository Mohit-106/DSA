#include<bits/stdc++.h>
using namespace std;

int cs(int arr[], int n, vector<int>& dp) {

  dp[dp.size()-1]=0;
  for(int i = dp.size()-1; i>=0; i--){
    if(arr[i]!=0){
      int minimum = INT_MAX;
      for(int jump = 1 ; jump<=arr[i] && i+jump < dp.size() ; jump++){
        
        if(dp[i+jump]!=-1){

          minimum = min(minimum,dp[i+jump]);

        }

      }
      if(minimum!=INT_MAX){
        dp[i]=minimum+1;
      }

    }

  }
  return dp[0];
}

int memo(int arr[], int n, vector<int>&dp, int idx){

  if(idx == n){
    dp[idx]=0;
    return 0;
  }
  if(dp[idx]!=-1){
    return dp[idx];
  }
  int moves = INT_MAX;
  for(int i=1;i<=arr[idx] && idx+i<=n; i++){
    if(i+idx==n){
      int val = memo(arr,n,dp,idx+i);
      moves = min(moves,val);
    }else if(arr[idx+i]!=0){
      int val = memo(arr,n,dp,idx+i);
      moves = min(moves,val);
    }
  }
  
  if(moves==INT_MAX){
    return dp[idx]=moves;
  }
  return dp[idx]=moves+1;
}



int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n + 1, -1);
  cout << cs(arr, n, dp) << endl;
  cout<<memo(arr,n,dp,0)<<endl;
}