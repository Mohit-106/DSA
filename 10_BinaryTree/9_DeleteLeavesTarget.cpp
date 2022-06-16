// Delete Leaves With a Given Value
//https://leetcode.com/problems/delete-leaves-with-a-given-value/

// class Solution {
// public:
//     TreeNode* removeLeafNodes(TreeNode* node, int target) {
//         if(node==NULL){
//             return NULL;
//         }
//         if(node->left==NULL && node->right==NULL){
//             if(node->val==target){
//                  return NULL;
//             }else{
//                 return node;
//             }
           
//         }
        
//         node->left = removeLeafNodes(node->left,target);
//         node->right = removeLeafNodes(node->right,target);
        
//         if(node->left==NULL && node->right==NULL){
//             if(node->val==target){
//                 return NULL;
//             }
//         }
        
//         return node;
        
//     }
// };