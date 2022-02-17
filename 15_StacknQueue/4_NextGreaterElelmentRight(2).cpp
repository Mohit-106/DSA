// jin jin ko maine pop kra dia un sbka next greater mai
// sidha loop
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

    int n= arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    st.push(0);
    for(int i =1; i<n; i++){

        while(st.size()>0 && arr[st.top()]<arr[i]){
            int pidx = st.top();
            st.pop();
            ans[pidx]=arr[i];

        }
        st.push(i);
        

    }

    // while(st.size()>0){ ---------if we use -1 in ans array then no need to use this extra while loop
    //     int idx = st.top();
    //     st.pop();
    //     ans[idx]=-1;
    // }   

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
   vector<int>nge(n,0);
   nge=solve(arr);
   display(nge);
   return 0;


}