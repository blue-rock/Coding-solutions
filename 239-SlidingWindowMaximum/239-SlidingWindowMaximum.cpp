// Last updated: 11/2/2025, 10:32:45 PM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.front()<=i-k) //remove indexes which are not in consideration
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]) //remove numbers which are less than the current number
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(k-i<=1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

/*
[1,3,-1,-3,5,3,6,7]

//0, 
*/