
class Solution {
public:
    pair<int,int> help(TreeNode* root,int &a){

        if(!root) return {0,0} ;
     auto l=   help(root->left,a);
     auto r=   help(root->right,a);
    int len=l.second+r.second+1;
    
    double avg=0.0;
    if(len!=0) avg=(l.first+r.first+root->val)/len;

     if(root->val==avg) a++;


     return {l.first+r.first+root->val,l.second+r.second+1};


    }
    int averageOfSubtree(TreeNode* root){
        int ans=0;
        int sum=0,cnt=0;
     help(root,ans);
     return ans;
    }
};