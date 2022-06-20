class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>ans;
        lessgoo(res,ans,n,1,k);
        return res;
    }
    void lessgoo(vector<vector<int>>&res,vector<int>&ans,int n,int start,int k)
    {
        if(k==0)
        {
            res.push_back(ans);
            return;
        }
        for(int i=start;i<=n;i++)
        {
            ans.push_back(i);
            lessgoo(res,ans,n,i+1,k-1);
            ans.pop_back();
        }
    }
};