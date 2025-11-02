// Last updated: 11/2/2025, 10:32:00 PM
class Solution {
public:
    int longestSubstring(string s, int k) {
        return hehe(s,k,0,s.length());
    }
    int hehe(string s, int k, int start, int end){
        if(end - start<k){
            return 0;
        }
        int count[26] = {0};
        for (int i = start; i < end; i++) {
            count[s[i] - 'a']++;
        }
        for(int i=start;i<end;i++){
            if(count[s[i] - 'a']<k){
                int left = hehe(s,k,start,i);
                int right = hehe(s,k,i+1,end);
                return max(left,right);
            }
        }
        return end - start;
    }
};