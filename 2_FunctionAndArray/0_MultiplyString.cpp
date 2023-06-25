// This cade failed for large inputs
//  class Solution {
//  public:
//      int chatToint(char &ch){
//          int n = ch - '0';
//          return n;
//      }
//      long long product(string &num1, char ch){
//          int n2 = chatToint(ch);
//          long long ans = 0;
//          long long carry=0;
//          long long pow=1;
//          cout<<n2<<endl;
//          for(int i = num1.size()-1;i>=0;i--){
//              int n1 = chatToint(num1[i]);
//              cout<<n1<<endl;
//              int mulpy = (n1*n2+carry);
//              cout<<mulpy<<endl;
//              ans += mulpy%10 * pow;
//              cout<<ans<<endl;
//              carry = mulpy/10;
//              pow*=10;
//          }
//          if(carry>0){
//              ans+=(carry*pow);
//          }
//          return ans;
//      }
//      long long add(long long x  , long long y){
//      long long ans=0,pow=1,carry=0;
//      while(x!=0 || y!=0 || carry!=0){
//          long long sum =x%10+y%10+carry;
//          carry=sum/10;
//          sum%=10;
//          ans+=sum*pow;
//          pow*=10;
//          x/=10;
//          y/=10;
//      }
//      return ans;
//      }
//      string multiply(string num1, string num2) {
//          long long ans=0;
//          long long pow=1;
//          for(int i = num2.size()-1;i>=0;i--){
//              char cn2 = num2[i];
//              long long prod = product(num1,cn2);
//              ans = add(prod*pow,ans);
//              pow*=10;
//          }
//          return to_string(ans);
//      }
//  };
