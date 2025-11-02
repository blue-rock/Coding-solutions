// Last updated: 11/2/2025, 10:26:59 PM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int val = (nums[i]>=0) ? nums[i] :-1*(nums[i]+1);
            if(nums[val]>=0){
                nums[val] = -1*(nums[val]+1);
            }
            else{
                ans.push_back(val);
            }
        }
        return ans;   
    }
};