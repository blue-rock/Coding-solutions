class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int left = 0;
        int right = 0;
        unordered_map<char,int>mp;
        int temp=0;
        while(right<s.size()){
            if(mp[s[right]]==0){
           
                int len = right-left+1; //windowsssss
                ans = max(ans,len);
                  mp[s[right]]++;
                right++;
            }
            else{
                mp[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};