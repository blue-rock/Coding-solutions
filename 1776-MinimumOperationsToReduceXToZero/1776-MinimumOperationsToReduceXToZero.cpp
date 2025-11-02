// Last updated: 11/2/2025, 10:27:40 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            mp[sum] = i;
        }
        if(x>sum)
        {
            return -1;
        }
        mp[0] = 0;
        int longest = 0;
        sum = sum - x; //find  this
        int val = 0;
        for(int i=0;i<n;i++)
        {
            val = val + nums[i];
            if(mp.find(val-sum)!=mp.end())
            {
                if(val-sum==0)
                {
                    longest = max(longest,i-mp[val-sum]+1);
                }
                else
                {
                    longest = max(longest,i-mp[val-sum]);
                }
            }
        }
        return longest==0?(sum==0?n:-1):n-longest;
    }
};
