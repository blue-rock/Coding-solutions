class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isPresent = false;
        unordered_map<string,int>mp;
        for(auto word:wordList)
        {
            if(endWord.compare(word)==0)
            {
                isPresent = true;
            }
            mp[word]++;
        }
        if(isPresent == false)
        {
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int depth = 0;
        while(!q.empty())
        {
            depth++;
            int n = q.size();
            for(int i=0;i<n;i++) //each word will be popped out
            {
                string curr = q.front();
                q.pop();
                int l = curr.length();
                for(int j=0;j<l;j++)
                {
                    string temp = curr;
                    for(char adds='a';adds<='z';adds++)
                    {
                        temp[j] = adds;
                        if(curr.compare(temp)==0)
                        {
                            continue;
                        }
                        if(temp.compare(endWord)==0)
                        {
                           return depth+1; 
                        }
                        if(mp.find(temp)!=mp.end())
                        {
                             cout<<temp<<endl;
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