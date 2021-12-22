#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int l1 = INT_MIN;
  int l2 = INT_MIN;

  for(int i=0;i<n;i++){
    if(arr[i]>l1){
      l2=l1;
      l1=arr[i];
     
    }else if(arr[i]>l2 && arr[i]<l1){
      l2=arr[i];
    }

  }

  cout<<"largest no is ->"<<" "<<l1<<endl;
  cout<<"2nd largest no is ->"<<" "<<l2<<endl;

  return 0;
}