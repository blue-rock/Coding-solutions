class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        unordered_map<int,int>mp;
        vector<int>nomba;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==1)
            {
                nomba.push_back(nums[i]);
            }
        }
        
        int n = nomba.size();
        int dp[n];
        sort(nomba.begin(),nomba.end());
        dp[0] = nomba[0]*mp[nomba[0]];
        if(nomba[1]==nomba[0]+1)
        {
            dp[1] = max(dp[0],nomba[1]*mp[nomba[1]]);
        }
        else
        {
            dp[1] = dp[0] + nomba[1]*mp[nomba[1]];
        }
        for(int i=2;i<n;i++)
        {
            if(nomba[i]==nomba[i-1]+1)
            {
            dp[i] = max(dp[i-1],nomba[i]*mp[nomba[i]] + dp[i-2]);
            }
            else
            {
                dp[i] = dp[i-1] + nomba[i]*mp[nomba[i]];
            }
        }
        return dp[n-1];
    }
};