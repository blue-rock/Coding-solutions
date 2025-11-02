// Last updated: 11/2/2025, 10:26:55 PM
class Solution {
public:
    bool hasSameDigits(string s) {

        while(s.length()>2){
            string newString = "";
            for(int i=0;i<s.length()-1;i++){
                int num = (int(s[i]) + int(s[i+1]))%10;
                newString+= std::to_string(num);
            }
            s = newString;
        }
        return s[0]==s[1];

    }
};