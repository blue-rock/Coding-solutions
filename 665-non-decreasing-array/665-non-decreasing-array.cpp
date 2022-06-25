class Solution {
public:
bool checkPossibility(vector<int>& nums) {
        int count = 1;
        int minv = INT_MIN;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] <= nums[i + 1]){
                minv = nums[i];
            }else{
                if(nums[i + 1] < minv){
                    nums[i+1] = nums[i];
                }
                count--;
            }
        }
        if(count < 0){
            return false;
        }else{
            return true;
        }
    }
};



