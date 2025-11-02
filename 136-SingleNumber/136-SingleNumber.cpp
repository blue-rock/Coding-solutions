// Last updated: 11/2/2025, 10:33:47 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        
        int a = nums[0] ;
        
        for (int i=1;i<nums.size();i++)
        {
            a = a xor nums[i] ;
        }
        return a ;        
    }
};