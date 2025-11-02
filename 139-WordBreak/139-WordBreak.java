// Last updated: 11/2/2025, 10:33:42 PM
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Integer l1 = s.length();
        Integer l2 = wordDict.size();
        boolean[] dp = new boolean[l1+1];
        dp[l1] = true; //Base Case
        
        for(int i=l1-1; i>=0 ; i--){
            for(String word: wordDict){
                if(i+word.length()<=l1 && s.substring(i,i + word.length()).equals(word)){
                   dp[i] = dp[i + word.length()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
}