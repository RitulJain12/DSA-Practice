public class Waterride {

        public static void main(String[] args) {
            int[] a={1,2,3};
            int[] b={1,2,3};
            int[] c={1,2,3};
            int[] d={1,2,3};
    
            Solution sol=new Solution();
            System.out.println(sol.earliestFinishTime(a,b,c,d));
        }
    
}

class Solution {
    public int earliestFinishTime(int[] a, int[] b, int[] c, int[] d) {

        int n=a.length;
        int m=c.length;
        int ans=Integer.MAX_VALUE;
        int mini=Integer.MAX_VALUE;


            for(int i=0;i<n;i++){

                mini=Math.min(mini,a[i]+b[i]);
            }

            for(int i=0;i<m;i++){
                ans=Math.min(ans,d[i]+Math.max(mini,c[i]));
            }

            //case 2 when i take waterride first;

            mini=Integer.MAX_VALUE;
            
              for(int i=0;i<m;i++){

                mini=Math.min(mini,c[i]+d[i]);
            }

            for(int i=0;i<n;i++){
                ans=Math.min(ans,b[i]+Math.max(mini,a[i]));
            }

        return ans;
    }
}
