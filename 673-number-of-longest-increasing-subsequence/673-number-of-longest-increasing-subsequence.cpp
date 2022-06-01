class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        vector<int>length(n,1);
        vector<int>count(n,1);
        int maxlength = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(length[j]+1>length[i])
                    {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    }
                    else if(length[j]+1==length[i])
                    {
                        length[i] = length[j] + 1;
                        count[i] += count[j];
                    }
                }
            }
            maxlength = max(maxlength,length[i]);
        }
        int result= 0;
        for(int i=0;i<n;i++)
        {
            if(length[i]==maxlength)
            {
                result+=count[i];
            }
        }
        return result;
    }
};