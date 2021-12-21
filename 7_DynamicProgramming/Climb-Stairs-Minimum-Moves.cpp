#include <bits/stdc++.h>
using namespace std;

int MinMoves(vector<int>&arr){

    int n= arr.size();

    vector<int>dp(n+1);

    dp[n]=0;

    for(int i=n; i>=0; i--){
        
    }

}

int main()
{

    int n;
    cin >> n;
    vector<int > arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans=MinMoves(arr);
    cout<<ans<<endl;
   

    return 0;
}