class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1 || nums.size()==0)
        {
            return nums;
        }
        int n = nums.size();
        vector<int>dp(n,1);
        int maxlen = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && (1+dp[j]>dp[i]))
                {
                    dp[i] = 1 + dp[j];
                    maxlen = max(maxlen,dp[i]);
                }
            }
        }
        vector<int>ans;
        int prev;
        for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==maxlen && (prev%nums[i])==0 || prev ==-1)
            {
                ans.push_back(nums[i]);
                maxlen--;
                prev = nums[i];
            }
        }
        return ans;
    }
};