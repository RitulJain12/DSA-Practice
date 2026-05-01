//the top view hides the nodes which are hidden by other nodes when viewed from the top. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top. The top view of a binary tree can be obtained by performing a level order traversal of the tree and keeping track of the horizontal distance of each node from the root. The horizontal distance of the root is 0, the horizontal distance of the left child is -1, and the horizontal distance of the right child is +1. For each horizontal distance, we keep track of the first node that we encounter at that distance, which will be part of the top view.
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int lftmost=0,rightmost=0;
void find(TreeNode *root,int level){
    if(root==NULL) return;
    lftmost=min(lftmost,level);
    rightmost=max(rightmost,level);
    find(root->left,level-1);
    find(root->right,level+1);
}


vector<int> result;
void help(TreeNode *root,int pos){
    if(root==NULL) return;
    
     result[pos-lftmost]=root->val;

    help(root->left,pos-1);
    help(root->right,pos+1);
}

 int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
      find(root,0);
      result.resize(rightmost-lftmost+1,-1);
     help(root,0);
    cout << "Top view of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}