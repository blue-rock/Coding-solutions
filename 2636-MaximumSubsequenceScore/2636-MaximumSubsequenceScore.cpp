// Last updated: 11/2/2025, 10:27:04 PM
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>>maxHeap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;   
        long long ans = INT_MIN;
        long long maxScore = 0;
        long long sum = 0;

        for(int i=0;i<nums1.size();i++){
            maxHeap.push({nums1[i], i});
        }

        while(!maxHeap.empty() && k>0){
            pair<int,int> top = maxHeap.top();
            sum = sum + top.first;
            minHeap.push({nums2[top.second], top.second});
            maxHeap.pop();
            k--;
        }

        int minMul = minHeap.top().first;
        maxScore = sum * minMul;
        ans = max(ans, maxScore);

        while(!maxHeap.empty()){
            pair<int,int> top = minHeap.top();
            sum = sum - nums1[top.second];
            minHeap.pop();

            pair<int,int> maxHeapTop = maxHeap.top();
            sum = sum + maxHeapTop.first;

            minHeap.push({nums2[maxHeapTop.second], maxHeapTop.second});
            maxHeap.pop();
            minMul = minHeap.top().first;
            maxScore = sum*minMul;
            ans = max(ans,maxScore);
        }
        return ans;

    }
};