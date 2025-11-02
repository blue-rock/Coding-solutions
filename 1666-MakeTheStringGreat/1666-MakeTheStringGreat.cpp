// Last updated: 11/2/2025, 10:27:49 PM
class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++)
        {
            stk.push(s[i]);
            while(!stk.empty() && ((stk.top()==s[i+1]+32) || (stk.top()==s[i+1]-32) ))
            {
                
                stk.pop();
                i++;
            }
        }
        string s2 = "";
        while(!stk.empty())
        {
            s2 = stk.top() + s2;
            stk.pop();
        }
        return s2;
    }
};
