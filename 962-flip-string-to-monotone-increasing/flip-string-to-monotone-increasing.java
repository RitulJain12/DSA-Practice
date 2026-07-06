class Solution {
    public int minFlipsMonoIncr(String s) {

        int n=s.length();
        int res=0;
        int o=0,z=0;
        for(int i=0;i<n;i++){
            char c=s.charAt(i);
            if(c=='1'){
               o++;
            }
            else{
                int temp1=o;
                int temp2=res+1;
                res=Math.min(temp1,temp2);
            }
        }

        return  res;
        
    }
}