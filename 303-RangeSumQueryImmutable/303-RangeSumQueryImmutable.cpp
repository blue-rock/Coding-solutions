// Last updated: 11/2/2025, 10:32:31 PM
class NumArray {
public:
    vector<int> memo;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            memo.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
        {
            return memo[right];
        }
        return (memo[right] - memo[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */