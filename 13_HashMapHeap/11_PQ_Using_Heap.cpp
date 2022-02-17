#include<bits/stdc++.h>
using namespace std;

vector<int> data;

int size() {
  return data.size();
}

void upheapify(int i) {   // without recursion
  while (i > 0) {
    int pi = (i - 1) / 2;
    if (data[i] < data[pi]) {
      swap(data[i], data[pi]);
    } else break;

    i = pi;
  }
}

void upheapify2(int i){  // Recursive code
  if(i==0)return;
  int pi = (i-1)/2;
  if(data[pi]>data[i]){
      swap(data[pi],data[i]);
      upheapify(pi);
  }
}

void downheapify(int i) {
 
    int li = i * 2 + 1;
    int ri = i * 2 + 2;

    int mini = i;

    if (li < data.size() && data[li] < data[mini]) {
      mini = li;
    }
    if (ri < data.size() && data[ri] < data[mini]) {
      mini = ri;
    }
    if (i != mini){
        
         swap(data[i], data[mini]);
         downheapify(mini);
         
    }

}

void add(int val) {
  data.push_back(val);
  upheapify(data.size() - 1);
}






int _remove() {
  if (size() == 0) {
    cout << "Underflow" << endl;
    return -1;
  }
  swap(data[0], data[data.size() - 1]);
  int val = data[data.size() - 1];
  data.pop_back();
  downheapify(0);
  return val;
}





int peek(){

    if(size()==0){
        cout<<"Underflow"<<endl;
        return -1;
    }
    return data[0];

}





int main() {


  while (1) {
    string str;
    getline(cin, str);
    if (str[0] == 'a') {
      string num = str.substr(4, str.length());
      int val = stoi(num);
      add(val);
    } else if (str[0] == 'r') {
      int val = _remove();
      if (val != -1) {
        cout << val << endl;
      }
    } else if (str[0] == 'p') {
      int val = peek();
      if (val != -1) {
        cout << val << endl;
      }
    } else break;
  }



}


