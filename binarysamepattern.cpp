
//same essa question he 3608. Minimum Cost to Connect All Points
class Dsu{

public:
vector<int>p,sz;

    Dsu(int n){
       p.resize(n,0);
       sz.resize(n,0);
       for(int i=0;i<n;i++) p[i]=i;
    }

    int find(int a){

        if(p[a]==a) return a;

        return p[a]=find(p[a]);

    }

    bool uni(int a,int b){

        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (sz[a] < sz[b])
            swap(a, b);

        p[b] = a;
        sz[a] += sz[b];

        return true;


    }


};
class Solution {
public:
    bool can(int mid, vector<vector<int>>& edges, int k,int n){
        int cmp=n;
         Dsu d(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i][2]<=mid){
                if(d.uni(edges[i][0],edges[i][1])) cmp--;
            }
        }

        return cmp<=k;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {

        int l=0,h=0;
        for(int i=0;i<edges.size();i++) h=max(h,edges[i][2]);
         int  ans=0;

        while(l<=h)

        {

            int mid=l+(h-l)/2;
            if(can(mid,edges,k,n)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};