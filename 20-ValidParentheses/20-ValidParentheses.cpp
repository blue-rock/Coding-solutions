// Last updated: 11/2/2025, 10:35:39 PM
class Solution {
public:
    bool isValid(string s) {
        //stack for maintaining latest open parantheses

        stack<char> stk;
        int l = s.length();

        for(int i=0;i<l;i++){
            if(isOpenParatheses(s[i])){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                else if(isNotMatchingWithLatestOpenParatheses(s[i], stk.top())){
                    return false;
                }
                else{
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }

    bool isOpenParatheses(char c){
        return c=='[' || c== '{' || c=='(';
    }

    bool isNotMatchingWithLatestOpenParatheses(char c1, char c2){
        return (c1=='}' && c2!='{') || (c1==']' && c2!='[') || (c1==')' && c2!='(');
    }
};