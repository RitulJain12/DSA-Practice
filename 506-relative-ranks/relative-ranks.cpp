class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n = score.size();
        vector<string>ans(n);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({score[i],i});
        }
        int r = 0;
        while(!pq.empty())
        {
            if(r==0)
            {
                ans[pq.top().second] = "Gold Medal";
                pq.pop();
                r++;
            }
            else if(r==1)
            {
                ans[pq.top().second] = "Silver Medal";
                pq.pop();
                r++;
            } 
            else if(r==2)
            {
                ans[pq.top().second] = "Bronze Medal";
                pq.pop();
                r++;
            }
            else
            {
                int t = r+1;
                ans[pq.top().second] = to_string(t);
                pq.pop();
                r++;
            }
        }
        return ans;
    }
//please upvote...
};