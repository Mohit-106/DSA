// jise mai pop na kra paya wo mera next greater
// Ulta loop
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
  ans[n-1]=-1;
  stack<int>st;
  st.push(arr[n-1]);

  for(int i=n-2;i>=0;i--){
      while(st.size()>0 && st.top() < arr[i]){
          st.pop();
      }
      if(st.size()==0){
          ans[i]=-1;
      }else{
          ans[i]=st.top();
      }
      st.push(arr[i]);
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
   vector<int>nge(n,0);
   nge=solve(arr);
   display(nge);
   return 0;


}

//Related Questions 
//1. Next Greater on left
//2 Next Smaller element (left and right)