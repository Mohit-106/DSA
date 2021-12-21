#include <bits/stdc++.h>
using namespace std;

void Msum(vector<int>&arr, int n){

    int inc=arr[0],exc=0;

    for(int i=1;i<n;i++){

        int inc1=arr[i]+exc;
        int exc1=max(inc,exc);

        inc=inc1;
        exc=exc1;


    }

    cout<<max(inc,exc)<<endl;





}


int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Msum(arr,n);


    return 0;
}