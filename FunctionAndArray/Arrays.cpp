#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>&arr , int i , int j){

    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;

}

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

int MaxNo(vector<int>&arr){

    int n=arr.size();
    int Max=INT_MIN;
    for(int i=0;i<n;i++){
        Max=max(arr[i],Max);
        
    }
    return Max;

}

void BarChart(vector<int>&arr){
    int n=arr.size();

    int rowNo=MaxNo(arr);
    int colNo=n;

    int val=rowNo;

    for(int r=1;r<=rowNo;r++){

        for(int c=0;c<colNo;c++){
            if(val>=arr[c]){
                cout<<"*\t";
            }else{
                cout<<"\t";
            }
        }
        val--;
        cout<<endl;

    }
}

void Reverse(vector<int>&arr){

    int n= arr.size();
    int i=0;
    int j=n-1;
    while(i<=j){
        swap(arr,i,j);
        i++;
        j--;
    }

}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }

    // BarChart(arr);

    // cout<<SpanofArray(arr)<<endl;

    Reverse(arr);
    

    for(int value:arr){

        cout<<value<<" ";

    }




    return 0;
}