#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{  
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int>lb(n);
    lb[0]=-1;
    stack<int>ls;
    ls.push(0);
    for(int i=1; i<n; i++){

        while(ls.size()>0 && arr[i]<=arr[ls.top()]){
            ls.pop();
        }
        if(ls.size()==0){
            lb[i]=-1;
        }else{
            lb[i]=ls.top();
        }
        ls.push(i);

    }

    vector<int>rb(n);
    stack<int>rs;
    rb[n-1]=n;
    rs.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(rs.size()>0 && arr[i]<=arr[rs.top()]){
            rs.pop();
        }
        if(rs.size()==0){
            rb[i]=n;
        }else{
            rb[i]=rs.top();
        }
        rs.push(i);

    }

    int maxArea=INT_MIN;
    for(int i=0;i<n;i++){
        int ht = arr[i];
        int wd = rb[i]-lb[i]-1;
        int area = ht*wd;
        if(area>maxArea){
            maxArea=area;
        }
    }

    cout<<maxArea<<endl;







   return 0;
}


