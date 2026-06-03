class Solution {
public:

    bool can(int mid, vector<int>& price, int k)
    {
        int cnt = 1;
        int last = price[0];

        for(int i=1;i<price.size();i++)
        {
            if(price[i] - last >= mid)
            {
                cnt++;
                last = price[i];
            }
        }

        return cnt >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {

        sort(price.begin(), price.end());

        int l = 0;
        int h = price.back() - price.front();

        int ans = 0;

        while(l <= h)
        {
            int mid = l + (h-l)/2;

            if(can(mid, price, k))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return ans;
    }
};