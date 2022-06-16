// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
        
//         if(root==NULL){
//             TreeNode * base = new TreeNode(val);
//             return base;
//         }
        
//         if(val < root->val){
            
//             root->left = insertIntoBST(root->left, val);
            
//         }else if(val > root->val){
            
//             root->right = insertIntoBST(root->right, val);
            
//         }else{
//             //nothing to do
//         }
        
//         return root;
        
//     }
// };