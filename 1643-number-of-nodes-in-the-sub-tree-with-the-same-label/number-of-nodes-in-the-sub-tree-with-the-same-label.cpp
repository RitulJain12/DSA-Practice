class Solution {
public:
     unordered_set<int>vis;
    vector<int>dfs( vector<int>&ans,vector<vector<int>>&graph,int s,string &l){

          vector<int>v(26,0);
          vis.insert(s);
           v[l[s]-97]++;

           for(auto & e:graph[s])
           {
                 if(vis.contains(e)) continue;
                  auto res=dfs(ans,graph,e,l);
                 for(int i=0;i<26;i++) v[i]+=res[i];
           }
        
      //   cout<<l[s]<<" ";

     // cout<<ans[s]<<endl;
     //cout<<v[l[s]-97]<<endl;

     ans[s]=v[l[s]-97];


           return v;


    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<vector<int>>graph(n,vector<int>());
        vis.clear();

        for(auto &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int>ans(n,0);

        dfs(ans,graph,0,labels);


        return ans;
        
    }
};