// Last updated: 11/2/2025, 10:29:13 PM
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1)
        {
            return 1;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<trust.size();i++)
        {
                mp[trust[i][0]]--;   
                mp[trust[i][1]]++;
        }
        for(auto x:mp)
        {
            if(x.second==n-1)
            {
                return x.first;
            }
        }
        return -1;
    }
};