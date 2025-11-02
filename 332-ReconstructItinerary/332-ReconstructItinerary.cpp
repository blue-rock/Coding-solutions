// Last updated: 11/2/2025, 10:32:19 PM
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>mp;
        for(auto tick:tickets)
        {
            mp[tick[0]].insert(tick[1]);
        }
        vector<string>res;
        dfs(mp,res,"JFK");
        reverse(res.begin(),res.end());
        return res;
    }
    void dfs(unordered_map<string,multiset<string>>&mp,vector<string>&res,string start)
    {
        while(mp[start].size()>0)
        {
            auto next = *mp[start].begin();
            mp[start].erase(mp[start].begin());
            dfs(mp,res,next);
        }
        res.push_back(start);
    }
};