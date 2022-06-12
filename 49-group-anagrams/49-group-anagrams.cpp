class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto str:strs)
        {
            string copy = str;
            sort(copy.begin(),copy.end());
            mp[copy].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};