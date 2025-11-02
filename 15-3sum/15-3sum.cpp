// Last updated: 11/2/2025, 10:35:46 PM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        if(nums.size()<=2){
            return ans;
        }
        int low = 0;
        int high = n-1;

        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low = i+1;
                int high = n-1;
                int target = 0 - nums[i];
                while(low<high){
                    if(nums[low]+nums[high]==target){
                        vector<int>temp = {nums[low], nums[i], nums[high]};
                        ans.push_back(temp);
                        while(low<high && nums[low]==nums[low+1]){
                        low++;
                    }
                    while(low<high && nums[high]==nums[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                    }
                     else if(nums[low] + nums[high] > target){
                        high--;
                    }
                    else{
                        low++;
                    }
                
                }
            }
        }
        return ans;
    }
};