#include <bits/stdc++.h>
using namespace std;


void SumofTwoArrays(vector<int>&arr1, vector<int>&arr2){

    int n=arr1.size();
    int m=arr2.size();
    int ansSize=max(n,m);


    int i=n-1;
    int j=m-1;
    int k=ansSize-1;
    int carry=0;

    vector<int>ans(ansSize);

    while(k>=0){

        int sum=carry;
        if(i>=0){
            sum+=arr1[i];
        }
        if(j>=0){
            sum+=arr2[j];
        }

        carry=sum/10;
        sum%=10;
        ans[k]=sum;
        k--,j--,i--;

    }
    if(carry>0){
        cout<<carry<<endl;
    }

    for(int value: ans){
        cout<<value<<endl;
    }



    

}




int main(){

    int n,m;
    cin>>n;
    vector<int>arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    cin>>m;
    vector<int>arr2(m);
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    SumofTwoArrays(arr1,arr2);



    
    return 0;
}


// 5
// 3
// 1
// 0
// 7
// 5
// 6
// 1
// 1
// 1
// 1
// 1
// 1