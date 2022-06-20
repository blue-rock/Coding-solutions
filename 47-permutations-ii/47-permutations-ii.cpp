class Solution {
public:
    set<vector<int>>res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permutation(nums,0,nums.size()-1);
        vector<vector<int>>ret;
        for(auto vec:res)
        {
            ret.push_back(vec);
        }
        return ret;
    }
    void permutation(vector<int>& nums,int i,int n)
    {
        if(i==n)
        {
            res.insert(nums);
            return;
        }
        for(int j=i;j<=n;j++)
        {
            swap(nums[i],nums[j]);
            permutation(nums,i+1,n);
            swap(nums[i],nums[j]);
        }
    }
};