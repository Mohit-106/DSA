#include <bits/stdc++.h>
using namespace std;

int SpanofArray(vector<int> &arr){
    int n = arr.size();
    int Max=INT_MIN;
    int Min=INT_MAX;


    for(int i=0;i<n;i++){
        Max=max(arr[i],Max);
        Min=min(arr[i],Min);

    }

    return(Max-Min);

}

void BarChart(vector<int>&arr){

    

}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }

    cout<<SpanofArray(arr)<<endl;
    BarChart(arr);




    return 0;
}