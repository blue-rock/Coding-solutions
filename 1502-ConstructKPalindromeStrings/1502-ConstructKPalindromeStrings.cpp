// Last updated: 11/2/2025, 10:28:14 PM
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(k>n){
            return false;
        }
        if(k==n){
            return true;
        }
        vector<int> freq(26,0);
        int oddCount = 0;

        for(auto& chr : s){
            freq[chr - 'a']++;
        }

        for(int i=0; i<26 ; i++){
            if(freq[i]%2==1){
                oddCount++;
            }
        }
        return oddCount <=k;
    }
};