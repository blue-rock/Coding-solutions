// Last updated: 11/2/2025, 10:29:01 PM
bool cmp(string a,string b)
    {
        if(a.length()==b.length())
        {
            return a<b;
        }
        return a.length()<b.length();
    }
class Solution {
public:
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int>dp;
        sort(words.begin(),words.end(),cmp);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            string word = words[i];
            cout<<word<<endl;
            int curr = 1;
            for(int j=0;j<word.length();j++)
            {
                string pre = word.substr(0,j) + word.substr(j+1);
                if(dp.find(pre)!=dp.end())
                {
                    curr = max(curr,dp[pre]+1);
                }
            }
            dp[word] = curr;
            ans = max(ans,curr);
        }
        return ans;
    }
};