// Last updated: 11/10/2025, 10:05:19 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        nums.push_back(0);
        vector<int> stk; 
        int count = 0; 
        for (int i = 0; i < nums.size(); i++){
            
            while (!stk.empty()){
                if (nums[i] > stk.back()){
                    stk.push_back(nums[i]);
                    break; 
                }
                else if (nums[i] < stk.back()){
                    stk.pop_back();
                    count++; 
                }
                else{
                    break; 
                }
            }
            if (stk.empty() && nums[i]!= 0){
                stk.push_back(nums[i]);
            }
        
        }
        return count; 
        
    }
};