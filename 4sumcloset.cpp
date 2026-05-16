class Solution {
public:
    int fourSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long closest =
            (long long)nums[0] + nums[1] + nums[2] + nums[3];

        for(int i = 0; i < n - 3; i++) {

            for(int j = i + 1; j < n - 2; j++) {

                int left = j + 1;
                int right = n - 1;

                while(left < right) {

                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[left] +
                        nums[right];

                    if(abs(sum - target) < abs(closest - target)) {
                        closest = sum;
                    }

                    if(sum < target) {
                        left++;
                    }
                    else if(sum > target) {
                        right--;
                    }
                    else {
                        return target;
                    }
                }
            }
        }

        return closest;
    }
};