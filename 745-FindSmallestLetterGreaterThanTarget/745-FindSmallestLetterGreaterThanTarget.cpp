// Last updated: 11/2/2025, 10:30:26 PM
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it  = upper_bound(letters.begin(),letters.end(),target);
        if(it - letters.begin()==letters.size())
        {
            return letters[0];
        }
        return letters[it - letters.begin()];
    }
};