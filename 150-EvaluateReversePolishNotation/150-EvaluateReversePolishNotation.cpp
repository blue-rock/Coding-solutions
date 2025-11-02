// Last updated: 11/2/2025, 10:33:33 PM
class Solution {
public:
int solve(int a, int b, string op){
        if(op=="+"){
            return b+a;
        }else if(op=="-"){
            return b-a;
        }else if(op=="*"){
            return b*a;
        }else{
            return floor(b/a);
        }
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if((tokens[i] == "+") || (tokens[i] == "-")  || (tokens[i] == "/") || (tokens[i] == "*") ){
                    int fnum = st.top();
                    st.pop();
                    int snum = st.top();
                    st.pop();
                    int tempres = solve(fnum, snum, tokens[i]);
                    st.push(tempres);
                }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        if(ans==INT_MIN && !st.empty()){
            return st.top();
        }
        return ans;
    }
};

/*

["3","11","+","5","-"]

5
14-5

*/