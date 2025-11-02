// Last updated: 11/2/2025, 10:35:37 PM
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generateans(n*2, 0, 0, ans, "");
        return ans;
    }

    void generateans(int n, int nopen, int nclose, vector<string>& ans, string curr){
        if(nopen+nclose==n){
            ans.push_back(curr);
            return;
        }
        if(nopen<n/2){
        generateans(n, nopen + 1, nclose, ans, curr + '(');
        }
        if(nclose<nopen){
            generateans(n, nopen, nclose+1, ans, curr+ ')');
        }

    }
};