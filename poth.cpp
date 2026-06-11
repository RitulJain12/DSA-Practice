class Solution {
public:
    vector<vector<int>> graph;
    const int mod=1e9+7;
    long long power(int a,int b){
        int temp=0;
        long long ans=1;
        while(temp<b){
            ans=(ans*2)%mod;
            temp++;
        }
        return ans;
    }
    void dfs(int src, int d,
             unordered_set<int>& used,
             unordered_map<int,int>& dep) {

        used.insert(src);
        dep[src] = d;

        for(auto nxt : graph[src]) {
            if(!used.count(nxt))
                dfs(nxt, d + 1, used, dep);
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        graph.resize(n + 1);

        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        unordered_set<int> used;
        unordered_map<int,int> dep;

        dfs(1, 0, used, dep);

        int maxi = 0;

        for(auto &p : dep)
            maxi = max(maxi, p.second);

        long long ans=power(2,maxi-1);

        return (int)ans;
    }
};