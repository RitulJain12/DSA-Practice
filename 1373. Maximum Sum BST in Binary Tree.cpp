#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        isBST(root, maxSum);
        return maxSum;
    }

private:
    tuple<int, int, int> isBST(TreeNode* node, int& maxSum) {
        if (!node) return {INT_MAX, INT_MIN, 0};

        auto [leftMin, leftMax, leftSum] = isBST(node->left, maxSum);
        auto [rightMin, rightMax, rightSum] = isBST(node->right, maxSum);

        if (leftMax < node->val && node->val < rightMin) {
            int currSum = leftSum + rightSum + node->val;
            maxSum = max(maxSum, currSum);
            return {min(leftMin, node->val), max(rightMax, node->val), currSum};
        }

        return {INT_MIN, INT_MAX, 0};


    }
};

//  use a data structure to store the minimum value, maximum value,and sum of the subtree.