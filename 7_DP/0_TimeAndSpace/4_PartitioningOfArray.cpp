#include<bits/stdc++.h>
using namespace std;


void swap(int arr[],int i,int j){
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void partition(int arr[],int n,int pivot){
    int i =0;
    int j=0;
    while(i<n){
        if(arr[i]<=pivot){
            swap(arr,i,j);
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    
}

void partition2(int arr[], int n, int pivot){

    int i=0;
    int j=n-1;
    while(i<=j){
        if(arr[i]<=pivot){
            i++;
        }else if(arr[i]>pivot && arr[j]<=pivot){
            swap(arr,i,j);
            i++;
            j--;
        }else{
            j--;
        }
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int pivot;
    cin>>pivot;
    
    partition(arr,n,pivot);
    print(arr,n);
    // cout<<"------"<<endl;
    // partition2(arr,n,pivot);
    // print(arr,n);
}