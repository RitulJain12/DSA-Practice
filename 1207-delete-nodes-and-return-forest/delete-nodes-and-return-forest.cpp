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
    TreeNode* help(vector<TreeNode*>&ans, unordered_set<int>&st,TreeNode* root)
    {
           
           if(!root) return nullptr;

        root->left=  help(ans,st,root->left);

       root->right=  help(ans,st,root->right);

           if(st.find(root->val)!=st.end()){
                 if(root->left) ans.push_back(root->left);
                 if(root->right) ans.push_back(root->right);
               //  st.erase(root->val);
                 return nullptr;
           }

          return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int>st(to_delete.begin(),to_delete.end());

        vector<TreeNode*>ans;

      auto a=   help(ans,st,root);
      if(a)  ans.push_back(a);
         return ans;
    }
};