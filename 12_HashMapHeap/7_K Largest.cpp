#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>k;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){

        if(i<k){
            pq.push(v[i]);
        }else if(v[i]>pq.top()){
           
                pq.pop();
                pq.push(v[i]);

        }
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;




}