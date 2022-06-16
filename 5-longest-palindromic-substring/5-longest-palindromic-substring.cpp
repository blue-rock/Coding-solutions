class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int n = size(s);
        string longestSub{""};
        
        for(int i = 0; i != n; ++i){
            expandFromCenter(i, i, s, longestSub);
            expandFromCenter(i, i+1, s, longestSub);
        }
        return longestSub;
    }
    
    void expandFromCenter(int left, int right, string& s, string& longestSub){
        while(left >= 0 and right < s.size() and s[left] == s[right]){
            int currLen = (right-left+1);
            if(currLen > longestSub.size()){
                longestSub = s.substr(left, currLen);
            }
            --left, ++right;
        }
    }
};