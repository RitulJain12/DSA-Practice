#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* bst(Node*root,int val){
    if(!root) return new Node(val);
    if(val<root->data){
        root->left=bst(root->left,val);
    }
    else{
        root->right=bst(root->right,val);
    }
    return root;
}

int main(){
    Node* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        root=bst(root,val);
    }
    return 0;
}