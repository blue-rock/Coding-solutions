// Last updated: 11/2/2025, 10:27:03 PM
import java.util.*;
class Solution {
    public long putMarbles(int[] weights, int k) {
        List<Integer> splits = new ArrayList<>();
        for(int i=0 ; i< weights.length -1 ; i++){
            splits.add(weights[i] + weights[i+1]);
        }

        Collections.sort(splits);
        long minscore = weights[0] + weights[weights.length-1];
        long maxscore = weights[0] + weights[weights.length-1];
        int l = splits.size();
        for(int i=0;i<k-1;i++){
            minscore = minscore + (long) splits.get(i);
            maxscore = maxscore + (long) splits.get(l - 1 - i);
        }

        return maxscore - minscore;
    }
}



