// Last updated: 11/2/2025, 10:32:46 PM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        bool onezero = false;
        bool multiplezero = false;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                totalProduct = totalProduct*nums[i];
            }
            else{
                if(onezero==false){
                    onezero = true;
                }
                else{
                    multiplezero = true;
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(multiplezero==true){
                ans.push_back(0);
            }
            else if(onezero==true){
                if(nums[i]==0){
                    ans.push_back(totalProduct);
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
                ans.push_back(totalProduct/nums[i]);
            }
        }
        return ans;
    }
};