// Last updated: 11/2/2025, 10:31:48 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int low = 0;
        int result = 0;
        int maxf = 0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            maxf = max(maxf, mp[s[i]]);
            if(i-low+1 - maxf >k ){
            mp[s[low]]--;
            low++;
            }
            else{
                result = max(result, i-low+1);
            }
        }
        return result;
    }
};


/*
1) put all characters in map
2) iterate over each time you add a character to get the frequency
3) if it's max freq, set it to maxf
*/