// Last updated: 11/2/2025, 10:33:56 PM
class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                a += tolower(s[i]);
            }
        }
        string b = a;
        reverse(a.begin(), a.end());
        if(a==b){
            return true;
        }
        return false;
    }
};