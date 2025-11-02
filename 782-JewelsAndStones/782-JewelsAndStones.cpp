// Last updated: 11/2/2025, 10:30:16 PM
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>mp;
        for(auto st : stones)
        {
            mp[st]++;
        }
        int count = 0;
        for(auto jew:jewels)
        {
            count = count + mp[jew];
        }
        return count;
    }
};