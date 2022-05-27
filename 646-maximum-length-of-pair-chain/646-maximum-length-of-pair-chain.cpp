class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int>nums;
        for(int i=0;i<pairs.size();i++)
        {
            nums.push_back(pairs[i][1]);
        }
        vector<int>dp(nums.size(),1);
        dp[0] = 1;
        int maxv = INT_MIN;
        int ans = 1; //longest seq possible
        for(int i=1;i<nums.size();i++)
        {
            int curr = nums[i];
            maxv = INT_MIN;
            for(int j=0;j<i;j++)
            {
                        if(pairs[j][1] < pairs[i][0])
                        {
                        dp[i] = dp[j] + 1;
                        }
            }
        }
        return dp[nums.size()-1];
    }
};