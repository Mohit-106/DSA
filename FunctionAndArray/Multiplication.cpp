#include <bits/stdc++.h>
using namespace std;


//......DecimalMultiplication......//


int  DecimalprodwithSingleDigit(int n, int digit){

    int ans=0,pow=1,carry=0;

    while(n!=0 || carry!=0){

        int prod=(digit*n%10)+carry;
        carry=prod/10;
        prod%=10;
        ans+=prod*pow;
        pow*=10;
        n/=10;
    }

    return ans;

}


int DecimalSum(int x , int y){

    int ans=0,pow=1,carry=0;
    while(x!=0 || y!=0 || carry!=0){
        int sum =x%10+y%10+carry;
        carry=sum/10;
        sum%=10;
        ans+=sum*pow;
        pow*=10;
        x/=10;
        y/=10;
    }
    return ans;




}


int DecimalMultiplication(int n, int m){

    int ans=0,pow=1;
    while(m!=0){
        int digit=m%10;
        int prod= prodwithSingleDigit(n,digit);

        ans=AnyBaseSum(ans,prod*pow);
        pow*=10;
        m/=10;

    }

    return ans;
    

}


//......Any base multiplication....//

int AnyBaseMultiplication(int n, int m , int b){



}






int main(){

    int n,m,b;
    cin>>n>>m>>b;
    cout<<DecimalMultiplication(n,m)<<endl;
    cout<<AnyBaseMultiplication(n,m,b)<<endl;
  

    return 0;

}


