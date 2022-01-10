#include <iostream>
using namespace std;
  
int main()
{

//    int a;
//    a=10;
//    int& b=a;// it will store  address of a

//    int c=20;
//    b=c;

//    cout<<a<<b<<c<<endl;

//    cout<<&a<<&b<<&c<<endl;

     char ch;
     ch='a';
     char* p =&ch;
     cout<<sizeof(ch)<<endl;
     cout<<ch<<endl;
     cout<<p<<endl;

     int n;
     n=10;
     int* q=&n;
     cout<<sizeof(n)<<endl;
     cout<<n<<endl;
     cout<<q<<endl;
     cout<<p+1<<endl;
     cout<<q+1<<endl;

   
   


    return 0;
}