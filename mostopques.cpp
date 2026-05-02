//it  is basically a greedy approach where we will check if the current element is 0 and the number of flips done till now is even then we will flip the next k elements and if the current element is 1 and the number of flips done till now is odd then we will also flip the next k elements and we will keep track of the number of flips done till now and also the number of flips done at each index in a separate array so that we can easily check if we need to flip or not at each index.

//it is a best  pattern question and the time complexity of this approach is O(n) and the space complexity is O(n) as we are using an extra array to keep track of the flips done at each index.


// i was thinking about brute force approach but it will give tle as we will have to check for each index and flip the next k elements and this will give us a time complexity of O(n*k) which is not efficient for large inputs.


// agar  tu dhyan se dekhega na toh pata chlega ki ye bhi same approach hai brute force wali bass isme optimise way me previous k flips ko track kar rahe hai taaki hume baar baar flip karne ki jarurat na pade aur isse time complexity O(n) ho jati hai. agar hr window traverse kru toh k multiple extra ajata he






class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>check(n,0);
        int ans=0,flip=0;
        for(int i=0;i<n;i++){
          if(i-k>=0 && check[i-k]==1) flip--;
          if(nums[i]==0 && flip%2==0){
            if(i+k>n) return -1;
            check[i]=1;
            ans++;
            flip++;
          }
          else if(nums[i]==1 && flip%2!=0){
            if(i+k>n) return -1;
            check[i]=1;
            ans++;
            flip++;
          }
        }
        return ans;
    }
};