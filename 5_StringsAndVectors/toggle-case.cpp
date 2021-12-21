#include <bits/stdc++.h>
using namespace std;

string Toggle(string str){

    int n=str.size();
    string ans;

    for(int i=0; i<n; i++){

        if(str[i]>='A' && str[i]<='Z'){

            char sch = (char)(str[i]-'A'+'a');
            ans.push_back(sch);
            

        }else{

            char cch = (char)(str[i]-'a'+'A');
            ans.push_back(cch);



        }

    }

    return ans;



}

int main(){

    string str;
    cin>>str;

    cout<<Toggle(str);

    return 0;
}