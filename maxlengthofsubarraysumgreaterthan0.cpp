//subarray with sum greater than 0
#include<bits/stdc++.h>
using namespace std;

int maxLengthSubarraySumGreaterThanZero(vector<int>& nums) {
    int maxLength = 0;
    int currentSum = 0;
    unordered_map<int, int> sumIndexMap;
    sumIndexMap[0] = -1;  

    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] > 8) {
            currentSum += 1;
        } else {
            currentSum -= 1;
        }

    
        if (currentSum > 0) {
            maxLength = i + 1;
        }

    
        if (sumIndexMap.find(currentSum-1) != sumIndexMap.end()) {
            maxLength = max(maxLength, i - sumIndexMap[currentSum-1]);
        } 

        if (sumIndexMap.find(currentSum) == sumIndexMap.end()) {
            sumIndexMap[currentSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {6,6,6,1,23,2,1,3,4,2,2};
    int result = maxLengthSubarraySumGreaterThanZero(nums);
    cout << "Maximum length of subarray with sum greater than 0: " << result << endl;
    return 0;
}