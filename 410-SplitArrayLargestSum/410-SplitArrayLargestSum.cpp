// Last updated: 11/2/2025, 10:31:53 PM
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int sum = 0;
        int maxnum = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxnum = max(maxnum,nums[i]);
            sum = sum + nums[i];
        }
        int low = maxnum;
        int high = sum;
        int res = 0;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(cansplit(mid,nums,m))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
    bool cansplit(int mid,vector<int>&nums,int m)
    {
        int sa = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            if(sum>mid)
            {
                sa++;
                sum = nums[i];
            }
        }
        return sa<=m;
    }
    
};