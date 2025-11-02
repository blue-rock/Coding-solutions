// Last updated: 11/2/2025, 10:27:22 PM
class Solution {
public:
    bool canBeValid(string s, string locked) {
        // if locked [i]==0 -> change it
        //else  can't change it
        int wc = 0;
        int open = 0;
        int close = 0;
        int n = s.length();
        if(n&1){
            return false;
        }
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                wc++;
            }
            else{
                if(s[i]=='('){
                    open++;
                }
                else{
                    close++;
                }
            }
            if(wc+open<close){
                return false;
            }
        }

        //reverse iterate
        wc = 0;
        close = 0;
        open = 0;

        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'){
                wc++;
            }
            else{
                if(s[i]=='('){
                    open++;
                }
                else{
                    close++;
                }
            }
            if(wc+close<open){
                return false;
            }
        }

        return true;
    }
};