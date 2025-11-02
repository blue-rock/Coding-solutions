// Last updated: 11/2/2025, 10:35:53 PM
class Solution {
public:
    string convert(string s, int r) {
        if (r == 1)
        {
            return s;
        }
        int rsize = min(r,int(s.length()));
        vector<string>v(rsize,"");
        int dir = -1, idx = 0;
        
        for (int i = 0; i < s.size(); i++) {
            v[idx] += s[i];
            idx += (dir == -1) ? 1 : -1;
            if (idx == 0 || idx == r - 1) 
            {
                dir = -dir;
            }
        }
        
        string res = "";
        for (auto a : v)
        {
            res = res + a ;                     
        }
        
        return res;
    }
};