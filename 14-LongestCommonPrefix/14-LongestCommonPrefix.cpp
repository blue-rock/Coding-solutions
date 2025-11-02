// Last updated: 11/2/2025, 10:35:44 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string curr = strs[0];
        int flag = 0;
        string retstr;
        for(int i=0;i<curr.length();i++)
        {
            char now = curr[i];
            for(int j=0;j<strs.size();j++)
            {
                string temp = strs[j];
                if(i>temp.size()-1)
                {
                    
                    flag = 1;
                    break;
                }
                if(temp[i]!=curr[i])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                break;
            }
            else
            {
                retstr = retstr + now;
            }
        }
        return retstr;
    }
};