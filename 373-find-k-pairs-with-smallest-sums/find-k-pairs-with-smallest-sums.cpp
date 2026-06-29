class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> ans;

        int n1=nums1.size(),n2=nums2.size(),i,x,y,sum;

        for(i=0;i<n1;i++)
        {
            sum=nums1[i]+nums2[0];
            pq.push({sum,{i,0}});
        }

        while(!pq.empty() and ans.size()<k)
        {
            x=pq.top().second.first;
            y=pq.top().second.second;
            pq.pop();

            ans.push_back({nums1[x],nums2[y]});

            if((y+1)<n2)
            {
                sum=nums1[x]+nums2[y+1];
                pq.push({sum,{x,y+1}});
            }
        }
        
        return ans;
    }
};