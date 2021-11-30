// #include <bits/stdc++.h>
// using namespace std;


// //....Decimal Multiplication....//


// int AnyBaseSum(int n1, int n2){
//     int ans=0,p=1,carry=0;
  
//     while(n1!=0 || n2!=0 || carry!=0){
//         int sum=n1%10+n2%10+carry;
//         carry=sum/10;
//         sum=sum%10;
//         n1/=10;
//         n2/=10;
//         ans+=sum*p;
//         p*=10;

//     }
//     return ans;
// }


// int MultiplyByoneDigit(int n, int digit){
//     int ans =0,p=1,carry=0;
//     while(n!=0 || carry!=0){
//         int prod=n%10*digit+carry;
//         prod%=10;
//         carry=prod/10;
//         n/=10;
//         ans+=prod*p;
//         p*=10;
//     }
//     return ans;
// }

// int DecimalMultiplication(int n, int m){

//     int ans=0, p=1;
//     while(m!=0){

//         int prod=MultiplyByoneDigit(n,m%10);
//         m/=10;
//         int ans=AnyBaseSum(ans,prod*p);
//         p*=10;


//     }
//     return ans;


// }


// int main()
// {

//     int n,m;
//     cin>>n>>m;

//     cout<<DecimalMultiplication(n,m);


  


//     return 0;
// }