// Last updated: 11/2/2025, 10:31:36 PM
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        int m=nums[nums.size()/2];
        for(auto x:nums){
            ans =  ans + abs(x-m);
        }
        return ans;
    }
};