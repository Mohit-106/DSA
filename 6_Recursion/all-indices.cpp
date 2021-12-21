#include <bits/stdc++.h>
using namespace std;

void allwithoutusingsapce(vector<int>&arr, int n, int i, int x){
    

    if(i==n){
        return;
    }
    if(arr[i]==x){
        cout<<i<<endl;
    }

    allwithoutusingsapce(arr,n,i+1,x);

}

int all(vector<int>&arr, int n, int i, int x){
    

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

    allwithoutusingsapce(arr,n,0,x);

}
