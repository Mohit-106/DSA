#include<bits/stdc++.h>
using namespace std;


void swap(vector<int> &arr, int i, int j){
    cout<<"Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int> &arr, int pivot, int lo, int hi){
    cout << "pivot -> " << pivot << endl;
    int curr = lo;
    int prev = lo - 1;
    while(curr <= hi){
        if(arr[curr] <= pivot){
            prev++;
            swap(arr, curr, prev);
        }
        curr++;
    }
    cout << "pivot index -> " << prev << endl;
    return prev;
}

void quicksort(vector<int> &arr, int lo, int hi){

    if(lo>hi){
        return;
    }

    int pivot=arr[hi];
    int idx = partition(arr,pivot,lo,hi);
    quicksort(arr,lo,idx-1);
    quicksort(arr,idx+1,hi);
}

void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << " ";
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    Display(arr);
    return 0;
}