// Last updated: 11/2/2025, 10:30:51 PM
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto num:arr){
            pq.push({abs(x-num),num});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};