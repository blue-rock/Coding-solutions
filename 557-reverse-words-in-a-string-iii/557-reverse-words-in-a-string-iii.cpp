class Solution {
public:
    string reverseWords(string s) {
        string res;
        for(int i=0;i<s.length();i++)
        {
            string currword = "";
            while(int(s[i])!=32 && i<s.length())
            {
                currword = currword + s[i];
                i++;
            }
            reverse(currword.begin(),currword.end());
            if(i!=s.length())
            {
                currword = currword + " ";
            }
            res = res + currword;
        }
        return res;
    }
};