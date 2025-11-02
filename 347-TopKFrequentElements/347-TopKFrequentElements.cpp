// Last updated: 11/2/2025, 10:32:13 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it=mp.begin(); it!=mp.end();it++){
            pq.push({it->second,it->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};