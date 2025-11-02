// Last updated: 11/2/2025, 10:30:43 PM
class Solution {
public:
     int repeatedStringMatch(string A, string B) {
        string s="";
        int count = 0;
        while(s.length()<B.length())
        {
            s+=A;
            count++;
        }
        if(s.find(B)!=string::npos)
            return count;
        s = s + A;
        count++;
        if(s.find(B)!=string::npos)
            return count;
        
        return -1;
        
    }
};

//abcd
//cdabcdab