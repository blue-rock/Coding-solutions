// Last updated: 11/2/2025, 10:29:29 PM
class Solution {
public:
    vector<int>parent;
    int findpar(int x)
    {
        if(parent[x]==-1)
        {
            return x;
        }
        return parent[x] = findpar(parent[x]);
    }
    void makeunion(int x,int y)
    {
        int p1 = findpar(x);
        int p2 = findpar(y);
        if(p1!=p2)
        {
            parent[p1] = p2;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        parent.resize(100001,-1);
        for(auto n:nums)
        {
            for(int i=2;i<=sqrt(n);i++)
            {
                if(n%i==0)
                {
                    makeunion(n,i);
                    makeunion(n,n/i);
                }
            }
                
        }
        int count = 0;
        unordered_map<int,int>mp;
        for(int x:nums)
        {
            int p = findpar(x);
            count = max(count,1 + mp[p]);
            mp[p]++;
        }
        return count;
    }
};