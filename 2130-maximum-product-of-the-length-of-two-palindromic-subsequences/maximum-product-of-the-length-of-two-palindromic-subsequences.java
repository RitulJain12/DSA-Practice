class Solution {
    public int maxProduct(String s) {
        return helper(s, 0, new StringBuilder(), new StringBuilder());
    }

    public int helper(String s, int i, StringBuilder s1, StringBuilder s2) {
        if(i == s.length()) {
            if(checkPal(s1.toString()) && checkPal(s2.toString())) {
                return s1.length() * s2.length();
            }
            return 0;
        }

        // s1 me liya
        s1.append(s.charAt(i));
        int first = helper(s, i + 1, s1 , s2);
        s1.deleteCharAt(s1.length() - 1);

        // s2 me liye
        s2.append(s.charAt(i));
        int second = helper(s, i + 1, s1 , s2);
        s2.deleteCharAt(s2.length() - 1);

        int third = helper(s, i + 1, s1, s2);
        return Math.max(first, Math.max(second, third));


    }

    public boolean checkPal(String s){
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s.charAt(i++) != s.charAt(j--)) return false;
        }
        return true;
    }
}