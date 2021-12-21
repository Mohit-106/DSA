#include <bits/stdc++.h>
using namespace std;

void display(vector<int>&arr,int n, int i){

    if(n==0){
        return;
    }

    cout<<arr[i]<<endl;

    display(arr,n-1,i+1);

}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    display(arr,n,0);
}