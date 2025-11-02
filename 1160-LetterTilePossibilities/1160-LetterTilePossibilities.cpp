// Last updated: 11/2/2025, 10:28:57 PM
class Solution {
public:
    set<string>s;
    map<int,int>mp;
    string t;
    int numTilePossibilities(string tiles) {
        helper(tiles);
        return s.size();
    }
    void helper(string& tiles)
    {
        for(int i=0;i<tiles.size();i++)
        {
            if(mp[i]!=1)
            {
                t.push_back(tiles[i]);
                mp[i] = 1;
                s.insert(t);
                helper(tiles);
                mp[i] = 0;
                t.pop_back();
            }
        }
    }
};