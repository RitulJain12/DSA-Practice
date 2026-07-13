class DSU {

public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    bool unionBySize(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u == v)
            return false;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];

        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>>vp;

        int n=points.size();
           
           for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {

        int dis = abs(points[i][0] - points[j][0]) +
                  abs(points[i][1] - points[j][1]);

        vp.push_back({dis, {i, j}});
    }
}
           sort(vp.begin(),vp.end(),[&](pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){

                return a.first<b.first;
           });
           DSU d(n);
           int eds=0,cost=0;

             for(auto &e:vp){
                  
                  auto &p=e.second;

                  if(d.unionBySize(p.first,p.second)){
                    cost+=e.first;
                    eds++;
                    if(eds==n-1) break;
                  }

             }

          return cost;
    }
};