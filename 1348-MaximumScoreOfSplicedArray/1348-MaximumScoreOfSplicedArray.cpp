// Last updated: 11/2/2025, 10:28:37 PM
class Solution {
public:
    vector<vector<int>> dp, dp2;
    vector<int> a1,a2;
    int dfs(int index, int t) {
        
        if(index == a1.size()) return 0;
        if(dp[index][t]!=-1) return dp[index][t];
        int res = 0;
        if(t == 0){
            res = a1[index] + dfs(index+1,0);
            res = max(res, a1[index] + dfs(index+1,1));
        }
       else if(t == 1) {
           res = a2[index] + dfs(index+1,1);
           res = max(res, a2[index] + dfs(index+1,2));
       }
        else res = a1[index] + dfs(index+1,2);
      return dp[index][t] = res;
        
    }
                      
       int dfs2(int index, int t) {
        
        if(index == a1.size()) return 0;
        if(dp2[index][t]!=-1) return dp2[index][t];
        int res = 0;
        if(t == 0){
            res = a2[index] + dfs2(index+1,0);
            res = max(res, a2[index] + dfs2(index+1,1));
        }
       else if(t == 1) {
           res = a1[index] + dfs2(index+1,1);
           res = max(res, a1[index] + dfs2(index+1,2));
       }
        else res = a2[index] + dfs2(index+1,2);
      return dp2[index][t] = res;
        
    }
                      
    int maximumsSplicedArray(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        this->a1 = a1;
        this->a2 = a2;
        dp = vector<vector<int>>(n + 20, vector<int>(3,-1));
        dp2 = vector<vector<int>>(n + 20, vector<int>(3,-1));
        
        return max(dfs(0,0), dfs2(0,0));
        
    }
};