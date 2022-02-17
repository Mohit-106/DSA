#include <bits/stdc++.h>
using namespace std;

int main(){

    string str;
    getline(cin,str);
    stack<char>st;
    st.push(str[0]);
    for(int i=0; i<str.size(); i++){
        char ch = str[i];

        if(ch==')'){
            if(st.top()=='('){
                cout<<"true"<<endl;
                return 0;
            }
            while(st.top()!='('){
                st.pop();
            }
            st.pop();

        }else{
            st.push(ch);
        }
    }
    cout<<"false"<<endl;
    return 0;

}