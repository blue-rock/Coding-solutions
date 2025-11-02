// Last updated: 11/2/2025, 10:35:29 PM
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].length();
        unordered_map<string,int>contain;
        for(string w:words)
        {
            contain[w]++;
        }
        vector<int>res;
        for(int j=0;j<len;j++)
        {
            unordered_map<string,int>found;
            int start = j;
            for(int i=j;i<s.size()-len+1;i=i+len)
            {
                string curr = s.substr(i,len);
                if(contain.find(curr)!=contain.end())
                {
                    found[curr]++;
                    while(found[curr]>contain[curr])
                    {
                        found[s.substr(start,len)]--;
                        start = start+len;
                    }
                    int size = (i - start + len)/len;
                    if(size==words.size())
                    {
                        res.push_back(start);
                    }
                }
                else
                {
                    found.clear();
                    start = i + len;
                }
            }
        }
        return res;
    }
};