#include <bits/stdc++.h>
using namespace std;

int b1BaseToDecimal(int n, int b1){

    int ans=0, rem,pow_b1=1;
    while(n!=0){
        rem=n%10;
        n/=10;
        ans+=rem*pow_b1;
        pow_b1*=b1;
    }
    return ans;


}

int DecimalofBaseb1ToBaseb2(int n2, int b2){
    int ans=0, rem, pow=1;

    while(n2!=0){
        rem=n2%b2;
        n2/=b2;
        ans+=rem*pow;
        pow*=10;


    }
    return ans;

}


int main(){

    int n,b1,b2;
    cin>>n>>b1>>b2;

    int n2=b1BaseToDecimal(n,b1);

    int n3=DecimalofBaseb1ToBaseb2(n2,b2);
     cout<<n3<<endl;



    return 0;
}