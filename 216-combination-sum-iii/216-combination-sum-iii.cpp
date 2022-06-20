class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;
        combinations(1,k,n,res,temp);
        return res;
    }
    void combinations(int start,int k,int n,vector<vector<int>>&res,vector<int>&temp)
    {
        if(k<0 || n<0)
        {
            return;
        }
        if(k==0 && n==0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=start;i<=9;i++)
        {
            temp.push_back(i);
            combinations(i+1,k-1,n-i,res,temp);
            temp.pop_back();
        }
    }
};