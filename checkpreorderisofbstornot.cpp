// if i ==n which means we have traversed the whole preorder array and we are able to construct the BST successfully then we return true else if we are not able to construct the BST successfully then we return false

class Solution {
    public:
        TreeNode* build(vector<int>& pre, int &i, int minVal, int maxVal) {
            if (i >= pre.size()) return NULL;
    
            int val = pre[i];
    
        
            if (val < minVal || val > maxVal) return NULL;

            TreeNode* root = new TreeNode(val);
            i++;
    
        
            root->left = build(pre, i, minVal, val);
    
    
            root->right = build(pre, i, val, maxVal);
    
            return root;
        }
    
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            int i = 0;
         build(preorder, i, INT_MIN, INT_MAX);
         if(i == preorder.size()) {
             return build(preorder, i, INT_MIN, INT_MAX);
         } else {
             return NULL;
        }
    };