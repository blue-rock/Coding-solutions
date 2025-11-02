// Last updated: 11/2/2025, 10:26:54 PM
class Solution {
public:
    long long removeZeros(long long n) {
        string numstr = to_string(n);
        string ans;
        for(int i=0;i<numstr.length();i++){
            if(numstr[i]!='0'){
                ans = ans + numstr[i];
            }
        }
        long long int num = std::stoll(ans);
        return num;
    }
};