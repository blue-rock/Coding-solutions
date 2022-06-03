class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj;
        vector<string>ans;
        for(int i=0;i<tickets.size();i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string>s;
        s.push("JFK");
        while(!s.empty())
        {
            string src = s.top();
            if(adj[src].size()==0)
            {
                ans.push_back(src);
                s.pop();
            }
            else
            {
                auto dst = adj[src].begin();
                s.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
//https://www.youtube.com/watch?v=WYqsg5dziaQ