// Last updated: 11/2/2025, 10:35:33 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 0;
        vector<int>temp;
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            while(i<nums.size()-1 && nums[i+1]==nums[i])
            {
                i++;
            }
            
            c++;
        }
        nums = temp;
        return c;
        
    }
};