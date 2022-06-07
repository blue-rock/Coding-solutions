class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<pair<int,int>>q; //id -- level
        q.push({id,0});
        unordered_map<string,int>mp;
        vector<int>vis(friends.size(),0);
        vis[id] = 1;
        vector<string>ans;
        while(!q.empty())
        {
            auto popval = q.front();
            q.pop();
            if(popval.second==level)
            {
                for(auto x:watchedVideos[popval.first])
                {
                    mp[x]++;
                }
                continue;
            }
            for(auto frns:friends[popval.first])
            {
                if(!vis[frns])
                {
                    q.push({frns,popval.second+1});
                    vis[frns] = 1;
                }
            }
        }
        vector<pair<int,string>>freq;
        for(auto i:mp)
        {
            freq.push_back({i.second,i.first});
        }
        sort(freq.begin(),freq.end());
        for(auto x:freq)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};