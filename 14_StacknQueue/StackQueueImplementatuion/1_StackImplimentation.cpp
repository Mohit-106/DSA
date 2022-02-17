// public class stack {

//     // class variables
//     private int[] arr;
//     private int sizeOfArray = 0;
//     private int sizeOfStack = 0;
//     private int tos = -1;

//     // constructor
//     public stack() {
//         this.initilize(5);
//     }

//     public stack(int size) {
//         this.initilize(size);
//     }

//     public void initilize(int size) {
//         this.arr = new int[size];
//         this.sizeOfArray = size;
//         this.sizeOfStack = 0;
//         this.tos = -1;
//     }

//     // exceptions
//     private void stackIsFullException() throws Exception {
//         if (this.sizeOfArray == this.sizeOfStack)
//             throw new Exception("stackIsFull");
//     }

//     private void stackIsEmptyException() throws Exception {
//         if (this.sizeOfStack == 0)
//             throw new Exception("stackIsEmpty");
//     }

//     // basic
//     public boolean isEmpty() {
//         return this.sizeOfStack == 0;
//     }

//     public int size() {
//         return this.sizeOfStack;
//     }

//     // functions

//     public void push(int val) throws Exception {
//         stackIsFullException();
//         this.tos++;
//         this.arr[this.tos] = val;
//         this.sizeOfStack++;
//     }

//     public int pop() throws Exception {
//         stackIsEmptyException();
//         int val = this.top();
//         this.arr[this.tos] = 0;
//         this.tos--;
//         this.sizeOfStack--;

//         return val;
//     }

//     public int top() throws Exception {
//         stackIsEmptyException();
//         return this.arr[this.tos];
//     }
// }
// public class client {
//     public static void main(String[] args) throws Exception {
//         stack st = new stack();
//         for (int i = 1; i <= 5; i++)
//             st.push(i * 10);

//         st.push(60);

//         while (st.size() != 0)
//             System.out.print(st.pop() + " ");
//     }
// }

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    //Variables
    
    int* arr = new int[0];
    int sizeofStack = 0;
    int tos = -1;

    //constructor
public:
    int sizeofArray = 0;
    void initialize(int size)
    {
        this->arr= new int[size];
        this->sizeofArray = size;
        this->sizeofStack = 0;
        this->tos = -1;
    }
    Stack()
    {
        initialize(5);
    }
    Stack(int size)
    {
        initialize(size);
    }

    //Exceptions

    //functions
    void push(int val)
    {

        this->tos++;
        this->arr[this->tos] = val;
        this->sizeofStack++;
    }

    int top()
    {

        return arr[this->tos];
    }

    void pop()
    {
        this->arr[this->tos] = 0;
        this->tos--;
        this->sizeofStack--;
    }

    int size()
    {
        return this->sizeofStack;
    }

    bool isempty()
    {
        return this->sizeofStack == 0;
    }

};

int main()
{

    // int n ;
    // cin>>n;
    Stack *st = new Stack(10);

    for(int i=1;i<=st->sizeofArray; i++){

        st->push(i*10);

    }
    
    while(!st->isempty()){
        int val = st->top();
        st->pop();
        cout<<val<<endl;
    }

    return 0;
}
