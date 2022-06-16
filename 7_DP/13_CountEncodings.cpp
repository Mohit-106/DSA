#include <bits/stdc++.h>
using namespace std;

int EncodingsTab2(string str, vector<int> &dp)
{

    for(int i=0;i<str.size()-1;i++){
        if(i==0){
            dp[i]=1;
            continue;
        }
        char ch1= str[i];
        char chm1=str[i-1];
        if(ch1!=0){
            dp[i]+=dp[i-1];
        }
        

    }
    
}

int EncodingsTab(string str, vector<int> &dp)
{

    for (int i = str.size(); i >= 0; i--)
    {
        if (i == str.size())
        {
            dp[i] = 1;
            continue;
        }
        char ch = str[i];
        if (ch != '0')
        {
            dp[i] += dp[i + 1];
            if (i < str.size() - 1)
            {
                int num = (ch - '0') * 10 + (str[i + 1] - '0');
                if (num <= 26)
                {
                    dp[i] += dp[i + 2];
                }
            }
        }
    }
    return dp[0];
}

int main()
{

    string str;
    cin >> str;
    vector<int> dp(str.size() + 1);
    cout << EncodingsTab(str, dp);

}
