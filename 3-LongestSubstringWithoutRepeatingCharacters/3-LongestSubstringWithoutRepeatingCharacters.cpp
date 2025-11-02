// Last updated: 11/2/2025, 10:35:57 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int low = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            char w = s[i];
            mp[w]++;
            if(mp[w]>1)
            {
                while(mp[w]!=1 && low<i){
                    mp[s[low]]--;
                    low ++;
                }
            }
            ans = max(ans, i-low+1);
        }
        return ans;
    }
};