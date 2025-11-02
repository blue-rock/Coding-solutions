// Last updated: 11/2/2025, 10:29:32 PM
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        
        for (auto a : pushed) {
            s.push(a); //push the pushed vector into a stack
            //5 4 3 2 1 - stack
            //4-5-3-2-1-
            while (!s.empty() && s.top() == popped[i]) {//pop if values are same 
                s.pop();
                i++;
            }
        }
        
        return i == pushed.size();
    }
};