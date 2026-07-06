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
class FindElements {
public:
    unordered_map<int,int>mp;
    FindElements(TreeNode* root) {
       
       queue<pair<TreeNode*,int>>q;
       q.push({root,0});

    

       while(q.size()){

        auto size=q.size();
     //   int mini=q.front().second;

          for(int i=0;i<size;i++){

            auto [node,idx]=q.front();q.pop();
          //  cout<<node->val;
            node->val=idx;
            mp[idx]++;

            if(node->right) q.push({node->right,2*idx+2});
            if(node->left) q.push({node->left,2*idx+1});

          }

       }

        
    }
    
    bool find(int target) {


        return mp.contains(target);
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */