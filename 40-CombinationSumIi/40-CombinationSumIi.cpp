// Last updated: 11/2/2025, 10:35:18 PM
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res ;
        vector<int> temp ;
        sort(candidates.begin() , candidates.end()) ;
        backT(candidates , 0, target , res , temp) ;
        return res ;
    }
    
    
    void backT(vector<int>& candidates ,int start , int target ,vector<vector<int>>& res , vector<int>& temp )
    {
        if (target == 0)
        {
            res.push_back(temp) ;
            return ;
        }
        if (target < 0){return ;}
        
        for (int i=start;i<candidates.size();i++)
        {
            if (i == start or candidates[i] != candidates[i-1])
            {
                temp.push_back(candidates[i]) ;
                backT(candidates,i+1 , target - candidates[i] , res ,temp) ;
                temp.pop_back() ;
            }
        }
    }
               
};