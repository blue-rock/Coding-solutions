// Last updated: 11/2/2025, 10:26:58 PM
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=1;
        int n = nums.size();
        vector<int>missingNumbers;
        while(i<n){
            if(nums[i]!=nums[i-1]+1){
                missingNumbers.push_back(nums[i-1]+1);
                nums[i-1] = nums[i-1] + 1;
            }
            else{
                i++;
            }
        }
        return missingNumbers;
    }
};