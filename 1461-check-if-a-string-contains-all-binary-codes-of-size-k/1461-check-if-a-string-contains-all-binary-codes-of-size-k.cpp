class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int>mp;
        string curr_string = "";
        int n = s.length();
        if(k>n)
        {
            return false;
        }
        for(int i=0;i<k;i++)
        {
            curr_string = curr_string + s[i];
        }
        mp[curr_string]++;
        for(int i=k;i<n;i++)
        {
            curr_string = curr_string.substr(1) + s[i];
            mp[curr_string]++;
        }
        int exp_ans = pow(2,k);
        if(mp.size()!=exp_ans)
        {
            return false;
        }
        return true;
    }
};