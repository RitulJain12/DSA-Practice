class Solution {
public:
 unordered_map<int,set<pair<int,int>>>graph;
 unordered_set<int>vis;
 void dfs(int src,int & ans){
    vis.insert(src);
    for(auto ele:graph[src]){
        auto[e,cost]=ele;
        ans=min(ans,cost);
        if(!vis.count(e)) dfs(e,ans);
    }
 }
    int minScore(int n, vector<vector<int>>& roads) {
        int ans=0,minans=INT_MAX;
        for(auto rd:roads){
            graph[rd[0]].insert({rd[1],rd[2]});
            graph[rd[1]].insert({rd[0],rd[2]});
        }
       dfs(1,minans);
        return minans;
    }
};