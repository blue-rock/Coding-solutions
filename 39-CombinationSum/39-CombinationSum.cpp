// Last updated: 11/2/2025, 10:35:19 PM
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        findans(candidates,target,0,temp,ans);
        return ans;
    }

    void findans(vector<int>& candidates,int target, int start,vector<int> temp,vector<vector<int>>& ans){
        if(target<0){
            return;
        }
        if(target==0){
            ans.push_back(temp);
        }
        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            findans(candidates, target - candidates[i],i,temp,ans);
            temp.pop_back();
        }
    }
};