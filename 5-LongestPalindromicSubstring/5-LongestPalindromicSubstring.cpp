// Last updated: 11/2/2025, 10:35:54 PM
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<2){
            return s;
        }
        string ans = "";
        for(int i=0;i<n;i++){
            expandFromCenter(i, i, ans,s);
            expandFromCenter(i,i+1,ans,s);
        }
        return ans;
    }
    void expandFromCenter(int left, int right,string& ans, string s){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            if((right-left+1)>ans.length()){
                ans = s.substr(left,right-left+1);
            }
            left--;
            right++;
        }
    }

};

/*
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
*/