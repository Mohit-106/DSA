#include <bits/stdc++.h>
using namespace std;

bool check(string ss){

    int n= ss.size();

    int i=0; int j=n-1;
    while(i<=j){
        if(ss[i]==ss[j]){

            i++;
            j--;


        }else{
            return false;
        }

    }
    return true;

}




void Palindrome(string str){

    int n=str.size();


    for(int i=0;i<n; i++){
        for(int j=1; j<=n-i;j++){

            string ss= str.substr(i,j);

            if(check(ss)){

                cout<<ss<<endl;

            }

           


        }
    }


}





int main(){

    string str;
    cin>>str;
    Palindrome(str);
    
    return 0;
}