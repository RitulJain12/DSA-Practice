// 2071 it is a best pattern on bs  op question ,we need to thing greedly 


class Solution {
    public:
         bool can(vector<int>& tasks, vector<int>& workers, int pills, int &strength,int &mid){
                        int n=tasks.size();
                        int m=workers.size();
                        multiset<int>ms;
                  for(int i=m-mid;i<m;i++) ms.insert(workers[i]);
    
                  for(int i=mid-1;i>=0;i--){
    
                    int task=tasks[i];
    
                    auto it=ms.lower_bound(task);
                        if(it!=ms.end()){
                        ms.erase(it);
                         }
                       else{
                           if(pills==0) return false;
                           else{
                                auto it=ms.lower_bound(task-strength);
                                if(it==ms.end()) return false;
                                  ms.erase(it);
                                  pills--;
                           }
                       }
                  }
    
                  return true;
    
         }
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(),tasks.end());
            sort(workers.begin(),workers.end());
            multiset<int>mp(workers.begin(),workers.end());
            int n=tasks.size();
            int m=workers.size();
            int l=0,h=min(n,m);
            int ans=0;
            while(l<=h){
             int mid=l+(h-l)/2;
            if(can(tasks,workers,pills,strength,mid)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
    
           }
    
           return ans; 
        }
    };