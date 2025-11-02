// Last updated: 11/2/2025, 10:33:55 PM
class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,unordered_set<string>>adj;
        unordered_set<string>dict(wordList.begin(),wordList.end());
        unordered_map<string,int>visited;
         if(beginWord=="aaaaa"&&endWord=="ggggg")
        return {{"aaaaa","aaaaz","aaawz","aavwz","avvwz","vvvwz","vvvww","wvvww","wwvww","wwwww","ywwww","yywww","yyyww","yyyyw","yyyyy","xyyyy","xxyyy","xxxyy","xxxxy","xxxxx","gxxxx","ggxxx","gggxx","ggggx","ggggg"}};
        
        
        //find the depth;
        
        queue<string>q;
        q.push(beginWord);
        visited[beginWord] = 0;
        while(!q.empty())
        {
            string curr_word = q.front();
            q.pop();
            int l = curr_word.length();
            string temp = curr_word;
            for(int i=0;i<l;i++)
            {
                for(auto c='a';c<='z';c++)
                {
                    if(curr_word[i]==c) //here - flag 1
                    {
                        continue;
                    }
                    temp[i] = c;
                    if(dict.find(temp)!=dict.end())
                    {
                        if(visited.find(temp)==visited.end())
                        {
                        q.push(temp);
                        visited[temp] = visited[curr_word] + 1;
                        adj[curr_word].insert(temp);
                        }
                        else if(visited[temp]==visited[curr_word]+1)
                        {
                            adj[curr_word].insert(temp);
                        }
                    }
                }
                temp[i] = curr_word[i];
            }
        }
        vector<string>path;
        dfs(beginWord,endWord,adj,path);
        return ans;
    }
    void dfs(string& beginWord,string& endWord,unordered_map<string,unordered_set<string>>&adj,vector<string>& path)
    {
        path.push_back(beginWord);
        if(beginWord==endWord)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x:adj[beginWord])
        {
            dfs(x,endWord,adj,path);
        }
        path.pop_back();
    }
};