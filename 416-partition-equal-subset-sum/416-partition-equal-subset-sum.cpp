class Solution {
public:
    vector<vector<int>>dp;
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
        }
        if(sum%2==1)
        {
            return false;
        }
        dp.resize(n+1,vector<int>(sum/2+1,-1));
        return helper(nums,n,0,sum/2);
    }
    bool helper(vector<int>&nums,int n,int pos,int sum)
    {
        if(sum==0)
        {
            return true;
        }
        if(pos>=n || sum<0)
        {
            return false;
        }
        if(dp[pos][sum]!=-1)
        {
            return dp[pos][sum];
        }

            return dp[pos][sum] = helper(nums,n,pos+1,sum) ||  helper(nums,n,pos+1,sum - nums[pos]);

    }
};