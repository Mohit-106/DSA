// distance between index to its next smaller in left
#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a){
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}

vector<int> solve(vector<int>&arr)
{
    int n = arr.size();
    vector<int>ans(n);
    stack<int>st;
    st.push(n-1);
    for(int i=n-2; i>=0; i--){

        while(st.size()>0 && arr[i]>arr[st.top()]){
            int idx = st.top();
            st.pop();
            ans[idx]=idx-i;
        }
        st.push(i);

    }
    while(!st.empty()){

        int idx = st.top();
        st.pop();
        ans[idx]=idx+1;

    }

    return ans;

}

int main()
{  
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {

        cin>>arr[i];

    }
    vector<int>span(n,0);
    span=solve(arr);
    display(span);
   return 0;
}