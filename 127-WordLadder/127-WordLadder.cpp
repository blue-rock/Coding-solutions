// Last updated: 11/2/2025, 10:33:53 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int nwords = wordList.size();
        unordered_map<string,int>mp;
        for(int i=0;i<nwords;i++)
        {
            mp[wordList[i]]++;
        }
        //endword does not exist
        if(mp.find(endWord)==mp.end())
        {
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty())
        {
            int s= q.size();
            level++;
            for(int i=0;i<s;i++)
            {
                string curr = q.front();
                q.pop();
                int l = curr.length();
                string temp = curr;
                for(int j=0;j<l;j++)//index flip
                {
                    temp = curr;
                    for(char c='a';c<='z';c++)
                    {
                        temp[j] = c;
                        if(temp==endWord)
                        {
                            return level;
                        }
                        if(temp!=curr && mp.find(temp)!=mp.end())
                        {
                            q.push(temp);
                            mp.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};