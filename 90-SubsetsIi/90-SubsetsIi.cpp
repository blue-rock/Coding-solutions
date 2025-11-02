// Last updated: 11/2/2025, 10:34:33 PM
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ret;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        helper(nums,ret,temp,0);
        return ret;
        
    }
    void helper(vector<int>&nums,vector<vector<int>>&ret,vector<int>&temp,int index)
    {
        ret.push_back(temp);
        for(int i=index;i<nums.size();i++)
        {
            if (i> index && i>0 && nums[i] == nums[i-1]) 
            {
                continue;
            }
            temp.push_back(nums[i]);
            helper(nums,ret,temp,i+1);
            temp.pop_back();
        }
    }
};
//1-2-2
//