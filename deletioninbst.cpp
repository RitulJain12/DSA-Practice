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

Node* delt(Node *root,int key){
    if(!root) return root;
    if(key<root->data){
        root->left=delt(root->left,key);
    }
    else if(key>root->data){
        root->right=delt(root->right,key);
    }
    else{
        if(!root->left){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        Node* temp=root->right;
        while(temp && temp->left){
            temp=temp->left;
        }
        root->data=temp->data;
        root->right=delt(root->right,temp->data);
    }
}