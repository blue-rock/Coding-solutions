class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(); 
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int k = (1<<i);
            int one = 0;
            int zero = 0;
            for(auto nom:nums)
            {
                if(nom&k)
                {
                    one++;
                }
                else if((nom&k)==0)
                {
                    zero++;
                }
            }
            if(one==n||zero==n)
            {
                continue;
            }
            else
            {
                ans = ans + one*zero;
            }
        }
        return ans;
    }
};