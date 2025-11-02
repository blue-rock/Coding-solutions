// Last updated: 11/2/2025, 10:35:41 PM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        findAns(nums, target, temp, ans, 0, 0);
        return ans;
    }

    void findAns(const vector<int>& nums, long long target,vector<int>& temp,vector<vector<int>>& ans,int start,long long currSum) {

        if (temp.size() == 4) {
            if (currSum == target){
                ans.push_back(temp);
            }
            return;
        }
        if (start >= nums.size()){
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            findAns(nums, target, temp, ans, i + 1, currSum + nums[i]);
            temp.pop_back();
        }
    }
};
