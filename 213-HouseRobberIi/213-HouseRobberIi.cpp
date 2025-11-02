// Last updated: 11/2/2025, 10:33:00 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        return max(nums[0],max(helper(nums,0),helper(nums,1)));
    }
    int helper(vector<int>&nums,int flag)
    {
        int rob1 = 0;
        int rob2 = 0;
        if(flag==1)
        {
         for(int i=1;i<nums.size();i++)
        { 
            int newrob = max(rob1 + nums[i],rob2);
            rob1 = rob2;
            rob2 = newrob;
        }   
        }
        else
        {
             for(int i=0;i<nums.size()-1;i++)
        { 
            int newrob = max(rob1 + nums[i],rob2);
            rob1 = rob2;
            rob2 = newrob;
        }   
            
        }
        return rob2;
    }
};