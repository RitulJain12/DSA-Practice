
// the only thing to solve is we need to know that or is becoming min or same when we take more edges so we can just take the and of all the edges in the same component and that will be the answer for all the queries in that component
class Dsu{
    public:
    vector<int>p,s;

    Dsu(int n){
        p.resize(n,0);
        s.resize(n,0);
        for(int i=0;i<n;i++) p[i]=i;
    }

    int find(int a){
        if(p[a]==a) return a;
        return p[a]=find(p[a]);
    }
     void uni(int  a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return ;

        if(s[a]>s[b]) swap(a,b);
        s[b]+=s[a];
        p[a]=b;
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        Dsu d(n);
        vector<int>comp(n,(1<<17)-1);

        for(auto &e:edges){
            d.uni(e[0],e[1]);
        }
       for (auto &e : edges) {
            int root = d.find(e[0]);
            comp[root] &= e[2];
        }
        vector<int>ans;
          
          for(auto &q:query){
               
               if(d.find(q[0])==d.find(q[1])){
                    
                    ans.push_back(comp[d.find(q[0])]);
               }
               else ans.push_back(-1);
          }


          return ans;
    }
};