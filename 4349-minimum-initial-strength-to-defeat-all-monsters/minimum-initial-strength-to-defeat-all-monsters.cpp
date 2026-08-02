class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
      int n=monsters.size();
    vector<long long> bonus(n,0);

for(auto &b : boosts){
    int l = b[0];
    int r = b[1];
    long long c = b[2];

    bonus[l] += c;
    if(r + 1 < n)
        bonus[r + 1] -= c;
}

for(int i = 1; i < n; i++)
    bonus[i] += bonus[i - 1];

long long prv = 0;
long long ans = 0;

for(int i = 0; i < n; i++){
    if(bonus[i] < monsters[i]){
        ans = max(ans, prv + (long long)monsters[i] - bonus[i]);
    }
    prv += monsters[i];
}

return ans;
    }
};