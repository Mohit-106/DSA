#include <bits/stdc++.h>
using namespace std;

void SlidingWindow(vector<int>&arr, int k){

    int n= arr.size();
    vector<int>nge(n);
    nge[n-1]=n;
    stack<int>st;
    st.push(n-1);
    
    for(int i=n-1; i>=0; i--){

        while(st.size()>0 && arr[i]>arr[st.top()]){
            st.pop();
        }
        if(st.size()==0){
            nge[i]=n;
        }else{
            nge[i]=st.top();
        }
        st.push(i);
    }
    int j=0;
    for(int i=0;i<=n-k; i++){
        if(i>j){
            j=i;
        }
        while(nge[j]<=k+i-1){
            j=nge[j];
        }
        cout<<arr[j]<<endl;

    }




}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    SlidingWindow(arr,k);
}