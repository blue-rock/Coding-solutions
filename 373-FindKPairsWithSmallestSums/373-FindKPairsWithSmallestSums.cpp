// Last updated: 11/2/2025, 10:32:05 PM
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                vector<int>temp{nums1[i],nums2[j]};
                if(pq.size()<k)
                {
                    pq.push({nums1[i] + nums2[j],temp});   
                }
                else if((nums1[i]+nums2[j])<pq.top().first)
                {
                    pq.pop();
                    pq.push({nums1[i] + nums2[j],temp});
                }
                else
                {
                    break;
                }
            }
        }
        vector<vector<int>>res;
        while(!pq.empty())
        {
            auto x = pq.top().second;
            res.push_back(x);
            pq.pop();
        }
        return res;
    }
};