// Last updated: 11/2/2025, 10:35:31 PM
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        int found = haystack.find(needle);
        if(found==string::npos)
        {
            return -1;
        }
        return found;
    }
};