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
  ans[0]=1;
  stack<int>st;
  st.push(0);
  for(int i=1;i<n;i++){
      while(st.size()>0 && arr[i]>arr[st.top()]){
          st.pop();
      }
      if(st.size()==0){
          ans[i]=i+1;
      }else{
          ans[i]=i-st.top();
      }
      st.push(i);

  }
  return ans;
}

int main(int argc, char **argv)
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