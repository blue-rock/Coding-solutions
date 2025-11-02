// Last updated: 11/2/2025, 10:35:12 PM
class Solution {
public:
    
    void solve(vector<int>& nums , set<vector<int>>& res ,int index)
    {
        if (index == nums.size())
        {
            res.insert(nums) ;
            return ;
        }
        
        for (int i=index;i<nums.size();i++)
        {
            swap(nums[i] ,nums[index]) ;
            solve(nums,res , index+1) ;
            swap(nums[i] , nums[index]) ;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res ;
        solve(nums,res,0) ;
        vector<vector<int>>ans(res.begin(),res.end());
        return ans ;
    }
};