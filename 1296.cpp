// it is best question
#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

bool canPosTodivide(vector<int>& nums,int k) {
  for(auto &x: nums) {
    mp[x]++;
  }
  while (mp.size())
  {
    auto p=*mp.begin();
    int a=p.first;

     for(int i=0;i<k;i++){
       if(!mp.size() || mp.find(a+i)==mp.end())return false;
       mp[a+i]--;
       if(mp[a+i]==0) mp.erase(a+i);
     }

  }
  
  return true;

}
int main(){
  vector<int> nums = {1, 2, 3, 4, 5,6};
  int k = 3;
  cout << canPosTodivide(nums, k) << endl;
  return 0;
}