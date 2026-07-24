class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return countPaths(root, targetSum) 
             + pathSum(root->left, targetSum) 
             + pathSum(root->right, targetSum);
    }

    int countPaths(TreeNode* node, long long targetSum) {
        if (!node) return 0;
        int res = (node->val == targetSum) ? 1 : 0;
        res += countPaths(node->left, targetSum - node->val);
        res += countPaths(node->right, targetSum - node->val);
        return res;
    }
};
