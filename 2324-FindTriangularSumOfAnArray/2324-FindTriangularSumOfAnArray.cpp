// Last updated: 11/2/2025, 10:27:18 PM
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        return findAns(nums);
    }

    //recursion?

    int findAns(vector<int> nums){
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>temp;
        for(int i=0;i<nums.size()-1;i++){
            int val = (nums[i] + nums[i+1])%10;
            temp.push_back(val);
        }
        return findAns(temp);
    }
};