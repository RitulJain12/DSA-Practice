class Solution {
public:
   
     unordered_set<int>vis;
     unordered_map<int,unordered_set<int>>graph;
     void dfs(int src,  unordered_set<int>&st){
        vis.insert(src);
        st.insert(src);
        for(auto n:graph[src]){
            if(!vis.count(n)){
                vis.insert(n);
                 st.insert(n);
                 dfs(n,st);
            }
        }
     }
     bool check( unordered_set<int>st){
       for(auto a:st){
        if(graph[a].size()!=st.size()-1) return false;
       }
       return true;
     }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
       for(auto v:edges){
        graph[v[0]].insert(v[1]);
        graph[v[1]].insert(v[0]);
       }
      int ans=0;
      for(int i=0;i<n;i++){
      unordered_set<int>st;
       if(!vis.count(i)) {
        dfs(i,st);
        if(check(st)) ans++;
       }

      }

return ans;
    }

};