// Last updated: 11/2/2025, 10:28:11 PM
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = *max_element(candies.begin(),candies.end());
        vector<bool>result;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies >= max_candies)
            {
                result.push_back(1);
            }
            else
            {
                result.push_back(0);
            }
        }
        return result;
    }
};