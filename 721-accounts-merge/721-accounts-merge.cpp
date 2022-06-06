class Solution {
public:
    vector<int>parent;
    int findpar(int x){
        if(parent[x] == x) return x;
        return parent[x] = findpar(parent[x]);
    }
    void make_union(int x,int y)
    {
        int p1 = findpar(x);
        int p2 = findpar(y);
        if(p1!=p2)
        {
            parent[p1] = p2;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        unordered_map<string,int>emailtoid;
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            for(int j=1;j<accounts[i].size();j++)
            {
                if(emailtoid.find(accounts[i][j])!=emailtoid.end())
                {
                    make_union(emailtoid[accounts[i][j]],i);
                }
                else
                {
                    emailtoid[accounts[i][j]] = parent[i];
                }
            }
        }
        unordered_map<int,vector<string>>newaccs;
        for(auto it:emailtoid)
        {
            newaccs[findpar(it.second)].push_back(it.first);
        }
        vector<vector<string>>ans;
        for(auto it:newaccs)
        {
            auto email = it.second;
            sort(email.begin(),email.end());
            email.insert(email.begin(),accounts[it.first][0]);
            ans.push_back(email);
        }
        return ans;
    }
};