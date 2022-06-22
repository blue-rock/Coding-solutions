class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n= s.length();
        vector<string>res;
        res.push_back(s);
        for(int i=0;i<n;i++)
        {
            vector<string>temp;
            for(auto str:res)
            {
                string t = str;
                if(t[i]>='a' && t[i]<='z')
                {
                    t[i]= toupper(t[i]);
                    temp.push_back(t);
                }
                else if(t[i]>='A' && t[i]<='Z')
                {
                    t[i]= tolower(t[i]);
                    temp.push_back(t);
                }
            }
            res.insert(res.end(),temp.begin(),temp.end());
        }
        return res;
    }
};