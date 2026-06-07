// isme ek great obs ye he ki agar array sorted h to adjacent elements ka difference hi check karna hoga usse hi graph ban jayega
class Dsu {
public:
    vector<int> p, sz;

    Dsu(int n) {
        p.resize(n);
        sz.resize(n,1);

        for(int i=0;i<n;i++)
            p[i]=i;
    }

    int find(int x){
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }

    void uni(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return;

        if(sz[a] > sz[b]) swap(a,b);

        p[a]=b;
        sz[b]+=sz[a];
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries) {

        Dsu d(n);

        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i] <= maxDiff)
                d.uni(i,i+1);
        }

        vector<bool> ans;

        for(auto &q:queries){
            ans.push_back(
                d.find(q[0]) == d.find(q[1])
            );
        }

        return ans;
    }
};