class Solution {
public:

    unordered_map<int, vector<pair<int,int>>> graph;

    void bfs(int source,int tar,vector<int>&dis,int th){

        deque<int>dq;
        dis[source]=0;
        dq.push_front(source);

            while(dq.size()){
               int frnt=dq.front();dq.pop_front();

               for(auto &it:graph[frnt]){
                     int wt=it.second;
                     int adj=it.first;
                   int cost= wt>th?1:0;

                if(dis[frnt]+cost<dis[adj]){

                    dis[adj]=cost+dis[frnt];
                    if(cost==0) dq.push_front(adj);
                    else dq.push_back(adj);

                }

               }
                

            }

    }

    bool can(int source, int target, int k, int thre,int n) {

        vector<int>dis(n,INT_MAX);
        bfs(source, target,dis,thre);

        return dis[target]<= k;
    }

    int minimumThreshold(int n,
                         vector<vector<int>>& edges,
                         int source,
                         int target,
                         int k) {

        if(source == target)
            return 0;

        graph.clear();

        int l = 0;
        int h = INT_MIN;

        for(auto &e : edges) {

            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});

            h = max(h, e[2]);
        }

        int ans = -1;

        while(l <= h) {

            int mid = l + (h - l) / 2;

            if(can(source, target, k, mid,n)) {

                ans = mid;

                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};