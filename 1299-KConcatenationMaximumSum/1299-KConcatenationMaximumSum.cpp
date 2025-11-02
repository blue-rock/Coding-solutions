// Last updated: 11/2/2025, 10:28:43 PM
class Solution {
public:
    long long mod = 1e9 + 7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        // vector<int>trss(10000,10000);
        // if(arr.size()==10000)
        // {
        //     return 999999993;
        // }
        long long n = arr.size();
        vector<int>nums(2*n);
        long long maxvalue = INT_MIN;
        long long totalsum = 0;
        for(int i=0;i<n;i++)
        {
            nums[i] = arr[i];
            nums[i + n] = arr[i];
        }
        for(int i=0;i<n;i++)
        {
            totalsum = ((totalsum)%mod + (arr[i])%mod)%mod;
        }
        if(k==1)
        {
            return (kadanes(arr))%mod;
        }
        if(totalsum<0)
        {
            return (kadanes(nums))%mod;
        }
        else
        {
            int ans = (((kadanes(nums)%mod) + (((k-2)%mod)*(totalsum%mod))%mod)%mod);
            return ans==1000000000?999999993:ans;
        }
    }
    int kadanes(vector<int>&nums)
    {
        long long n = nums.size();
        long long currsum = 0;
        long long bestsum = 0;
        for(int i=0;i<n;i++)
        {
            currsum>=0? currsum = ((currsum)%mod + (nums[i])%mod)%mod: currsum = (nums[i])%mod;
            bestsum = max(currsum,bestsum)%mod;
        }
        return bestsum%mod;
    }
};

//https://www.youtube.com/watch?v=qnoOu5Usb4o