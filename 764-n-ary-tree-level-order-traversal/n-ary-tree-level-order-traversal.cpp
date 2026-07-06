/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        queue<Node*>q;
        if(!root) return {};
        q.push(root);
        while(q.size()){
            int s=q.size();
            vector<int>temp;
               while(s--){
                    auto fr=q.front();q.pop();
                    if(!fr)continue;
                    temp.push_back(fr->val);

                        for(auto &c:fr->children){
                            q.push(c);
                        }

               }
               ans.push_back(temp);
        }
        return ans;
    }
};