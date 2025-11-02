// Last updated: 11/2/2025, 10:32:57 PM
class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>t;
        findans(1,k,n,t);
        return ans;
    }
    void findans(int curr,int sije,int target,vector<int>&temp)
    {
        if(target<0 || temp.size()>sije)
        {
            return;
        }
        if(target==0 && temp.size()==sije)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=curr;i<=9;i++)
        {
            temp.push_back(i);
            findans(i+1,sije,target - i,temp);
            temp.pop_back();
        }
    }
};