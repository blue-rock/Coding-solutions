// Last updated: 11/2/2025, 10:31:35 PM
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>res;
        if(words.size()==0)
        {
            return res;
        }
        set<string>s;
        for(auto x:words)
        {
            s.insert(x);
        }
        for(auto word:words)
        {
            if(isconcat(word,s))
            {
                res.push_back(word);
            }
        }
        return res;
    }
    bool isconcat(string word,set<string>& s)
    {
        int len = word.length();
        for(int i=1;i<len;i++)
        {
            string suff = word.substr(i);   
            if(s.find(word.substr(0,i))!=s.end() && (s.find(suff)!=s.end() || isconcat(suff,s)))
            {
                return true;
            }
        }
        return false;
    }
};