//op difference sort pattern


class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {

        int n=t1.size();
        vector<int>idx;
        for(int i=0;i<n;i++)    idx.push_back(i);

        sort(idx.begin(),idx.end(),[&](int i,int j){
             return t1[i]-t2[i]>t1[j]-t2[j];
        });

        long long ans=0;

        for(int i=0;i<k;i++)  ans+=t1[idx[i]];
        for(int i=k;i<n;i++)    ans+=max(t1[idx[i]],t2[idx[i]]);
        
        
        return ans;
        
    }
};