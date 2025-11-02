// Last updated: 11/2/2025, 10:31:02 PM
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto task:tasks)
        {
            mp[task]++;
        }
        priority_queue<int>pq;
        for(auto x:mp)
        {
            pq.push(x.second);
        }
        int cycles = 0;
        int time = 0;
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i=0;i<n+1;i++)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            for(int i=0;i<temp.size();i++)
            {
                temp[i]--;
                if(temp[i]>0)
                {
                    pq.push(temp[i]);
                }
            }
            cycles += (pq.empty()) ? temp.size() : n+1;
        }
        return cycles;
    }
};