#include<bits/stdc++.h>

using namespace std;
class Node {
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data) {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;
  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr) {
  if (idx == arr.size() || arr[idx] == -1) {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void display(Node* node) {
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;
  display(node->left);
  display(node->right);
}


void levelOrder1(Node* node) { //Two queues approach

    queue<Node*>pq,cq;
    pq.push(node);
    while(pq.size()>0){

        Node* temp = pq.front();
        pq.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){

            cq.push(temp->left);
            
        }
        if(temp->right!=NULL){
            
            cq.push(temp->right);
            
        }
        if(pq.size()==0){
            swap(pq,cq);
            cout<<endl;
        }



    }

  
}

void levelOrder2(Node* node){  //count approach

    queue<Node*>q;
    q.push(node);
    while(q.size()>0){

      int count= q.size();
      for(int i=1;i<=count;i++){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
          q.push(temp->left);
        }
        if(temp->right!=NULL){
          q.push(temp->right);
        }

      }
      cout<<endl;

    }

}

void levelOrder3(Node* node){    // Pehchan wali approach (-1)

}

void levelOrder4(Node* node){    //Pair approach

}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    if (temp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(temp);
    }
  }
  Node* root = constructTree(arr);
  levelOrder1(root);
  cout<<"-----------"<<endl;
  levelOrder2(root);

}

// import java.io.*;
// import java.util.*;

// public class Main {
//   public static class Node {
//     int data;
//     Node left;
//     Node right;

//     Node(int data, Node left, Node right) {
//       this.data = data;
//       this.left = left;
//       this.right = right;
//     }
    
//     Node(){
        
//     }
//   }

//   public static class Pair {
//     Node node;
//     int state;

//     Pair(Node node, int state) {
//       this.node = node;
//       this.state = state;
//     }
//   }

//   public static Node construct(Integer[] arr) {
//     Node root = new Node(arr[0], null, null);
//     Pair rtp = new Pair(root, 1);

//     Stack<Pair> st = new Stack<>();
//     st.push(rtp);

//     int idx = 0;
//     while (st.size() > 0) {
//       Pair top = st.peek();
//       if (top.state == 1) {
//         idx++;
//         if (arr[idx] != null) {
//           top.node.left = new Node(arr[idx], null, null);
//           Pair lp = new Pair(top.node.left, 1);
//           st.push(lp);
//         } else {
//           top.node.left = null;
//         }

//         top.state++;
//       } else if (top.state == 2) {
//         idx++;
//         if (arr[idx] != null) {
//           top.node.right = new Node(arr[idx], null, null);
//           Pair rp = new Pair(top.node.right, 1);
//           st.push(rp);
//         } else {
//           top.node.right = null;
//         }

//         top.state++;
//       } else {
//         st.pop();
//       }
//     }

//     return root;
//   }

// //   public static void display(Node node) {
// //     if (node == null) {
// //       return;
// //     }

// //     String str = "";
// //     str += node.left == null ? "." : node.left.data + "";
// //     str += " <- " + node.data + " -> ";
// //     str += node.right == null ? "." : node.right.data + "";
// //     System.out.println(str);

// //     display(node.left);
// //     display(node.right);
// //   }

// //   public static void levelOrder1(Node node) {
// //     // write your code here
// //     ArrayDeque<Node> pq = new ArrayDeque<>();
// //     ArrayDeque<Node> cq = new ArrayDeque<>();
    
// //     pq.add(node);
// //     while(pq.size() > 0){
// //         Node temp = pq.remove();
// //         System.out.print(temp.data + " ");
        
// //         if(temp.left != null){
// //             cq.add(temp.left);
// //         }
        
// //         if(temp.right != null){
// //             cq.add(temp.right);
// //         }
        
// //         if(pq.size() ==  0){
// //             pq = cq;
// //             cq = new ArrayDeque<>();
// //             System.out.println();
// //         }
// //     }
// //   }
  
// //    public static void levelOrder2(Node node) {
// //     // write your code here
// //     ArrayDeque<Node> pq = new ArrayDeque<>();
// //     pq.add(node);
    
// //     while(pq.size() > 0){
// //         int count = pq.size();
        
// //         for(int i = 0; i < count; i++){
// //             Node temp = pq.remove();
// //             System.out.print(temp.data + " ");
            
// //             if(temp.left != null){
// //                 pq.add(temp.left);
// //             }
            
// //             if(temp.right != null){
// //                 pq.add(temp.right);
// //             }
// //         }
        
// //         System.out.println();
// //     }
// //   }
  
// //   public static void levelOrder3(Node node) {
// //     // write your code here
// //     ArrayDeque<Node> pq = new ArrayDeque<>();
// //     pq.add(node);
    
// //     Node delim = new Node(-1, null, null);
// //     pq.add(delim);
    
// //     while(pq.size() > 0){
// //         Node temp = pq.remove();
        
// //         if(temp.data == -1){
// //             System.out.println();
// //             if(pq.size() > 0){
// //                 pq.add(temp);
// //             }
// //             continue;
// //         }
        
// //         System.out.print(temp.data + " ");
        
// //         if(temp.left != null){
// //             pq.add(temp.left);
// //         }
        
// //         if(temp.right != null){
// //             pq.add(temp.right);
// //         }

// //     }
// //   }

// //   public static void main(String[] args) throws Exception {
// //     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// //     int n = Integer.parseInt(br.readLine());
// //     Integer[] arr = new Integer[n];
// //     String[] values = br.readLine().split(" ");
// //     for (int i = 0; i < n; i++) {
// //       if (values[i].equals("n") == false) {
// //         arr[i] = Integer.parseInt(values[i]);
// //       } else {
// //         arr[i] = null;
// //       }
// //     }

// //     Node root = construct(arr);
// //     levelOrder3(root);
// //   }

// // }
