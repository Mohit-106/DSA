#include <bits/stdc++.h>
using namespace std;

int  first(vector<int>&arr, int n, int i, int x){


    if(n==0){
        return -1;
    }

    if(arr[i]==x){
        return i;
    }

    first(arr,n-1,i+1,x);




}




int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int x;
    cin>>x;

    cout<<first(arr,n,0,x);

}
