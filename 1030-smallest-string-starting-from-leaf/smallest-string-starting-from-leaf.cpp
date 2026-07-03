/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,string &s,string formed){
 if(!root) return ;
      if(root->left == nullptr && root->right == nullptr){
    formed.push_back(root->val + 'a');
    string temp = formed;
    reverse(temp.begin(), temp.end());

    if(s.empty() || temp < s)
        s = temp;

    return;
}
       

          

        formed.push_back(char(root->val+97));

        dfs(root->left,s,formed);
        dfs(root->right,s,formed);


    }
    string smallestFromLeaf(TreeNode* root) {

        string ans="";

        dfs(root,ans,"");

        return ans;
        
    }
};