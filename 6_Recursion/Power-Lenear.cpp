#include <bits/stdc++.h>
using namespace std;

int power(int x , int n){

    if(n==0){
        return 1;
    }


    int y = power(x,n-1);
    int ans= x*y;
    return ans;



}




int main()
{

   int x,n;
   cin>>x>>n;
   cout<<power(x,n);
    return 0;

}