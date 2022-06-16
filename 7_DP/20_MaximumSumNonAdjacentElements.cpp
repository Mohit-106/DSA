#include <bits/stdc++.h>
using namespace std;

int maxSum(int n,vector<int>& arr){

    int inc = arr[0];
    int exe = 0;

    for(int i=1;i<n;i++){
        int ninc = arr[i]+exe;
        int nexe = max(inc,exe);
        inc = ninc;
        exe = nexe;
    }
    return max(inc,exe);

}


int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<maxSum(n,arr);
    return 0;

}