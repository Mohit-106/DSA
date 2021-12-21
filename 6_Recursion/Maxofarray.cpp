#include <bits/stdc++.h>
using namespace std;

int  MAX(vector<int>&arr, int n, int i){


    if(n==1){
        return arr[i];
    }



    int m =MAX(arr,n-1,i+1);
    m = max(m,arr[i]);
    return m;




}




int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<MAX(arr,n,0);

}