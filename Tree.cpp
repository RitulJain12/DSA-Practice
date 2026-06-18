class Solution {
public:
     bool help(ListNode* head, TreeNode* root){

        if(!head) return 1;
        if(!root) return 0;

        if(head->val!=root->val) return false;

        return help(head->next,root->left)|| help(head->next,root->right);

     }
    bool isSubPath(ListNode* head, TreeNode* root) {

        if(!root) return false;

        return help(head,root)||isSubPath(head,root->left)||isSubPath(head,root->right);
        
    }
};