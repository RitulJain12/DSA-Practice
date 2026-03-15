// it is pure maths problem i can able to solve it in contest then i took a refrence from yt now i am clear i will broke  the same pattern problem in future;

class Solution {
    public:
        int longestArithmetic(vector<int>& nums) {
    
            int n=nums.size();
            int left[n],right[n];
    
            left[0]=1,left[1]=2;
            right[n-1]=1,right[n-2]=2;
    
            for(int i=2;i<n;i++){
                if(nums[i-1]-nums[i-2]== nums[i]-nums[i-1]) left[i]=left[i-1]+1;
                else left[i]=2;
            }
              for(int i=n-3;i>=0;i--){
                if(nums[i+2]-nums[i+1]== nums[i+1]-nums[i]) right[i]=right[i+1]+1;
                else right[i]=2;
            }
    
            int ans=2;
            ans=max(left[n-2]+1,ans);
            ans=max(right[1]+1,ans);
           for(int i=2;i<n-1;i++){
            ans=max(ans,left[i]+1);
             ans=max(ans,right[i]+1);
           }
               for(int i=1;i<n-1;i++){
                   int bet=nums[i+1]+nums[i-1];
                   if(bet%2==0){
                       int d=(nums[i+1]-nums[i-1])/2;
    
                       int lef=1,rght=1;
    
                       if(i>=2 && nums[i-1]-nums[i-2]==d)  lef=left[i-1];
                       if(i+2<n && nums[i+2]-nums[i+1]==d)  rght=right[i+1];
    
                    ans=max(ans,lef+rght+1);
                   }
               }
    
               return ans;
            
        }
    };