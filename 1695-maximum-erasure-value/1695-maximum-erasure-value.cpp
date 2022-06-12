class Solution {
public:
    int maximumUniqueSubarray(vector<int>nums) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int,int>mp;
        while(start < n && end < n){
            
            if(mp[nums[end]] == 0){
                mp[nums[end]]  = 1;
                sum += nums[end];
                if(ans < sum){
                    ans = sum;
                }
                end++;
            }else{
                sum -= nums[start];
                mp[nums[start]] = 0;       
                start++;
            }
            
        }
        
        return ans;
    }
};