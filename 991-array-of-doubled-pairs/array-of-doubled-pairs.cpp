class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {

        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(auto &i:arr) mp[i]++;
        int ans=0;

        for(int i=0;i<n;i++)
        {
             if(mp.count(arr[i]) && mp.count(arr[i]*2)){
                mp[arr[i]]--;
                mp[arr[i]*2]--;
                if(mp[arr[i]]==0) mp.erase(arr[i]);
                 if(mp[arr[i]*2]==0) mp.erase(arr[i]*2);
                ans++;
             }
        }
        
        if(ans==n/2 && !mp.size()) return 1;

        return 0;
    }
};