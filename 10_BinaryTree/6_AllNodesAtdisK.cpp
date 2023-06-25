//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// class Solution {
// public:
//     vector<int>ans;
//     vector<TreeNode*>  NodeToRoot(TreeNode * root, TreeNode * Target){
        
//         if(root==Target){
//             vector<TreeNode*>base;
//             base.push_back(root);
//             return base;
//         }
        
//         if(root->left!=NULL){
//             vector<TreeNode*> left = NodeToRoot(root->left,Target);
//             if(left.size()>0){
//                 left.push_back(root);
//                 return left;
//             }
            
//         }
//         if(root->right!=NULL){
//             vector<TreeNode*> right = NodeToRoot(root->right,Target);
//             if(right.size()>0){
//                 right.push_back(root);
//                 return right;
//             }
            
//         }
        
//         vector<TreeNode*> ans;
//         return ans;
        
        
//     }
    
//     void klevelDown(TreeNode* root, int level , TreeNode * blocker, int clevel){    
//         if(clevel == level){
//             ans.push_back(root->val);
//             return;
//         }       
//         if(root->left!= blocker && root->left!=NULL){
//             klevelDown(root->left,level,blocker,clevel+1);
//         }
//         if(root->right!=blocker && root->right!=NULL){
//             klevelDown(root->right,level,blocker,clevel+1);
//         }
//     }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         if(root==NULL){
//             return ans;
//         }
        
//         vector<TreeNode*>arr = NodeToRoot(root,target);
//         for(int i=0,level=k;i<arr.size();i++,level--){
           
//             klevelDown(arr[i],level,i==0?NULL:arr[i-1],0);
            
            
//         }
        
//         return ans;
        
//     }
// };