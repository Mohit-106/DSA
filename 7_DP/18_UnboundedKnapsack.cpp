#include <bits/stdc++.h>
using namespace std;

int Knapsack(int n , vector<int>&runs, vector<int>&balls, int k){

    //Home Work

    



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