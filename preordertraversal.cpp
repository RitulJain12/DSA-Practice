//Inorder traversal of a binary tree is to traverse the left subtree first, then visit the root node, and finally traverse the right subtree.
//Morris Traversal is a tree traversal algorithm that uses O(1) space complexity by
#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> morrisInorderTraversal(TreeNode* root) {
    vector<int> result;
    TreeNode* current = root;
    TreeNode* pre;

    while (current) {
        if (!current->left) {
            result.push_back(current->val);
            current = current->right;
        } else {
            
            pre = current->left;
            while (pre->right && pre->right != current) {
                pre = pre->right;
            }

          
            if (!pre->right) {
                pre->right = current;
                result.push_back(current->val);
                current = current->left;
            } else {
               
                pre->right = NULL;
                //result.push_back(current->val);
                current = current->right;
            }
        }
    }
    return result;
}
