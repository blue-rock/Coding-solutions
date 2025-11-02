// Last updated: 11/2/2025, 10:31:51 PM
class Solution {
public:
    vector<vector<int>>dp;
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int vsum = 0;
        for(int i=0;i<n;i++){
            vsum = vsum + nums[i];
        }
        if(vsum%2==1){
            return false;
        }
        dp.resize(n+1,vector<int>(vsum/2+1,-1));
        return helper(nums,n,0,vsum/2);
    }

    bool helper(vector<int>&nums,int n,int pos, int sum){
        if(sum==0){
            return true;
        }
        if(pos>=n || sum<0){
            return false;
        }
        if(dp[pos][sum]!=-1){
            return dp[pos][sum];
        }
        return dp[pos][sum] = helper(nums,n,pos+1,sum) || helper(nums,n,pos+1,sum - nums[pos]);
    }
};