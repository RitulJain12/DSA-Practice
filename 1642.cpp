//it is the best greedy question i  have ever seen since it is solved from first thought principle and it is not a dp question as many people think



class Solution {
    public:
    
        int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
                 int n=heights.size();
                 priority_queue<int>pq;
                int i=0;
                while(i+1<n){
                while(i+1<n &&heights[i]>=heights[i+1]) i++;
                if(i+1==n) return i;
                 int diff=heights[i+1]-heights[i];
            
                    pq.push(diff);
                    bricks-=diff;
                    
                
                if(bricks<0){
                  if(ladders==0) return i;
                    bricks+=pq.top();
                    pq.pop();
                    ladders--;
                 
                 }
                    i++;

                }  
                 return n-1;
        }
    };

    // we simply need to use bricks untill it become zero and then we need top difference so far we used to we can replace that bricks with ladder and  we can use those bricks for current difference and if we have no ladder left then we can not move forward and return the index of current building

