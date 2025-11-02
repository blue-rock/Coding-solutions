// Last updated: 11/2/2025, 10:33:25 PM
class Solution {
public:
    string fractionToDecimal(int nume, int deno) {
        if(nume==0)
        {
            return "0";
        }
        string ans="";
        if(nume>0 ^ deno>0)
        {
            ans = ans + '-';
        }
        long num = abs(nume);
        long den = abs(deno);
        long r = long(num)%long(den);
        ans = ans + to_string(num/den);
        if(!r)
        {
            return ans;
        }
        unordered_map<int,int>mp;
        ans = ans + ".";
        while(r)
        {
            if(mp.find(r)!=mp.end())
            {
                ans.insert(mp[r], "(");
                ans = ans + ")";
                break;
            }
            mp[r] = ans.length();
            r = r*10;
            ans = ans + to_string(r/den);
            r = r%den;
            
        }
        return ans;
    }
};