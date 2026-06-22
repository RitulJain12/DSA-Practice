class Solution {
public:
      TreeNode* help(TreeNode* root){
        if(!root) return nullptr;
       root->left=help(root->left);
       root->right=help(root->right);

       if(root->left && root->right) return root;
        if(!root->left && !root->right && root->val) return root;
       if(root->left){
        root->right=nullptr;
        return root;
       }
        if(root->right){
        root->left=nullptr;
        return root;
       }
    return nullptr;
     }
    TreeNode* pruneTree(TreeNode* root) {

        return help(root);
        
    }
};