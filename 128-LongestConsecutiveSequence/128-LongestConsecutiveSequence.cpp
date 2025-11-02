// Last updated: 11/2/2025, 10:33:54 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]-1)==st.end()){
                int curr_len = 1;
                int num = nums[i];
                while(st.find(num+1)!=st.end()){
                    num++;
                    curr_len++;
                }
                longest = max(longest, curr_len);
            }
        }
        return longest;
    }
};