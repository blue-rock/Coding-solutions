// Last updated: 11/2/2025, 10:33:23 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        vector<int>ans;
        while(low<high){
            int sum = numbers[low] + numbers[high];
            if(sum==target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                return ans;
            }
            if(sum>target){
                high--;
            }
            else{
                low++;
            }
        }
        return ans;
    }
};