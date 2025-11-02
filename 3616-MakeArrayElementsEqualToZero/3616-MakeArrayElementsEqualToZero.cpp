// Last updated: 11/2/2025, 10:26:56 PM
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0LL);
        int leftSum = 0;
        int totalSol = 0;
        for (int num : nums) {
            int rightSum = total - leftSum - num;
            if (num == 0) {
                if (leftSum == rightSum) {
                    totalSol += 2;
                } else if (leftSum == rightSum - 1 || leftSum - 1 == rightSum) {
                    totalSol++;
                }
            }
            leftSum += num;
        }
        return totalSol;
    }
};