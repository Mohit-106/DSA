// import java.util.*;

// public class Main {
//   public static void printKLevelsDown(Node node, int k){
//     Queue<Node> q = new ArrayDeque<Node>();
//     q.add(node);
//     int count = k+1;
//     while(count-- > 0){
//       int qsize = q.size();
//       while(qsize-->0){
//         Node temp = q.remove();
//         // System.out.print(temp.data + " ");
//         if(count == 0) System.out.println(temp.data + " ");
//         if(temp.left != null) q.add(temp.left);
//         if(temp.right != null) q.add(temp.right);
//       } 
//       //System.out.println();
//     }
//   }

//   public static void main(String[] args) {
//     // Write your code here

//   }
// }
// Sir, ye code neat to nahi he par aapke code se space
// complexity ke terms me better he. Kyuki aapke code me recursion stack me k 
// levels down tak saare nodes aayenge. mere waale me  queue kaali hoti jaa rhi he.
// Basically isme level order waali trick hi use ki he bas jaaha print karvaana tha bas vha hi karwaaya he.



