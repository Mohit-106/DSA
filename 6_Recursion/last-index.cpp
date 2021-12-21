#include <bits/stdc++.h>
using namespace std;

int  last(vector<int>&arr, int n, int i, int x){


    if(i==n){

        return -1;
        
    }

    int idx = last(arr,n,i+1,x);
     if(idx==-1){

         if(arr[i]==x){
            return i;
         }else{
             return -1;
         }
     }else{
         return idx;
     }
   
        
       
 






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

    cout<<last(arr,n,0,x);

}
