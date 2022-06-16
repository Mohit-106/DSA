#include<bits/stdc++.h>
using namespace std;


bool isSmaller(int arr[],int i,int j ){
    cout<<"Comparing "<<arr[i]<<" and "<<arr[j]<<endl;
    if(arr[i]<arr[j]){
        return true;
    }else{
        return false;
    }
}

void swap(int arr[],int i,int j){
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
}


void bubbleSort(int arr[],int n){

    for(int j=1;j<=n-1;j++){

        for(int i=0;i<n-j;i++){

            if(isSmaller(arr,i+1,i)){
                swap(arr,i+1,i);
            }
        }
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}



int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    bubbleSort(arr,n);
    print(arr,n);
    
}