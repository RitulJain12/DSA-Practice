
//its a best solution for this problem using sqrt decomposition technique we have to find the maximum element in the segment of size a and then we have to check if the fruit can be placed in that segment or not if it can be placed then we have to update the maximum element in that segment and if it cannot be placed then we have to increment the answer by 1 and return the answer at the end.
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {

        int n=b.size();
        int a=sqrt(n);

        vector<int>d;
            
                         int maxi=0,cnt=0;
                         for(int i=0;i<n;i++){

                            if(cnt==a){
                                d.push_back(maxi);
                                cnt=1;
                                maxi=b[i];
                            
                            }  

                            else{ maxi=max(maxi,b[i]);cnt++;}

                         }

                         d.push_back(maxi); 

                   int ans=0;      

             for(int i=0;i<n;i++){
                   
                   int segIdx=-1;

                   for(int k=0;k<d.size();k++){
                     if(d[k] >= f[i]){
                        segIdx=k;
                        break;
                     }
                   }

                   if(segIdx==-1){
                    ans++;
                    continue;
                   }


                   int st=segIdx*a;
                   int end=min(n,st+a);
                   int idx=-1;
                   for(int j=st;j<end;j++){
                   
                    if(b[j]>=f[i]){
                          idx=j;
                          b[j]=0;
                        break;
                     }

                   }

                 int mx=b[st];

                  for(int j=st;j<end;j++){
                   
                      mx=max(mx,b[j]);

                   }

                   d[segIdx]=mx;
             }


             return ans;
        
    }
};