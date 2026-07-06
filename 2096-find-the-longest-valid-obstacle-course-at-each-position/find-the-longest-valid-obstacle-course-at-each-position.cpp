class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {

        int n=o.size();
        vector<int>ans(n,0);
        vector<int>temp;
         
         for(int i=0;i<n;i++){

         
         if(temp.size()==0){
            temp.push_back(o[i]);

            ans[i]=temp.size();
         }

         else if(temp.back()<=o[i]){
              temp.push_back(o[i]);

            ans[i]=temp.size();
         }

         else {
            auto it=upper_bound(
                temp.begin(),
                temp.end(),
                o[i]
            );
            auto idx=it-temp.begin();
            temp[idx]=o[i];
            ans[i]=idx+1;
            
             }
          


         }
        
        return ans;
    }
};