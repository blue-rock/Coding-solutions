class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp.insert(nums[i]);
        }
        int max_l = 0;
        for(int i=0;i<nums.size();i++)
        {
           int current_num = nums[i];
           int curr_l = 1;
           if(mp.find(current_num-1)== mp.end())
           {
               while(mp.find(current_num+1)!= mp.end())
               {
                   current_num++;
                   curr_l++;
               }
               max_l = max(max_l,curr_l);
           }
        }
        return max_l;
    }
};