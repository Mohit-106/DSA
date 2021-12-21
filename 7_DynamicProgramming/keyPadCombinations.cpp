#include <bits/stdc++.h>
using namespace std;

void Recursion(string s, string asf)
{

    if (s.size() == 0)
    {
        cout << asf << endl;
        return;
    }
    if (s[0] == '0')
    {
        return;
    }

    string str = s.substr(0, 1); //s.substr(index,size)
    string ros1 = s.substr(1);

    Recursion(ros1, asf + (char)(stoi(str) + 'a' - 1)); //stoi function converts string to number

    if (s.size() >= 2)
    {
        string str2 = s.substr(0, 2);
        string ros2 = s.substr(2);
        if (stoi(str2)<=26)
        {
            Recursion(ros2, asf + (char)(stoi(str2) + 'a' - 1));
        }
    }
}

void DP(string s){

    int n= s.size();
    vector<int>dp(n);
    dp[0]=1;

    for(int i=1; i<n; i++){

        if(s[i]=='0' && s[i-1]=='0'){

            dp[i]=0;

        }else if(s[i-1]=='0'&& s[i]!='0'){
            dp[i]=dp[i-1];
           
        }else if(s[i-1]!='0' && s[i]=='0'){
            if(s[i-1]=='1'||s[i-1]=='2'){

                dp[i]=(i>=2?dp[i-2]:1);

            }else{
                dp[i]=0;
            }
        }else{
            
            string sub=s.substr(i-1,2);
            int val = stoi(sub);


            if( val <= 26){
                dp[i]=dp[i-1]+(i>=2 ? dp[i-2]:1);
            }else{

                dp[i]=dp[i-1];

            }

        }



    }

    cout<<dp[n-1];







}



int main()
{

    string s;
    cin >> s;
    // Recursion(s, "");
    DP(s);

    return 0;
}