#include <bits/stdc++.h>
using namespace std;
//i tried it with solving via k loop but it was giving tle so i solved it with recursion and memoization pick skip is better than k loop in this case because we are only interested in the sum of digits and not the actual numbers so we can skip the numbers which are not giving us the required sum of digits and also we can memoize the results to avoid recalculating the same state multiple times.
class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> memo;

    bool check(int s,int sum){
        int t = 0;
        while(s>0){
            int lt = s%10;
            t += lt;
            s = s/10;
        }
        return t==sum;
    }

    int solve(int idx,int s,vector<int>& digitSum){
        if(idx==digitSum.size()) return 1;
        if(s>5000) return 0;

        if(memo[idx][s]!=-1) return memo[idx][s];

        int res = 0;

        if(check(s,digitSum[idx])){
            res = (res + solve(idx+1,s,digitSum))%MOD;
        }

        res = (res + solve(idx,s+1,digitSum))%MOD;

        return memo[idx][s] = res;
    }

    int countArrays(vector<int>& digitSum) {
        int n = digitSum.size();

        memo.assign(n+1,vector<int>(5005,-1));

        return solve(0,0,digitSum);
    }
};