#include <bits/stdc++.h>
using namespace std;

void TOH(int n, string S, string H, string D){

    if(n==0){
        return ;
    }
    
    TOH(n-1,S,D,H);
    cout<<n<<S<<"->"<<D<<endl;
    TOH(n-1,H,S,D);

}

int main(){
    int n;
    cin>>n;
    TOH(n,"A","B","c");

    return 0;
}