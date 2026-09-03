class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
         int mn = *min_element(nums1.begin(), nums1.end());
        
        bool hasOdd = false;
        for(int x : nums1){
            if(x % 2) hasOdd = true;
        }
        
      
        if(mn % 2 == 0 && hasOdd) return false;
        
        return true;
    }
};