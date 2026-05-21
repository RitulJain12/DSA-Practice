class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int n=arr1.size(),m=arr2.size();
        unordered_set<int>st;

        for(auto &ele:arr1){
         
            while(ele){
                st.insert(ele);
                ele/=10;
            }

        }
        
          int ans=0;
        for(auto &ele:arr2){
            
            while(ele){
              if(st.count(ele)){
                int temp=ele,a=0;
                while(temp){
                 a++;temp/=10;
                }
                ans=max(ans,a);
              }
                ele/=10;
            }

        }

        return  ans;
    }
};