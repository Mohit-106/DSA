// class Solution {
// public:
//     bool v(TreeNode* root, long int low, long int high){
        
// 		if (root)
// 		{
// 			if (root->val<=low || root->val>=high)
// 			{
// 				return false;
// 			}
//         return ( v(root->left , low , root->val) && v(root->right , root->val , high) );
// 		}
//         return true;
//     }
    
// 	bool isValidBST(TreeNode* root){
		
// 		return v( root , -2147483649 , 2147483648 );
//     }
// };  


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2 class pair solution
