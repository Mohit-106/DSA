#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> v1 , const vector<int> v2){
     return v1[0]<v2[0];
 }

void mergeIntervals(vector<vector<int>>&arr){
    sort( arr.begin(), arr.end() ,compare);
    stack<vector<int>>st;
    st.push(arr[0]);
    for(int i=1;i<arr.size();i++){
        vector<int> m1 = st.top();
        st.pop();
        vector<int>m2 = arr[i];
        int s1 = m1[0];
        int e1 = m1[1];
        int s2 = m2[0];
        int e2 = m2[1];


        if(e1>=s2){
            vector<int>merge{s1,max(e1,e2)};
            st.push(merge);

        }else{

           st.push(m1);
           st.push(m2);

        }

    }
    stack<vector<int>>st1;
    while(st.size()>0){
        st1.push(st.top());
        st.pop();
    }
   

    while(st1.size()>0){

        vector<int>ans=st1.top();
        st1.pop();
        cout<<ans[0]<<" ";
        cout<<ans[1]<<endl;

    }



}

int main(){

    int n;
    cin>>n;
    vector<vector<int>>arr(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }

    mergeIntervals(arr);


}