#include <bits/stdc++.h>
using namespace std;

void SOW2( vector<vector<int>>&arr){

    int n=arr.size();
    

    for(int gap=0; gap<n; gap++){

        for(int i=0,j=gap;j<n;i++,j++){
            cout<<arr[i][j]<<endl;
        }
    }



}


int main()
{

    int n;
    cin >> n ;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    SOW2(arr);
  
    return 0;

}