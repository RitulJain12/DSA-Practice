#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int width(Tree* Node){

    if(!Node) return 0;

    queue<pair<Node*,long long>>q;

    int ans=1;

    q.push({Node,0});

    while(q.size()){

        int sz=q.size();
        int st=q.front().second;
        int end=q.back().second;
        ans=max(ans,end-st+1);
        for(int i=0;i<sz;i++){
        
            pair<TreeNode*, int> p = q.front();
            long long idx = p.second - start;
            
            q.pop();
            
        
            if(p.first->left != NULL)
                q.push({p.first->left, (long long)2 * idx + 1});
            

            if(p.first->right != NULL)
                q.push({p.first->right, (long long) 2 * idx + 2});


        }

 

    }

  return ans;
} 


int main(){




}