#include <bits/stdc++.h>
using namespace std;



int main()
{


    
    stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40); //10 20 30 40 5
    cout << stack.top() << endl; //40
    stack.pop();
    cout << stack.top(); //30


    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    cout << q.front() << " " << q.back() << endl;



    
    
    return 0;
}