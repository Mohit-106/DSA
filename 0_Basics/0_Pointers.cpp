#include <bits/stdc++.h>
using namespace std;

class Mohit{
    public:
    string name;
    Mohit(string name){
        this->name = name;
    }

    Mohit(){
        this->name ="";
    }

    void Display(){
        cout<<this->name<<endl;
    }

};

int main(){

    // int n=2;
    // vector<int> * v = new vector<int>(n);// vector on heap
    // vector<int>v1(n);//vector on stack
    // int arr[n]; // array on stack
    // int * arr1 = new int[n]; // array of pointer on heap
    // int * arr2{new int[n]}; // Dynamically allocated array
    // Mohit *m1 = new Mohit("Mohit1");  // On heap
    // m1->Display();
    // Mohit m2("Mohit2"); // On stack
    // m2.Display();
    // cout<<v->size()<<endl;
    // cout<<v1.size();
    // vector<string>s; // vector of string also acted like 2D array
    // return 0;

}