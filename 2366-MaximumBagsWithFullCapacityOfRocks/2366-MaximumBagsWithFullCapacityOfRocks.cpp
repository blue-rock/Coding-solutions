// Last updated: 11/2/2025, 10:27:12 PM
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = rocks.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int d = capacity[i] - rocks[i];
            if(d==0)
            {
                ans++;
            }
            else
            {
            pq.push(d);
            }
        }
        int flag = 0;
        while(!pq.empty() && flag==0)
        {
            if(pq.top()<=additionalRocks)
            {
                additionalRocks = additionalRocks - pq.top();
                pq.pop();
                ans++;
            }
            else
            {
                flag=1;
            }
        }
        return ans;
    }
};