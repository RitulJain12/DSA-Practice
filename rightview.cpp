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
unordered_map<int, int> levelMap;

int help(TreeNode *root,int level){
    if(root==NULL) return 0;

    levelMap[level]=root->val;
    help(root->left,level+1);
    help(root->right,level+1);

}

vector<int> rightView (TreeNode *root) {
    vector<int> result;
    help(root, 1);
    for (const auto &pair : levelMap) {
        result.push_back(pair.second);
    }
    return result;
}

int main() {
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> result = rightView(root);
    cout << "Right view of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}