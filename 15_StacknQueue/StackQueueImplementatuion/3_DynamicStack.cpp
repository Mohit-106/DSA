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
    int *arr{new int[0]};
    int sizeofStack = 0;
    int tos = -1;

    //constructor
public:
    int sizeofArray = 0;
    void initialize(int size)
    {

        this->arr = new int[size];
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

    int Size()
    {
        return this->sizeofStack;
    }

    bool isempty()
    {
        return this->sizeofStack == 0;
    }
};

class DynamicStack : public Stack
{

public:
    DynamicStack(int size) : Stack(size)
    {
    }

    void push(int val)
    {

        if(sizeofArray == Size()){
            int * temp  { new int[Size()]};
            int idx = Size()-1;
            while(Size()!=0) temp[idx--] = top();

            initialize(sizeofArray*2);
            
            // for(int i=0; i< size(temp); i++){
            //     push(temp[i]);  
            // }

        }

        Stack::push(val);
    }
};

int main()
{

    int n;
    cin >> n;
    DynamicStack *st = new DynamicStack(n);

    for (int i = 1; i <= st->sizeofArray; i++)
    {

        st->push(i * 10);
    }

    while (!st->isempty())
    {
        int val = st->top();
        st->pop();
        cout << val << endl;
    }

    return 0;
}

// public class dynamicStack extends stack {
//     public dynamicStack(int size) {
//         super(size);
//     }

//     public dynamicStack() {
//         super();
//     }

//     @Override
//     public void push(int val) throws Exception {
//         if (super.sizeOfArray() == super.size()) {
//             int[] temp = new int[super.size()];
//             int idx = super.size() - 1;
//             while (super.size() != 0)
//                 temp[idx--] = super.pop();

//             super.initilize(super.sizeOfArray() * 2);

//             for (int i = 0; i < temp.length; i++)
//                 super.push(temp[i]);
//         }

//         super.push(val);
//     }

// }
