#include <bits/stdc++.h>
using namespace std;

void ArraySubtraction(vector<int>&arr1, vector<int>&arr2){

    int n=arr1.size();
    int m=arr2.size();
    int s=max(n,m);

    vector<int>ans(s);

    int i=n-1,j=m-1,k=s-1,borrow=0;
 

    while(k>=0){
        int sub=borrow;
        sub+=arr2[j];
        if(i>=0){
            sub-=arr1[i];
        }
        
            
        

        if(sub<0){
            sub+=10;
            borrow=-1;

        }else{
            borrow=0;
        }

        ans[k]=sub;
        k--,j--,i--;

    }

   int idx=0;
   while(idx<s){
       if(ans[idx]==0){
           idx++;

       }else{
           break;

       }
   }

   while(idx<s){
       
       cout<<ans[idx]<<endl;
       idx++;
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

    ArraySubtraction(arr1,arr2);



    return 0;
}



