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