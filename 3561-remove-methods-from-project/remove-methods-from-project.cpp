class Solution {
public:
    void dfs(int src,  unordered_set<int>&vis,vector<vector<int>>&grph){
          vis.insert(src);

          for(auto &n:grph[src]){
            if(!vis.count(n))  dfs(n,vis,grph);
          }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

       // int n=invocations.size();

        vector<vector<int>>grph(n);

        for(auto & i:invocations)
        {
            grph[i[0]].push_back(i[1]);
        }

        unordered_set<int>vis;

        dfs(k,vis,grph);

        bool remo=1;

        for(auto &v:invocations){

            int src=v[0];
            int des=v[1];

            if(vis.count(des) && !vis.count(src)) remo=0;
        }
        vector<int>ans;

       if(!remo){
        for(int i=0;i<n;i++) ans.push_back(i);
        return ans;
       }
        

           for(int i=0;i<n;i++) if(!vis.count(i))ans.push_back(i);
        return ans;

    }
};