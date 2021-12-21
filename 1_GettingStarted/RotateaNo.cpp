#include <bits/stdc++.h>
using namespace std;

int Digits(int n){
    int count=0;
    while(n!=0){
        n/=10;
        count++;
    }

    return count;
}



int Rotate(int n, int k){

    int  digits = Digits(n);

    k=k%digits;
    if(k<0){
        k+=digits;
    }


    int  divisor= pow(10,k);
    int q=n/divisor;
    int r=n%divisor;
     
    int ans=q+(r*pow(10,digits-k));
    return ans;


}



int main()
{

    int n,k;
    cin >> n >>k;
    cout<<Rotate(n,k);

    return 0;
}