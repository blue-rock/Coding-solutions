// Last updated: 11/2/2025, 10:32:42 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return 0;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']++;
            if(mp[s[i]-'a']==0){
                mp.erase(s[i]-'a');
            }
            mp[t[i]-'a']--;
            if(mp[t[i]-'a']==0){
                mp.erase(t[i]-'a');
            }
        }
        if(mp.size()==0){
            return true;
        }
        return false;
    }
};