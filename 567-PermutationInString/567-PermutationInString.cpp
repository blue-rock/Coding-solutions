// Last updated: 11/2/2025, 10:31:09 PM
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n>m){
            return false;
        }
        vector<int>v(26,0);
        vector<int>u(26,0);
        for(auto i:s1){
            v[i-'a']++;
        }

        int j = 0;
        while(j<n){
            u[s2[j++]-'a']++;
        }
        if(v==u){
            return true;
        }

        while(j<m){
            u[s2[j]-'a']++;
            u[s2[j-n] - 'a']--;
            if(u==v){
                return true;
            }
            j++;
        }
        return false;
    }
};