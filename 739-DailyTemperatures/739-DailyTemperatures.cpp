// Last updated: 11/2/2025, 10:30:33 PM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        int n = t.size();
        vector<int> sol(n,0);
        st.push(n-1);
        int topIndex = n-1;

        for(int i=n-2;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && t[i]>=t[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                }
                else{
                    sol[i] = st.top() - i;
                    st.push((i));
                }
            }
        }
        return sol;
    }
};

/*
stack: 




76
73


*/