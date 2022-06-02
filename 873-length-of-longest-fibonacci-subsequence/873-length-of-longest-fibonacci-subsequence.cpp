class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n));
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]] = i;
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int findthis = arr[j] - arr[i];
                if(mp.find(findthis)!=mp.end())
                {
                    int index = mp[findthis];
                    if(index<i)
                    {
                    dp[i][j] = max(dp[i][j],1+dp[index][i]);
                    ans = max(ans,dp[i][j]);
                    }
                }
            }
        }
        if(ans==0)
        {
            return ans;
        }
        return ans+2;
    }
};