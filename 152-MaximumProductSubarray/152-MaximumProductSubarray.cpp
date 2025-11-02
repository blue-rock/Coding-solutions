// Last updated: 11/2/2025, 10:33:31 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            res = max(res,nums[i]);
        }
        int currmin = 1;
        int currmax = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                currmin = currmax = 1;
                continue;
            }
            int temp = currmax*nums[i];
            currmax = max(max(temp,nums[i]),currmin*nums[i]);
            currmin = min(min(temp,nums[i]),currmin*nums[i]);
            res = max(res,currmax);
        }
        return res;
    }
};