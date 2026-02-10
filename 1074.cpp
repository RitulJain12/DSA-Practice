#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    mp[0] = 1;                 
    int sum = 0, count = 0;

    for (int x : nums) {
        sum += x;
        if (mp.find(sum - target) != mp.end()) {
            count += mp[sum - target];
        }
        mp[sum]++;
    }
    return count;
}

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int ans = 0;


    for (int top = 0; top < rows; top++) {
        vector<int> temp(cols, 0);   

    
        for (int bottom = top; bottom < rows; bottom++) {

        
            for (int c = 0; c < cols; c++) {
                temp[c] += matrix[bottom][c];
            }

           
            ans += helper(temp, target);
        }
    }
    return ans;
}

int main(){
    //agar 2d array me sum of subaaray of 2d matrix diya == target find krna he toh humko basically usko 1d me convert krna pdega uska pura flow ye rahega ki hum nested loop chalaynge hr top k liye bottom tak or sum add krte jaynge and hr vector k liye prefix hashmap sum-k pattern lagaynge
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };
    
    int ans= numSubmatrixSumTarget(matrix,1);
    cout<<ans;
}