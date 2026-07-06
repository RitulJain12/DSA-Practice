class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {

        int n=target.size();
        int m=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[target[i]]=i;

        vector<int>v;
        for(int i=0;i<m;i++) if(mp.find(arr[i])!=mp.end()) v.push_back(mp[arr[i]]);

        vector<int>temp;
        int ans=0;
   //    vector<int> temp;

for (int e : v) {
    auto it = lower_bound(temp.begin(), temp.end(), e);

    if (it == temp.end())
        temp.push_back(e);
    else
        *it = e;
}

return n - temp.size();
        
    }
};