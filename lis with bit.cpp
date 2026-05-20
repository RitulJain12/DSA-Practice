class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int ans=0;
        int n=nums.size();

          for(int bit=0;bit<=30;bit++){

            vector<int>temp,lis;

            for(auto &e:nums) if((e & (1<<bit))!=0) temp.push_back(e);


            for(int i=0;i<temp.size();i++){

         auto it=lower_bound(lis.begin(),lis.end(),temp[i]);

         if(it==lis.end()) lis.push_back(temp[i]);
         else *it=temp[i];

            }

            ans=max(ans,(int)lis.size());

          }
        return ans;
    }
};