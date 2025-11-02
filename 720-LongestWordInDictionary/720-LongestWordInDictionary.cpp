// Last updated: 11/2/2025, 10:30:35 PM
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        string res = "";
        set<string>s;
        for(auto w:words)
        {
            if(w.length()==1 || s.find(w.substr(0,w.length()-1))!=s.end())
            {
                if(w.length()>res.length())
                {
                    res = w;  
                }
                s.insert(w); 
            }
        }
        return res;
    }
};