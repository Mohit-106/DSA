#include <bits/stdc++.h>
#include <exception>
using namespace std;

class CustomQueue{
    public:
    int *arr;
    int sizeQ;
    int front;
    int arrSize;
    
    CustomQueue(int cap){
        sizeQ = 0;
        front = 0;
        arr = new int[cap];
        arrSize = cap;
    }
    
    int size(){

        if(sizeQ==0){
            cout<<" "<<endl;
        }else{

             return sizeQ; 

        }
        

    }
    
    void add(int data){

        if(sizeQ == arrSize){
            cout<<"Queue overflow"<<endl;
            return;
        }
        int rear =(sizeQ+front)%arrSize;
        arr[rear]=data;
        sizeQ++;

    }

    int peek(){

        if(sizeQ==0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        return arr[front];

    }

    int remove(){
        
        if(sizeQ==0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        int val = arr[front];
        front = (front+1)%arrSize;
        sizeQ--;
        return val;
        
    }
    
    void display() {

        for(int i=0;i<sizeQ; i++){
            int idx = (front+i)%arrSize;
            cout<<arr[idx]<<" ";
        }
        cout<<endl;
        
    }
};

int main(){
    int n;
    cin>>n;
    CustomQueue q(n);
    string str;
    cin>>str;
    
    while(str!="quit"){
        if(str=="add"){
            int val;
            cin>>val;
            q.add(val);
        }
        else if(str=="remove"){
            int val = q.remove();
            if(val != -1){
                cout<<val<<endl;
            }
        }
        else if(str=="peek"){
            int val = q.peek();
            if(val != -1){
                cout<<val<<endl;
            }
        }
        else if(str=="size"){
            cout<<q.size()<<endl;
        }
        else if(str=="display"){
            q.display();
        }
        cin>>str;
    }
    return 0;
}


