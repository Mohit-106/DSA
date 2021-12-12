#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    arr.erase(arr.begin()+4); // to erase element from specific position

    for(auto value:arr){
        cout<<value<<endl;
    }

}