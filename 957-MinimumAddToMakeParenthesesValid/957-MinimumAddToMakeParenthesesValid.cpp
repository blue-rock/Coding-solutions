// Last updated: 11/2/2025, 10:29:37 PM
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        int count = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                stk.push(s[i]);
            }
           else if (s[i]==')')
            {
                if(!stk.empty() && stk.top()=='(')
                {
                    stk.pop();
                }
                else
                {
                    count = count + 1;
                }
            }
        }
        while(!stk.empty())
        {
            count = count + 1;
            stk.pop();
        }
        return count;
    }
};