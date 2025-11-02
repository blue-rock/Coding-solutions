// Last updated: 11/2/2025, 10:34:46 PM
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128,0);
        int count = 0;
        int res = INT_MAX;
        for(int i=0;i<t.length();i++){
            freq[t[i]]++;
            count++;
        }
        int i = 0;
        int j = 0;
        int start = 0;
        int till = 0;
        while(i<s.length()){
            if(freq[s[i]]>0){
                count--;
                freq[s[i]]--;
                i++;
            }
            else{
                freq[s[i]]--;
                i++;
            }
            while(count==0){
                if(res>i-j){
                    res = i-j;
                    start = j;
                    till = i-j;
                }
                if(freq[s[j]]<0){
                    freq[s[j]]++;
                    j++;
                }
                else{
                    freq[s[j]]++;
                    j++;
                    count++;
                }
            }
        }
        return s.substr(start,till);
    }
};