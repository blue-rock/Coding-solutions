// Last updated: 11/2/2025, 10:35:04 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last  = n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=last){
                last = i;
            }
        }
        return last==0;
    }
};