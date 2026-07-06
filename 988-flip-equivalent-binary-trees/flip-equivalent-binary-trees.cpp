class Solution {
public:
    bool help(TreeNode* r1, TreeNode* r2) {

        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;
        if (r1->val != r2->val) return false;

        return (help(r1->left, r2->left) &&
                help(r1->right, r2->right))
            ||
               (help(r1->left, r2->right) &&
                help(r1->right, r2->left));
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return help(root1, root2);
    }
};