#include<bits/stdc++.h>
using namespace std;
int main(){
    // we can color a graph easily by greedy if there were always less nodes than colors like in this question it is given that a node can have 4 colors but a node can have max 3 childs so we can use greedy here
      int n=5;//graph size having vertices 0 to 4
      vector<int>graph(n,-1);
    vector<int>color(n,-1);

    //for every node
    for(int i=0;i<n;i++){
        vector<bool> used(4,0) ;// local vis type
         for(auto nei:graph){
            if(color[nei]==1){
               used[color[nei]]=1;
            }
         }

         for(int c=1;c<=4;c++){
            if(used[c]!=1){
                color[c]=c;
                break;
            }
         }

    }
}


//leetcode 
// class Solution {
//     public:
//         vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
//             unordered_map<int,unordered_set<int>>graph;
//             for(auto pth:paths ) {
//                 graph[pth[0]-1].insert(pth[1]-1);
//                 graph[pth[1]-1].insert(pth[0]-1);
//             }
//             vector<int>ans(n,-1);
            
//             for(int i=0;i<n;i++){
//                        vector<bool>used(5,0);
//                     for(auto nei:graph[i]){
//                       if(ans[nei]!=-1){
//                         used[ans[nei]]=1;
//                       }
//                     }
    
//                     for(int c=1;c<=4;c++){
//                         if(used[c]!=1){
//                             ans[i]=c;
//                             break;
//                         }
//                     }
    
//             }
//             return ans;
//         }
//     };


