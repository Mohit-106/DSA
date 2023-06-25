#include <iostream>
#include <string>
using namespace std;

void printEncoding(string str, string asf)
{
    if (str.size() == 0)
    {
        cout << asf << endl;
        return;
    }

    char ch = str[0];
    if (ch == '0')
    {
        return;
    }
    int val = ch - '0'; // value of char in int
    char codes = (char)('a' + val - 1);
    printEncoding(str.substr(1), asf + codes);
    
    if (str.size() >= 2)
    {   string s = str.substr(0, 2);
        int val2 = stoi(s);
        if (val2 <= 26)
        {
            char codes2 = (char)('a' + val2 - 1);
            printEncoding(str.substr(2), asf + codes2);
        }
    }
}

int main()
{
    string str;
    cin >> str;
    if (str[0] == '0')
    {
        cout << "invalid output" << endl;
    }
    printEncoding(str, "");
}