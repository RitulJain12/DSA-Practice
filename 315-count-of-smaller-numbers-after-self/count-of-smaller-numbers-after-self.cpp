class Solution {
public:

    vector<int> tree;

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node]++;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid) {
            update(2 * node, start, mid, idx);
        } else {
            update(2 * node + 1, mid + 1, end, idx);
        }

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {

    
        if (r < start || end < l)
            return 0;


        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        return query(2 * node, start, mid, l, r)
             + query(2 * node + 1, mid + 1, end, l, r);
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

    
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        sorted.erase(unique(sorted.begin(), sorted.end()),
                     sorted.end());

        tree.resize(4 * sorted.size() + 1, 0);

        vector<int> ans(n);

     
        for (int i = n - 1; i >= 0; i--) {


            int pos = lower_bound(sorted.begin(),
                                  sorted.end(),
                                  nums[i]) - sorted.begin() ;

         
            ans[i] = query(1, 0, sorted.size()-1, 0, pos-1);

            update(1, 0, sorted.size()-1, pos);
        }

        return ans;
    }
};