#include <bits/stdc++.h>
using namespace std;

class MyPriorityQueue
{
public:
    vector<int> data;

    MyPriorityQueue(vector<int>&v){

        for(int val : v){  

            data.push_back(val);
            
        }
        for(int i=data.size()/2-1; i>=0;i--){

            downheapify(i);
            
        }

    }

    int size()
    {
        return data.size();
    }

    void upheapify(int i)
    { // Recursive code
        if (i == 0)
            return;
        int pi = (i - 1) / 2;
        if (data[pi] > data[i])
        {
            swap(data[pi], data[i]);
            upheapify(pi);
        }
    }

    void downheapify(int i)
    {

        int li = i * 2 + 1;
        int ri = i * 2 + 2;

        int mini = i;

        if (li < data.size() && data[li] < data[mini])
        {
            mini = li;
        }
        if (ri < data.size() && data[ri] < data[mini])
        {
            mini = ri;
        }
        if (i != mini)
        {

            swap(data[i], data[mini]);
            downheapify(mini);
        }
    }

    void add(int val)
    {
        data.push_back(val);
        upheapify(data.size() - 1);
    }
    int _remove()
    {
        if (size() == 0)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        swap(data[0], data[data.size() - 1]);
        int val = data[data.size() - 1];
        data.pop_back();
        downheapify(0);
        return val;
    }

    int peek()
    {

        if (size() == 0)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        return data[0];
    }

};

int main()
{
    
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        v.push_back(data);
    }
    MyPriorityQueue* pq = new MyPriorityQueue(v);

    while(pq->data.size()>0){

        cout<<pq->_remove()<<endl;


    }






}