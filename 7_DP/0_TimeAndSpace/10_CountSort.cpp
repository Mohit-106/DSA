#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

void countsort(vector<int> &arr, int max, int min){
    int range = max-min+1;
    vector<int>freq(range);
    for(int i=0;i<range;i++){

        int idx = arr[i]-min;
        freq[idx]++;

    }
    vector<int>pfix(range);
    pfix[0]=freq[0];
    for(int i=1;i<range;i++){
        pfix[i]=pfix[i]+pfix[i-1];
    }
    vector<int>ans(arr.size());
    for(int i=arr.size()-1; i>=0; i--){
        int idx = arr[i]-min;
        int aidx = pfix[idx]-1;
        ans[aidx]=arr[i];
    }  
}

void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << endl;
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    
    for(int i = 0; i < n; i++){    
        cin >> arr[i];
    }
    
    int maxi = (int)-1e9;
    int mini = (int)1e9;
    
    for(int i = 0; i < n; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    
    countsort(arr, maxi, mini);
    Display(arr);
    
}