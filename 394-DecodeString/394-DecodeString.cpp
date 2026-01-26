// Last updated: 1/26/2026, 10:55:47 AM
1class Solution {
2public:
3    string decodeString(string s) {
4        stack<char>st;
5        for(int i=0;i<s.length();i++){
6            if(s[i]!=']'){
7                st.push(s[i]);
8            }
9            else{
10                string substr = "";
11                while(st.top()!='['){
12                    substr = st.top() + substr;
13                    st.pop();
14                }
15                st.pop();
16                string reps = "";
17                while(!st.empty() && isdigit(st.top())){
18                    reps = st.top() + reps;
19                    st.pop();
20                }
21                int repint = stoi(reps);
22                while(repint--){
23                    for(int j=0;j<substr.size();j++){
24                        st.push(substr[j]);
25                    }
26                }
27            }
28        }
29
30        s = "";
31        while(!st.empty()){
32            s = st.top() + s;
33            st.pop();
34        }
35        return s;
36    }
37};