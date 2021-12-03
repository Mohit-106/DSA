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
        int prod= DecimalprodwithSingleDigit(n,digit);

        ans=DecimalSum(ans,prod*pow);
        pow*=10;
        m/=10;

    }

    return ans;
    

}


//......Any base multiplication....//

int  AnyBaseprodwithSingleDigit(int n, int digit, int b){

    int ans=0,pow=1,carry=0;

    while(n!=0 || carry!=0){

        int prod=(digit*n%10)+carry;
        carry=prod/b;
        prod%=b;
        ans+=(prod*pow);
        pow*=10;
        n/=10;
    }

    return ans;

}

int AnyBaseSum(int x , int y, int b){

    int ans=0,pow=1,carry=0;
    while(x!=0 || y!=0 || carry!=0){
        int sum =x%10+y%10+carry;
        carry=sum/b;
        sum%=b;
        ans+=sum*pow;
        pow*=10;
        x/=10;
        y/=10;
    }
    return ans;




}



int AnyBaseMultiplication(int n, int m , int b){
    int ans=0,pow=1;
    while(m!=0){
        int digit=m%10;
        int prod= AnyBaseprodwithSingleDigit(n,digit,b);

        ans=AnyBaseSum(ans,prod*pow,b);
        pow*=10;
        m/=10;

    }

    return ans;




}






int main(){

    int n,m,b;
    cin>>b>>n>>m;
    // cout<<DecimalMultiplication(n,m)<<endl;
    cout<<AnyBaseMultiplication(n,m,b)<<endl;




// int gpwsd(int b, int n1, int d2){
//     int ans = 0;
//     int power = 1;
//     int carry = 0;
    
//     while(n1 != 0 || carry != 0){
//         int l1 = n1 % 10;
//         n1 /= 10;
        
//         int product = l1 * d2 + carry;
//         int q = product / b;
//         int r = product % b;
        
//         ans += (r * power);
//         carry = q;
//         power *= 10;
//     }
//     return ans;
// }

// int anyBaseAddition(int b, int n1, int n2){
//     int ans = 0;
//     int carry = 0;
//     int power = 1;
    
//     while(n1 != 0 || n2 != 0 || carry != 0){
//         int ld1 = n1 % 10;
//         int ld2 = n2 % 10;
//         n1 /= 10;
//         n2 /= 10;
        
//         int sum = ld1 + ld2 + carry;
//         int q = sum / b;
//         int r = sum % b;
        
//         ans += (r * power);
//         carry = q;
//         power *= 10;
//     }
//     return ans;
// }

// int getProduct(int b, int n1, int n2){
//     // write your code here
//     int ans = 0;
//     int power = 1;
    
//     while(n2 != 0){
//         int l2 = n2 % 10;
//         n2 /= 10;
        
//         int pwsd = gpwsd(b,n1,l2);
//         ans = anyBaseAddition(b,ans,pwsd * power);
//         power *= 10;
//     }
//     return ans;
// }

// int main(){
//     int b, n1, n2;
//     cin>>b>>n1>>n2;
//     cout<<getProduct(b,n1,n2)<<endl;
// }
                        
                                

    return 0;
}






