class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {


        if(finalSum%2!=0) return {};

        vector<long long>ans;
         long long curr=2;
        while(finalSum>=curr){
              finalSum-=curr;
            ans.push_back(curr);
            curr+=2;

        }
        if(finalSum>0)  ans.back()+=finalSum;
        return ans;
    }
};