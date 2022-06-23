class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int res;
      unordered_map<int,int> m;
        for(auto i: nums)
        {
            m[i]++;
        }
        for(auto j: m){
            if(j.second<3)
            {
                res=j.first;
            }
        }
      return res;  
    }
};