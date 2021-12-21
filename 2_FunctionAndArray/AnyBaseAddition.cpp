#include <bits/stdc++.h>
using namespace std;

int DecimalAddition(int n, int m){

    int carry=0, pow=1, sum, ans=0;
    while(n!=0 || m!=0 || carry!=0){

        sum= n%10 + m%10 + carry;

        carry= sum/10;
        sum= sum%10;
        n/=10;
        m/=10;
        ans+=sum*pow;
        pow*=10;

    }
    return ans;


}

int BinaryAddition(int n, int m){
    
    int carry=0, pow=1, sum, ans=0;
    while(n!=0 || m!=0 || carry!=0){

        sum= n%10 + m%10 + carry;

        carry= sum/2;
        sum= sum%2;
        n/=10;
        m/=10;
        ans+=sum*pow;
        pow*=10;

    }
    return ans;



}

int AnyBaseAddition(int n, int m, int b){

    int carry=0, pow=1, sum, ans=0;
    while(n!=0 || m!=0 || carry!=0){

        sum= n%10 + m%10 + carry;

        carry= sum/b;
        sum= sum%b;
        n/=10;
        m/=10;
        ans+=sum*pow;
        pow*=10;

    }
    return ans;



}

int  main(){


    int n, m, b;
    cin>>n>>m>>b;
    cout<<DecimalAddition(n,m)<<endl;
    cout<<BinaryAddition(n,m)<<endl;
    cout<<AnyBaseAddition(n,m,b);


    return 0;
}